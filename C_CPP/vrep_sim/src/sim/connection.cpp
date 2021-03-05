#include"connection.h"
int connection::Port = 19997;
int connection::ClientId = -1;
//start the remote api connection
void connection::sim_openConnection()
{
	cout << "Starting remote Api!!" << endl;
	try {
		ClientId = simxStart("127.0.0.1",Port, 1, 1, 5000, 5);
		if (ClientId == -1) {
			std::cout << "Failed to connect to Remote API server" << endl;
			sim_stop();
			sim_closeConnection();
			exit(0);
		}
		else {
			std::cout << "Connected to V-REP with ClientID: " << ClientId << endl;
		}
	    }
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
//start vrep simulation
void connection::sim_start()
{
simxStartSimulation(ClientId, simx_opmode_oneshot_wait);
 //make sure the scripts on the V - REP side had the time to execute at least once
//(e.g.to set the signals).So we simply send 3 dummy requests(effectively waiting a bit here) :
simxGetFloatSignal(ClientId, "",NULL, simx_opmode_oneshot_wait);
simxGetFloatSignal(ClientId, "",NULL, simx_opmode_oneshot_wait);
simxGetFloatSignal(ClientId, "",NULL, simx_opmode_oneshot_wait);
}
//stop vrep  simulation
void connection::sim_stop()
{
	simxStopSimulation(ClientId, simx_opmode_oneshot_wait);
}
// close the remote Api connection
void connection::sim_closeConnection()
{
simxFinish(ClientId);
}
//pause the vrep simulation
void connection::sim_pause()
{
simxPauseSimulation(ClientId, simx_opmode_oneshot_wait);
}
//	Sends a synchronization trigger signal to the server
void connection::sim_triggerStep()
{
simxSynchronousTrigger(ClientId);
}
//Enables or disables the synchronous operation mode for the remote API server
void connection::sim_setStep()
{
	simxSynchronous(ClientId, true);
}