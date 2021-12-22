/*
Create by Giovani Sant'Ana Pedroso
Tested in ESP32 
Date: 21/Dez/2021
Github: https://github.com/Giovani-Pedroso/Blue-Pill-a-new-Begining/blob/main/6-Libraries/display7segs.h
*/

#include "driver/gpio.h"

#ifndef _DISPLAY7SEGS_H

#define _DISPLAY7SEGS_H

void sevenSegDisplayInit(){
    

    //PB9 as slow output - blue
    gpio_pad_select_gpio(12);
    gpio_set_direction(12, GPIO_MODE_OUTPUT);

    //PB8 as slow output - green
    gpio_pad_select_gpio(13);
    gpio_set_direction(13, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(25);
    gpio_set_direction(25, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(26);
    gpio_set_direction(26, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(27);
    gpio_set_direction(27, GPIO_MODE_OUTPUT);
    
    gpio_pad_select_gpio(32);
    gpio_set_direction(32, GPIO_MODE_OUTPUT);

    gpio_pad_select_gpio(33);
    gpio_set_direction(33, GPIO_MODE_OUTPUT);

    
    
}



void writeCharSevenSegDisplay(unsigned char c){

    //This function are responsible for show the characters 
    //received  by the usart in the display

    //do not expect perfection in the char 
    //afther all it is still a seven seg display
    //so is necessari use a bit of imagination to understand 
    //the letters , some exemples are K=Q, M=K, and the leter W was implossible
    //to show in the display
    
    //this diagram show which segments are connected with which port
    //      -----27-----
    //      |          |
    //      |          |
    //      33         26
    //      |          |
    //      |          |
    //       ----25----
    //      |          |
    //      |          |
    //      32         13 
    //      |          |
    //      |          |
    //       ----12---- 

    // Converter the upper case char in lower case
    if(c >= 'A' && c <='Z') c += 'a' - 'A' ;

    //Check wich char was recived by the usart
    switch (c){

        case '9':
            //turn on or turn off the segments of the display
            //to form the letter or number
            gpio_set_level(25 ,1); 
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;
        
        case '8': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1); 
            break;

        case '7': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case '6': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case '5': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1); 
            break;

        case '4': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case '3': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0); 
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1); 
            break;

        case '2': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case '1': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,0); 
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case '0': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1); 
            break;

        case 'a': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case 'b': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 'c': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case 'd': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case 'e': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case 'f': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case 'g': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case 'h': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case 'i': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 'j': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case 'k':

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1); 
            break;

        case 'l': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0); 
            break;

        case 'm': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0); 
            break;

        case 'n': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 'o': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case 'p': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case 'q': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case 'r': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 's': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

        case 't': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0); 
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 'u': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case 'v': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,0); 
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case 'x':

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case 'y':

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,0);
            break;

        case 'z': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,1);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case '_': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case '-': 

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        case '?': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,1);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,1);
            gpio_set_level(26 ,1);
            gpio_set_level(27,1);
            break;

        case ' ': 

            gpio_set_level(25 ,0);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,0);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,0);
            break;

        default:

            gpio_set_level(25 ,1);
            gpio_set_level(33 ,0);
            gpio_set_level(32 ,0);
            gpio_set_level(12 ,1);
            gpio_set_level(13 ,0);
            gpio_set_level(26 ,0);
            gpio_set_level(27,1);
            break;

    }

}
#endif
