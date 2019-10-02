#ifndef IR_SENSOR_HPP
#define IR_SENSOR_HPP
#include "hwlib.hpp"
#include <array>
///@file

class IR_Sensor{
private:
    hwlib::target::pin_in IR_sen;
    
public:
    /// \brief
    /// IR_Sensor constructor
    /// \details
    /// This function functions as the constructor for when an IR_Sensor object is created.
    IR_Sensor(hwlib::target::pin_in &IR_sen);
    
    /// \brief
    /// IR_Sensor Signal detector
    /// \details
    /// This function will return a 1 if the IR_Sensor has no input signal, and a 0 if the IR_Sensor does have an input signal.
    /// The Infrared sensor has an active low output
    bool signal();
    
    
    /// \brief
    /// IR_Sensor output
    /// \details
    /// This function follows the standard NEC Infrared Transmission Protocol.
    /// It will return an array<uint8, 4> containing the value of the 32 bits send after the first 9ms activation bit.
    /// These 32 bits include:
    /// The 8-bit adress for the receiving device
    /// The 8-bit logical inverse of the address
    /// The 8-bit command
    /// The 8-bit logical inverse of the command
    /// A pulse burst to signal the end of the transmission
    std::array<uint8_t ,4> output();
    
    /// \brief
    /// Button press function (CR2025)
    /// \details
    /// This function is only to be used for the CR2025.
    /// This function asks for an uint32_t parameter, which can be obtained from the output(); function. 
    /// it will use this to determine which button was pressed on the remote.
    ///The function will determine the button according to the folowing 32 bites:
    ///1 = 16724175;
    ///2 = 16718055;
    ///3 = 16743045;
    ///4 = 16716015;
    ///5 = 16726215;
    ///6 = 16734885;
    ///7 = 16728765;
    ///8 = 16730805;
    ///9 = 16732845;
    ///10 = 0 = 16738455;
    ///11 = ch- = 16753245;
    ///12 = ch = 16736925;
    ///13 = ch+ = 16769565;
    ///14 = backward = 16720605;
    ///15 = forward = 16712445;
    ///16 =  play/pause = 16761405;
    ///17 = vol- = 16769055;
    ///18 = vol+ = 16754775;
    ///19 = EQ = 16748655;
    ///20 = 100+ = 16750695;
    ///21 = 200+ = 16756815; 
    int button_Pressed(uint8_t code);

};
    /// \brief
    /// Create IR_Sensor Object
    /// \details
    /// When called, this function will create an IR_Sensor with the data pin in D2.
IR_Sensor create_IR_sensor();

#endif // IR_SENSOR_HPP
