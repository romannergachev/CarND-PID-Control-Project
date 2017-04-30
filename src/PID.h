#ifndef PID_H
#define PID_H

class PID {
public:
  const double MINIMUM_SPEED = 30.0;
  /*
  * Errors
  */
  double pError;
  double iError;
  double dError;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError(double min, double max);
};

#endif /* PID_H */
