#ifndef GAME_HPP
#define GAME_HPP
#include "servo.hpp"
#include "IR_Sensor.hpp"
///@file

/// \brief
/// Servo movement switch
/// \details
/// This function has a range of 4 cases.
/// The switch will run a certain function once a case is called for.
/// The functions in this case all allow for a smooth movement for the security robots head
void inswitch( int i, Servo servo0);

/// \brief
/// Intruder Programm
/// \details
/// This function will run an intruder program, which revolves around the function calculating a random digit.
/// afterwhich the function will reveal the code throught leds pulses.
/// When the found user presses the correct button on the remote, the program will continue its initial search for a person
void intruderFound(hwlib::target::pin_out &seenLed, int distance);


/// \brief
/// Game function
/// \details
/// This function uses all the ouputs from the included libraries to create the brain for the security robot.
/// The robot will have a continuous cycle of headturns and scans untill someone is found within a distance of 60 meters.
/// When said person is found, the function "intruderFound()" will trigger.
void runGame();

#endif // GAME_HPP
