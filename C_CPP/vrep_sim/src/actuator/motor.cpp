#include"motor.h"
void Motor::setOmega(float omega)
{
	if (omega > _motor_config->max_omega)
		omega = _motor_config->max_omega;
	else if (omega < -_motor_config->max_omega)
		omega = -_motor_config->max_omega;
	_motor_config->motorHandle->setMotorVelocity(omega);
	
}
void Motor::setAngle(float Angle)
{
	if (Angle > _motor_config->max_angle)
		Angle = _motor_config->max_angle;
	else if (Angle < -_motor_config->max_angle)
		Angle = -_motor_config->max_angle;
	_motor_config->motorHandle->setMotorAngle(Angle);
}