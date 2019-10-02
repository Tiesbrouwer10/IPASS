#include "hwlib.hpp"
#include "Servo.hpp"
#include "Game.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"
#include "Test.hpp"
/// @file
/// \brief
/// Main codefile
/// \details
/// first, this file killes the watchdog, after which it will run the main game file for this embedded program.
int main(){
    WDT->WDT_MR = WDT_MR_WDDIS;
    //servo op d9
    //afstand sensor op trigger: d6 en echo: d7
    //IR sensor op d2
    //leds op d5
    runGame();
    //testFuncties();
    

}


    
    
    
    
    
    
    
    
    
    
    
    
 
    
 
 
    