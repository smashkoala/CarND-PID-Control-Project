# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program - Writeup and instructions

## Writeup (Rubric points)

1. Your code should compile  
Yes. See [this](https://github.com/smashkoala/CarND-PID-Control-Project) repository in GitHub.

2. The PID procedure follows what was taught in the lessons.  
It is implemented as taught in the lesson.
The PID controller is also implemented for throttle control too.

3. Describe the effect each of the P, I, D components had in your implementation.   
[This](https://github.com/smashkoala/CarND-PID-Control-Project/blob/master/OK_param.mov) is the video of successful run with 40 mph. The parameters are set P = 0.3, I = 0.000001 and D = 3.0.  
The P component influences on the magnitude of the turning angle. If it is higher, the steering angle gets steeper.  See [this video](https://github.com/smashkoala/CarND-PID-Control-Project/blob/master/P_param.mov). Only P is changed to P = 0.8. The rest of the parameters stay the same as successful run vide.  
The I component compensates for bias. In this project, it compensates for steering angle bias. If it is large, it oversteers from the begging of the drive. Therefor,it needs to be a very small number. See [this video](https://github.com/smashkoala/CarND-PID-Control-Project/blob/master/I_param.mov). Only I is changed to I = 0.1.  
The D component influences on the oscillation of the car. If it is higher, the oscillation of the vehicle gets less. See [this video](https://github.com/smashkoala/CarND-PID-Control-Project/blob/master/D_param.mov). Only D is changed to 0.1.

4. Describe how the final hyperparameters were chosen.
First, I tried to run the vehicle by setting both I and D = 0. For this, I set
the target speed of vehicle less than 20 miles/hour, since if the speed is higher,the vehicle oscillate more often. Once, the vehicle can finish one lap of the course, I increased the speed up to 40 miles/hour. The vehicle oscillates more often with this speed. In order to reduce the oscillations, I chose the D component, which is 3.0 used in the lesson, and kept the I component still 0. I changed the D several times to set it between
2.0 and 4.0, but in the end 3.0 was the best fit by looking at the behavior of
vehicle.
Lastly, I set the I component to 0.1, and I realized that with this setting,
the vehicle does not run straight from the begging. Then I set it to very small
value, which is 0.000001. It seems that this compensate some steering biases.

5. The vehicle must successfully drive a lap around the track.  
Yes, the vehicle drive successfully drive a lap with the speed of 40 miles/hour.

---

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

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).
