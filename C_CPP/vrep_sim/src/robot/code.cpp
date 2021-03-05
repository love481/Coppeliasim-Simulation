#include"robot_operation.h"
int main(void)
{
	connection::sim_openConnection();
	connection::sim_start();
	robo_init();
	robo_play();
	connection::sim_stop();
	connection::sim_closeConnection();
}