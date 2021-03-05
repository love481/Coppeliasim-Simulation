#include"robo_init.h"
//all objects handle
objectHandling body;
objectHandling wheel;
objectHandling motor[4];
objectHandling robotRefHandle;

//initilze required value
float bodyDiameter;
float interWheelDist;
float wheelDiameter;

//initilize all objects and their configurations
static param_config param_config_;
static param param_;
static motor_config motor_config_[4];
Motor Motor_[4];
static encoder_config encoder_config_[4];
encoder encoder_[4];
robo_state robo_state_;
void robo_init()
{
	setAllHandle();
	parameterInitilize();
	motorAllInitilize();
	encoderAllInitilize();
	pidAllInitilize();
}
void setAllHandle()
{
	body.setHandle("Cylinder");
	wheel.setHandle("wheel1");
	motor[0].setHandle("motor1");
	motor[1].setHandle("motor2");
	motor[2].setHandle("motor3");
	motor[3].setHandle("motor4");
	robotRefHandle.setHandle("robot_reference");

}
void parameterInitilize()
{
	param_config_.bodyHandle = &body;
	param_config_.wheelHandle= &wheel;

	param_.setConfig(&param_config_);
	param_.setAllParameters();

	bodyDiameter=param_.get_bodyDiameter();
	wheelDiameter = param_.get_wheelDiameter();
    interWheelDist = param_.get_interWheelDist();

}
void motorAllInitilize()
{
	motor_config_[0].motorHandle = &motor[0];
	motor_config_[0].max_omega = 5;
	Motor_[0].setConfig(&motor_config_[0]);

	motor_config_[1].motorHandle = &motor[1];
	motor_config_[1].max_omega = 5;
	Motor_[1].setConfig(&motor_config_[1]);

	motor_config_[2].motorHandle = &motor[2];
	motor_config_[2].max_omega = 5;
	Motor_[2].setConfig(&motor_config_[2]);

	motor_config_[3].motorHandle = &motor[3];
	motor_config_[3].max_omega = 5;
	Motor_[3].setConfig(&motor_config_[3]);
}
void encoderAllInitilize()
{   //set all handles for all motors
	encoder_config_[0].encHandle= &motor[0];
	encoder_[0].setConfig(&encoder_config_[0]);

	encoder_config_[1].encHandle= &motor[1];
	encoder_[1].setConfig(&encoder_config_[1]);

	encoder_config_[2].encHandle= &motor[2];
	encoder_[2].setConfig(&encoder_config_[2]);

	encoder_config_[3].encHandle= &motor[3];
	encoder_[3].setConfig(&encoder_config_[3]);
	 
	//start measuring specific parameters
	encoder_[0].encoderInitilize();
	encoder_[1].encoderInitilize();
	encoder_[2].encoderInitilize();
	encoder_[3].encoderInitilize();

}
void pidAllInitilize()
{
	Motor_[0].setPIDConstrain(0.5, 10, 0, -5, 5);
	Motor_[1].setPIDConstrain(0.5, 10,0, -5, 5);
	Motor_[2].setPIDConstrain(0.5, 10, 0, -5, 5);
	Motor_[3].setPIDConstrain(0.5, 10, 0, -5, 5);
	robo_state_.setPIDConstrain(0.5, 0, 0, -10, 10);
}