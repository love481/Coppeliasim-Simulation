/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _INVERSEKINEMATICS_H_
#define _INVERSEKINEMATICS_H_
#include"robo_init.h"
class inversekinematics
{  private:
	float motor_omega[4];
	float robot_velocity[3];
   public:
	void set_motorOmegaFromInvKin(void);
	void set_robotVelocity(float,float,float=0);
	float get_motorOmegaFromInvKin(int motor_index) { return motor_omega[motor_index]; }
};
#endif //!_INVERSEKINEMATICS_H_
