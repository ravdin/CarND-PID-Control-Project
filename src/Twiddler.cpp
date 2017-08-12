#include "Twiddler.h"
#include "PID.h"
#include <math.h>
#include <vector>
#include <numeric>

using namespace std;

Twiddler::Twiddler() {
  bestErr = 0;
  currentParam = 0;
  isInitialized = false;
  isIncremement = false;
}

Twiddler::~Twiddler() {}

void Twiddler::init(vector<double> p, vector<double> dp) {
  this->p = p;
  this->dp = dp;
}

void Twiddler::increment() {
  isIncremement = true;
  p[currentParam] += dp[currentParam];
  step = 0;
  totalErr = 0;
}

void Twiddler::decrement() {
  isIncremement = false;
  p[currentParam] -= 2 * dp[currentParam];
  step = 0;
  totalErr = 0;
  iteration_count = 0;
}

void Twiddler::doStep(double cte) {
  step++;
  totalErr += fabs(cte);
}

void Twiddler::reset() {
  if (!isInitialized) {
    isInitialized = true;
  }
  else {
    currentParam = (currentParam + 1) % p.size();
    if (currentParam == 0) {
      iteration_count++;
    }
    increment();
  }
}

bool Twiddler::stepsCompleted() {
  return step >= max_steps;
}

bool Twiddler::isOptimized() {
  return accumulate(dp.begin(), dp.end(), 0.0) <= tolerance || iteration_count > max_iterations;
}

void Twiddler::twiddleParams(PID &pid) {
  if (isInitialized) {
    if (totalErr < bestErr) {
      bestErr = totalErr;
      dp[currentParam] *= 1.1;
      reset();
    }
    else if (isIncremement) {
      decrement();
    }
    else {
      increment();
      dp[currentParam] *= 0.9;
      reset();
    }
    pid.Init(p[0], p[1], p[2]);
  }
  else {
    bestErr = totalErr;
    reset();
    increment();
  }
}
