# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

--

## Rubric Discussion Points

This projects implements a PID controller.  A PID controller continuously calculates the difference between a desired setpoint and a measured process variable, and applies a correction as follows:

* P: Proportional correction based on present values.  For example, if the error is large, then the control output will also be large.  This control has a tendency to overshoot.

* I: The integral component accounts for past values and accumulates over time.  This counteracts systemic bias that may allow errors to accumulate over time.

* D: The derivative component aims to reduce the rate of change of the errors to zero.  This has a dampening effect on oscillation as the car adjusts to the center line.

Source: [wikipedia](https://en.wikipedia.org/wiki/PID_controller)

## Twiddler

I introduced a class `Twiddler` to the project to help fine tune the parameters.  The main idea was to allow the simulator to repeatedly run for a set number of steps, change the parameters, and keep the parameters with the best performance.  The best performance was measured by a run with the lowest error.

In a nutshell, the algorithm is to fiddle with the parameter by a small amount (set in the `dp` vector).  If the run has a lower error measurement than the best run so far, then we'll keep that parameter and slightly increase `dp` (allowing the search to be a bit wider with the next run).  If the current run is not an improvement over the best known run, reduce `dp`.  When `dp` has reduced enough, end the search.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)
