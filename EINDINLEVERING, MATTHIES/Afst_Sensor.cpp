#include "Afst_Sensor.hpp"
#include "hwlib.hpp"


Afst_Sensor::Afst_Sensor(hwlib::target::pin_out &trigger, hwlib::target::pin_in &echo):
    trigger(trigger),
    echo(echo)
{}

 
int Afst_Sensor::getDist(){
    long long nu; 
    long long dan;   
    long long length;
    while(true){   
        hwlib::wait_ms(50);
        trigger.set(0);              //makes sure the signal is low before its send
        hwlib::wait_us(2);
        trigger.set(1);              // sends a clock cylce to the sensor
        hwlib::wait_us(10);
        trigger.set(0);
        hwlib::wait_us(10);
        while(!echo.get()){
            hwlib::wait_us(2);       // waits for a response from the sensor
        }
        if(echo.get()){                 // determines how long the output from the sensor is
            nu = (hwlib::now_us());
            while(echo.get()){
                hwlib::wait_us(0.4);
            }
            dan = (hwlib::now_us());
        }
        length = dan - nu;
        if(length < 0){
            return 0;
        }
        return (int)(dan-nu) /22.1/2;   //converted the obtained output to cm and returns it
    }
}


Afst_Sensor create_Afst_Sensor(){
    auto trigger = hwlib::target::pin_out(hwlib::target::pins::d6);
    auto echo = hwlib::target::pin_in(hwlib::target::pins::d7);
    Afst_Sensor afstSensor0(trigger, echo);
    return afstSensor0;
}


