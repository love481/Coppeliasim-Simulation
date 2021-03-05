function [x,y,theta] = omni_getPose(connection)
%OMNI_GETPOSE Summary of this function goes here
        [result,data]=connection.vrep.simxGetStringSignal(connection.clientID,strcat('omni_pose',num2str(connection.robotNb)),connection.vrep.simx_opmode_buffer);
        if (result~=connection.vrep.simx_error_noerror)
            err = MException('VREP:RemoteApiError', ...
                            'simxGetStringSignal failed');
            throw(err);
        end
        if(isempty(data))
            err = MException('VREP:RemoteApiError', ...
                'Empty data returned');
            throw(err);
        end
        pose=connection.vrep.simxUnpackFloats(data);
	x=pose(1);
	y=pose(2);
	theta=pose(3); % rad
end

