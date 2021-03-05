#include"inversekinematics.h"
extern float wheelDiameter;
extern Motor motor_[4];
/*static float inverseCouplingMatrix[4][3] =   
{   
	{-0.70711, 0.70711, 0.5  },
	{ -0.70711,-0.70711, 0.5 },
	{ 0.70711, -0.70711, 0.5 },
	{ 0.70711, 0.70711, 0.5 },
};*/
//based on direction of motion of robot
const float inverseCouplingMatrix[4][3] =
{
	{0.70711, -0.70711, 0.5 },
	{ 0.70711,0.70711, 0.5 },
	{ -0.70711, 0.70711, 0.5},
	{ -0.70711, -0.70711, 0.5 },
};
void inversekinematics::set_motorOmegaFromInvKin()
{
	float vel_x_y_theta[3] = { robot_velocity[0],robot_velocity[1] ,robot_velocity[2] };
	for (int i = 0; i < 4; i++)
	{
		motor_omega[i] = 0;
		for (int j = 0; j < 3; j++)
			motor_omega[i] += inverseCouplingMatrix[i][j] * vel_x_y_theta[j];
		motor_omega[i] = (motor_omega[i]*2) / wheelDiameter;

	}
}
void inversekinematics::set_robotVelocity(float vel, float direction, float omega)
{
	robot_velocity[0] = vel * cos((PI/180) *direction);
	robot_velocity[1] = vel* sin((PI / 180) * direction);
	robot_velocity[2] = omega;
	set_motorOmegaFromInvKin();
}