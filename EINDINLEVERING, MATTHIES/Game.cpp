#include "Game.hpp"
#include "Servo.hpp"
#include "hwlib.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"



void inswitch( int i, Servo servo0){
    switch(i){
        case 0 : servo0.turn_to_0();
        break;
        case 1 : servo0.turn_to_90();
        break;
        case 2 : servo0.turn_to_180();
        break;
        case 3: servo0.turn_to_90();
        break; 
    }
} 


void intruderFound(hwlib::target::pin_out &seenLed,int distance){
    std::array<uint8_t, 4> code;
    int secret;
    IR_Sensor infra0 = create_IR_sensor();
    hwlib::wait_ms(20);
    seenLed.set(1);
    hwlib::wait_ms(2000);
    seenLed.set(0);
    secret = ((distance %10) + 1); //sets a secret digit, which is randomised by the distance
    hwlib::wait_ms(2000);
    for(int j = 0; j < secret ; j++){           // reveales the secret digit by pulsing the leds
        hwlib::wait_ms(20);
        seenLed.set(1);
        hwlib::wait_ms(500);
        seenLed.set(0);
        hwlib::wait_ms(500);
    }
    hwlib::wait_ms(20);
    code = infra0.output();
    while(infra0.button_Pressed(code[2]) != secret){       //waits for the player to press the correct button
        hwlib::wait_us(20);
        if(!infra0.signal()){
            code = infra0.output();
        }
    }   
    hwlib::wait_ms(200);
    
}




void runGame(){
    namespace target = hwlib::target;
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo0(pin_Servo);
    Afst_Sensor afstSensor0 = create_Afst_Sensor();
    auto seenLed = hwlib::target::pin_out(hwlib::target::pins::d5);
    int distance;


    while(true){
        for(unsigned int i =0; i<4; i++){
            inswitch(i ,servo0);
            hwlib::wait_ms(50);
            for(unsigned int i=0; i<4; i++){
                hwlib::wait_ms(250);
                distance = afstSensor0.getDist();
                if(distance <= 60 && distance >=0){
                    intruderFound(seenLed,distance);
                    hwlib::wait_ms(200);
                    break;
                }
            }
        }
    }
}



