#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
  Init(0.4, 0.2, 0.1);
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  this->totalError = 0;
}

void PID::UpdateError(double cte) {
  totalError += cte;
  previousCte = cte;
}

double PID::TotalError() {
  return totalError;
}

