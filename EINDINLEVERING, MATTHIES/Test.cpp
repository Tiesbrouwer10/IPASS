#include "Test.hpp"
#include "hwlib.hpp"
#include "IR_Sensor.hpp"
#include "Afst_Sensor.hpp"
#include "Servo.hpp"
#include "Game.hpp"
#include <array>

void test_getDist(IR_Sensor &infra0){
    int distance = 0;
    Afst_Sensor afstSensor1 = create_Afst_Sensor();
        while(true){
            distance = afstSensor1.getDist();
            hwlib::wait_ms(200);;
            hwlib::cout<<distance<<hwlib::endl;
        }   
        
}

void test_inSwitch(IR_Sensor &infra0){
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo2(pin_Servo);
    while(true){
        hwlib::wait_us(20);
        inswitch(0 ,servo2);
        hwlib::wait_ms(1000);
        inswitch(1 ,servo2);
        hwlib::wait_ms(1000);
        inswitch(2 ,servo2);
        hwlib::wait_ms(1000);
        inswitch(3 ,servo2);
        hwlib::wait_ms(1000);
        }
}

void test_signal(IR_Sensor &infra0){
    while(true){ 
        hwlib::wait_ms(10);
        if(!infra0.signal()){
            hwlib::cout<<infra0.signal()<< hwlib::endl;
        }
    }
}

void test_Output(IR_Sensor &infra0){
    std::array<uint8_t, 4> code;

    while(true){ 
        hwlib::wait_ms(0.2);
        code = infra0.output();
        if(!infra0.signal()){
            if(code[2] != 0){
                for(unsigned int t=0; t<4; t++){
                        hwlib::cout<<(int)code[t]<<hwlib::endl;
                }
            }

        }
    }
}

void test_buttonPressed(IR_Sensor &infra0){
    std::array<uint8_t, 4> stop;
    stop = infra0.output();
    while(true){ 
        hwlib::wait_ms(0.2);
        stop = infra0.output();
        if(infra0.button_Pressed(stop[2]) >0){
            hwlib::cout<<infra0.button_Pressed(stop[2]) << hwlib::endl;
        }
    }
}


void test_FullServoturn(IR_Sensor &infra0){ 
    auto pin_Servo = hwlib::target::pin_out(hwlib::target::pins::d9);
    Servo servo6(pin_Servo);
    while(true){
        hwlib::wait_us(20);
        servo6.full_Servo_Turn();
        hwlib::wait_ms(1000);
        }
}




void testSwitch( int keuze, IR_Sensor &infra0){
    switch(keuze){
        case 1 : test_getDist(infra0);
        break;
        case 2 : test_inSwitch(infra0);
        break;
        case 3: test_signal(infra0);
        break; 
        case 4: test_Output(infra0);
        break; 
        case 5: test_buttonPressed(infra0);
        break; 
        case 6: test_FullServoturn(infra0);
        break; 
    }
} 



void testFuncties(){
    while(true){
        std::array<uint8_t, 4> keuze;
        IR_Sensor infra0 = create_IR_sensor();
        hwlib::wait_ms(200);
        hwlib::cout<< "Welkom bij het test programma voor de Guardian security robot." <<hwlib::endl;
        hwlib::cout<< "Welk functie zou u willen testen:   " << hwlib::endl;
        hwlib::cout<< "*Afst_Sensor" << hwlib::endl;
        hwlib::cout<< "     1. getDist();" << hwlib::endl;
        hwlib::cout<< "*Game" <<hwlib::endl;
        hwlib::cout<< "     2. inswitch();\n" <<hwlib::endl;
        hwlib::cout<< "*IR_Sensor" <<hwlib::endl;
        hwlib::cout<< "     3. bool signal();" << hwlib::endl;
        hwlib::cout<< "     4. int Output();" <<hwlib::endl;
        hwlib::cout<< "     5. int buttonPressed();\n" <<hwlib::endl;
        hwlib::cout<< "*Servo" <<hwlib::endl;
        hwlib::cout<< "     6. void full_Servo_Turn();" <<hwlib::endl;

        
        keuze = infra0.output();
        while(infra0.signal()){       //waits for the player to press the correct button
            hwlib::wait_us(20);

        }   
            keuze = infra0.output();
            hwlib::wait_ms(20);
        testSwitch(infra0.button_Pressed(keuze[2]), infra0);
        
    }
}


