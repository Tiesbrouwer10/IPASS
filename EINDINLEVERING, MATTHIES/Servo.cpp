#include "Servo.hpp"
#include "hwlib.hpp"

void Servo::turn_to_0(){
    for(unsigned int i=0; i<30;i++){
        hwlib::wait_ms(10);
        pin_place.set(1);
        hwlib::wait_ms(1.5);
        pin_place.set(0);
    }
}

void Servo::turn_to_90(){
    for(unsigned int i=0; i<35;i++){
        hwlib::wait_ms(5);
        pin_place.set(1);
        hwlib::wait_ms(2.5);
        pin_place.set(0);
    }
}

void Servo::turn_to_180(){
    for(unsigned int i=0; i<30;i++){
        hwlib::wait_ms(10);
        pin_place.set(1);
        hwlib::wait_ms(4.5);
        pin_place.set(0);
    }
}

void Servo::full_Servo_Turn(){

    turn_to_0();
    hwlib::wait_ms(1000);
    turn_to_90();
    hwlib::wait_ms(1000);
    turn_to_180();
    hwlib::wait_ms(1000);
}

Servo create_Servo(){
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo0(pin_Servo);
    return servo0;
    
}