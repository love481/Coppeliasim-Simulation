/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _CONNECTION_H_
#define _CONNECTION_H_
#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;
//Name mangling
extern "C" {
#include"extApi.h"
#include"extApiPlatform.h"
}
namespace connection {
    extern int ClientId;
	extern int Port;
    void sim_openConnection();
    void sim_start();
    void sim_triggerStep();
    void sim_setStep();
    void sim_pause();
    void sim_stop();
    void sim_closeConnection();
}
#endif // !_CONNECTION_H_
