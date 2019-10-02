#include "IR_Sensor.hpp"
#include "hwlib.hpp"
#include <array>
//1 = 48;
//2 = 24;
//3 = 122;
//4 = 16;
//5 = 65;
//6 = 90;
//7 = 66;
//8 = 74;
//9 = 82;
//10 = 0 = 104;
//11 = ch- = 162;
//12 = ch = 98;
//13 = ch+ = 226;
//14 = backward = 34;
//15 = forward = 2;
//16 =  play/pause = 194;
//17 = vol- = 224;
//18 = vol+ = 168;
//19 = EQ = 144;
//20 = 100+ = 152;
//21 = 200+ = 176;



IR_Sensor::IR_Sensor(hwlib::target::pin_in &IR_sen):
    IR_sen(IR_sen)
{}

bool IR_Sensor::signal(){
    return(IR_sen.get());
}


int IR_Sensor::button_Pressed(uint8_t code){
    while(true){
        if(code == 104){
            return 10;
        }
        if(code == 48){
            return 1;
        }
        if(code == 24){
            return 2;
        }
        if(code == 122){
            return 3;
        }
        if(code == 16){
            return 4;
        }
        if(code == 56){
            return 5;
        }
        if(code == 90){
            return 6;
        }
        if(code == 66){
            return 7;
        }
        if(code == 74){
            return 8;
        }
        if(code == 82){
            return 9;
        }
        if(code == 162){
            return 11;
        }
        if(code == 98){
            return 12;
        }
        if(code == 226){
            return 13;
        }
        if(code == 34){
            return 14;
        }
        if(code == 2){
            return 15;
        }
        if(code == 194){
            return 16;
        }
        if(code == 224){
            return 17;
        }
        if(code == 168){
            return 18;
        }
        if(code == 144){
            return 19;
        }
        if(code == 152){
            return 20;
        }
        if(code == 176){
            return 21;
        }
        else{
            return 0;
        
    }
    }
}

std::array<uint8_t ,4> IR_Sensor::output(){
    long long nu;
    long long dan;
    long long begin0;
    std::array<uint8_t, 4> code = {0,0,0,0};
    
    nu = (hwlib::now_us());
    while(!IR_sen.get()){
        hwlib::wait_us(2);
    }
    dan = (hwlib::now_us());            
    begin0 = dan-nu;
    if(begin0 > 8000 && begin0 <10000){
        nu = hwlib::now_us();
        while(IR_sen.get()){
        hwlib::wait_us(2);
        }
        dan = (hwlib::now_us());
        if((dan-nu)>4000){
            for(unsigned int i=0; i<4; i++){
                for(unsigned int j=0; j<8; j++){
                    
                    while(!IR_sen.get()){
                        hwlib::wait_us(2);
                    }
                    nu = hwlib::now_us();
                    while(IR_sen.get()){
                        hwlib::wait_us(2);
                    }
                    dan = hwlib::now_us();
                    if(dan-nu < 1000){
                        code[i] = (code[i]<<1);
                        code[i] = (code[i]|0);
                    }
                    if(dan-nu > 1000){
                        code[i] = (code[i]<<1);
                        code[i] = (code[i]|1);                        
                    }
                }
            }
        }
    }
    
    return code;
}





IR_Sensor create_IR_sensor(){
    auto IR = hwlib::target::pin_in(hwlib::target::pins::d2);
    IR_Sensor infra0(IR);
    return infra0;
}
