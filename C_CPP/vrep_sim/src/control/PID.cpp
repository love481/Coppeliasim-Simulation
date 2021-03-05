#include"PID.h"
float PID:: Compute(float Setpoint,float Input)
{
    if (!inAuto) return 0;
    unsigned long now= extApi_getTimeInMs();
    unsigned long timeChange = (now - lastTime);
    if (timeChange >= SampleTime)
    {   
        /*Compute all the working error variables*/
        currInput = Input;
        float error = Setpoint - Input;
        ITerm += (ki * error);
        float dInput = (Input - lastInput);
        if (!pOnE) ITerm -= kp * dInput;
        if (ITerm > outMax) ITerm = outMax;
        else if (ITerm < outMin) ITerm = outMin;

        /*Compute P-Term*/
        if (pOnE) Output = kp * error;
        else Output = 0;

        /*Compute Rest of PID Output*/
        Output += ITerm - kd * dInput;
        if (Output > outMax) Output = outMax;
        else if (Output < outMin) Output = outMin;

        /*Remember some variables for next time*/
        lastInput = Input;
        lastTime = now;
    }
    return Output;
}

void PID:: SetTunings(float Kp, float Ki, float Kd,int pOn)
{
    if (Kp < 0 || Ki < 0 || Kd < 0) return;

    pOnE = (pOn == P_ON_E);

    float SampleTimeInSec = (float)SampleTime / 1000;
    kp = Kp;
    ki = Ki * SampleTimeInSec;
    kd = Kd / SampleTimeInSec;

    if (controllerDirection == REVERSE)
    {
        kp = (0 - kp);
        ki = (0 - ki);
        kd = (0 - kd);
    }
}

void PID:: SetSampleTime(int NewSampleTime)
{
    if (NewSampleTime > 0)
    {
        float ratio = (float)NewSampleTime / (float)SampleTime;
        ki *= ratio;
        kd /= ratio;
        SampleTime = (int)NewSampleTime;
    }
}

void PID:: SetOutputLimits(float Min, float Max)
{
    if (Min > Max) return;
    outMin = Min;
    outMax = Max;
}

void PID:: SetMode(int Mode)
{
    bool newAuto = (Mode == AUTOMATIC);
    if (newAuto == !inAuto)
    {  /*we just went from manual to auto*/
        Initialize();
    }
    inAuto = newAuto;
}

void PID:: Initialize()
{
    lastInput = currInput;
    ITerm = Output;
    if (ITerm > outMax) ITerm = outMax;
    else if (ITerm < outMin) ITerm = outMin;
}

void PID:: SetControllerDirection(int Direction)
{
    controllerDirection = Direction;
}