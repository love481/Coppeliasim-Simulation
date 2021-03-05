%% V-REP Simulation Exercise 3: Kinematic Control
% Tests the implemented control algorithm within a V-Rep simulation.

% In order to run the simulation:
%   - Start V-Rep
%   - Load the scene matlab/common/vrep/mooc_exercise.ttt
%   - Hit the run button
%   - Start this script

%% Parameters setup

%% Initialize connection with V-Rep
startup;
connection = simulation_setup();
connection = simulation_openConnection(connection, 0);
simulation_start(connection);
[bodyDiameter ,wheelDiameter ,interWheelDist] = omni_init(connection);
%% CONTROL LOOP.
EndCond = 0;
for i=0:20
if (i<10)
omni_setWheelSpeeds(connection,pi,pi,-pi,-pi);
else 
omni_setWheelSpeeds(connection,-pi,-pi,+pi,+pi);   
end
[m1,m2,m3,m4] = omni_getWheelSpeeds(connection);
[m1Enc,m2Enc,m3Enc,m4Enc] = omni_getEncoders(connection);
[x, y ,theta] = omni_getPose(connection);
 fprintf('m1 m2 m3 m4 is %2.2f & %2.2f & %2.2f & %2.2f\n',m1,m2,m3,m4);
 fprintf('m1E m2E m3E m4E is %2.2f & %2.2f & %2.2f & %2.2f\n',m1Enc,m2Enc,m3Enc,m4Enc);
 fprintf('(x,y,theta)=(%2.2f ,%2.2f , %2.2f)\n',x,y,theta);
pause(1);
end
%% Bring omni to standstill
simulation_stop(connection);
simulation_closeConnection(connection);

% msgbox('Simulation ended');
