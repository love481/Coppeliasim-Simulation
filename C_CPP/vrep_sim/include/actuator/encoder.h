/*******************
**Author:Love Panta
**Created:2020/10/11/
******************/

#pragma once
#ifndef _ENCODER_H_
#define  _ENCODER_H_
#include"objectHandling.h"
#include "defines.h"
struct encoder_config {
	objectHandling* encHandle;
};
class encoder {
private:
	float omega, angle, prevAngle;
	encoder_config* _encoder;
public:
	encoder() :omega(0), angle(0),prevAngle(0),_encoder(0){}
	~encoder(){}
	void setConfig(encoder_config* encoder_) { _encoder = encoder_; }
	void encoderInitilize(void);
	float getOmega(void);
	float getAngle(void);

};
#endif //! _ENCODER_H_