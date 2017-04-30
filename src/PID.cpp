#include "PID.h"
#include <iostream>

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

double PID::TotalError(double min, double max) {
  double totalError = -(Kp * pError + Kd * dError + Ki * iError);
  if (totalError < min) {
    std::cout << "Speed Value Fixed! < " << totalError << std::endl;
    totalError = min;
  } else if (totalError > max) {
    std::cout << "Speed Value Fixed! > " << totalError << std::endl;
    totalError = max;
  }

  return totalError;
}
