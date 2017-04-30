#include "PID.h"

/*
* PID Controller class
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  iError += cte;
  dError = cte - pError;
  pError = cte;
}

double PID::TotalError() {
  return -(Kp * pError + Kd * dError + Ki * iError);
}
