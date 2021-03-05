/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/
#pragma once
#ifndef _ROBO_INIT_H_
#define _ROBO_INIT_H_
#include"motor.h"
#include"encoder.h"
#include"param.h"
#include"inversekinematics.h"
#include"robot_state.h"
//initilze all functions for their respective objects
void setAllHandle(void);
void parameterInitilize();
void motorAllInitilize(void);
void encoderAllInitilize(void);
void pidAllInitilize(void);
void robo_init(void);
#endif //!_ROBO_INIT_H_

