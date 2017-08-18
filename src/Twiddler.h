#ifndef TWIDDLER_H
#define TWIDDLER_H

#include <vector>
#include "PID.h"

class Twiddler {

    std::vector<double> p;
    std::vector<double> dp;
    std::vector<double> weighted_dp;
    double totalErr;
    double bestErr;
    const double tolerance = 0.1;
    const int max_steps = 1000;
    bool isInitialized;
    bool isIncremement;
    int step;
    int currentParam;
    int iteration_count;
    const int max_iterations = 10;

public:


  Twiddler();

  virtual ~Twiddler();

  void init(std::vector<double> p, std::vector<double> dp);

  void increment();

  void decrement();

  void doStep(double cte);

  void reset();

  bool stepsCompleted();

  bool isOptimized();

  void twiddleParams(PID::PID &pid);

  void outputParams();
};

#endif
