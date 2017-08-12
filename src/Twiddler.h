#ifndef TWIDDLER_H
#define TWIDDLER_H

#include <vector>
#include "PID.h"

class Twiddler {

    double totalErr;
    double bestErr;
    const double tolerance = 0.1;
    const int max_steps = 1000;
    bool isInitialized;
    bool isIncremement;
    int step;
    int currentParam;
    int iteration_count;
    const int max_iterations = 20;

public:

      std::vector<double> p;
      std::vector<double> dp;

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
};

#endif
