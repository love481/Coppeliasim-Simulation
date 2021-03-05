#include "robot_operation.h"
extern encoder encoder_[4];
extern Motor Motor_[4];
extern robo_state robo_state_;
extern objectHandling robotRefHandle;
inversekinematics inversekinematics_;
void robo_play()
{
	uint32_t prevTime = extApi_getTimeInMs();
	uint32_t currTime = extApi_getTimeInMs();
	while (1)
	{
		robotRefHandle.getRobotPose(robo_state_.x, robo_state_.y, robo_state_.theta);
		getRobotVelocity();
		if ((extApi_getTimeInMs() - currTime) > 10)
		{
			inversekinematics_.set_robotVelocity(robo_state_.velocity, robo_state_.direction, robo_state_.omega);
			uint32_t currTime = extApi_getTimeInMs();
	
			motor_actuate();
		}
		if (extApi_getTimeInMs() - prevTime >= 30000)
			break;
	}
	for (int i = 0; i < 4; i++)
		Motor_[i].setOmega(0);
}
void motor_actuate()
{
	for (int i = 0; i < 4; i++)
	{
		float tunedOmega = Motor_[i].computeOmega(inversekinematics_.get_motorOmegaFromInvKin(i), encoder_[i].getOmega());
		Motor_[i].setOmega(tunedOmega);
	}
}
void getRobotVelocity()
{
	float rho = sqrt(pow(2 - robo_state_.x, 2) + pow(3 - robo_state_.y, 2));
	float lambda = atan2f( 3- robo_state_.y, 2 - robo_state_.x);
	float alpha = normalizeAngle(lambda - robo_state_.theta);
	float beta = normalizeAngle(-alpha - robo_state_.theta);
	//cout << robo_state_.theta<<endl;
	robo_state_.velocity = 0.5*rho;
	robo_state_.direction = alpha*(180/PI);
	robo_state_.omega = 0;
	//robo_state_.omega =robo_state_.computeOmegaBasedOnPose( 90*(PI/180), robo_state_.theta);

}