#ifndef SERVO_HPP
#define SERVO_HPP

#include "hwlib.hpp"

class Servo{
private:
    hwlib::target::pin_out & pin_place;
public:

    /// \brief
    /// Servo constructor
    /// \details
    /// This function functions as the contructor for when a Servo object is created..
    Servo(hwlib::target::pin_out &pin_place):
       pin_place(pin_place)
       {}
       
    /// \brief
    /// Turn to position 0
    /// \details
    /// This function moves the position of the servo to its 0 degrees position. 
    /// This functions works by giving small pulses with a certain length per pulse
    void turn_to_0();
    
    /// \brief
    /// Turn to position 90
    /// \details
    /// This function moves the position of the servo to its 90 degrees position.  
    /// This functions works by giving small pulses with a certain length per pulse

    void turn_to_90();
    
    /// \brief
    /// Turn to position 180
    /// \details
    /// This function moves the position of the servo to its 180 degrees position.  
    /// This functions works by giving small pulses with a certain length per pulse    
    void turn_to_180();
    
    /// \brief
    /// Turn servo full
    /// \details
    /// This function moves the position of the servo to its 0 degrees position, afterwhich it will go to its 90 degrees position, followed bij the 180 degrees position.  
    void full_Servo_Turn();
};


/// \brief
/// Create Servo object
/// \details
/// When called, this function will create a Servo Object with the clock pulse on d9.
Servo create_Servo();
    


#endif