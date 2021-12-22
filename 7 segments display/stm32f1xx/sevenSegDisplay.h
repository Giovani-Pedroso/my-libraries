/*
Create by Giovani Sant'Ana Pedroso
Tested in STM32F103C8 (bluepill)
Date: 21/Dez/2021
Github: https://github.com/Giovani-Pedroso/Blue-Pill-a-new-Begining/blob/main/6-Libraries/display7segs.h
*/

#include "stm32f1xx.h"

#ifndef _DISPLAY7SEGS_H

#define _DISPLAY7SEGS_H

void sevenSegDisplayInit(){
        //Activate the clock for the PortB
    RCC->APB2ENR |=  (RCC_APB2ENR_IOPBEN);

    //PB9 as slow output - blue
    GPIOB->CRH |=  (GPIO_CRH_MODE9_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE9_1|GPIO_CRH_CNF9_0|GPIO_CRH_CNF9_1);

    //PB8 as slow output - green
    GPIOB->CRH |=  (GPIO_CRH_MODE8_0);
    GPIOB->CRH &= ~(GPIO_CRH_MODE8_1|GPIO_CRH_CNF8_0|GPIO_CRH_CNF8_1);
    
    //PB7 as slow output  
    GPIOB->CRL |=   (GPIO_CRL_MODE7_0);
    GPIOB->CRL &=  ~(GPIO_CRL_MODE7_1|GPIO_CRL_CNF7_0|GPIO_CRL_CNF7_1);

    //PB6 as slow output  
    GPIOB->CRL |=  (GPIO_CRL_MODE6_0);
    GPIOB->CRL &=  ~(GPIO_CRL_MODE6_1|GPIO_CRL_CNF6_0|GPIO_CRL_CNF6_1);

    //PB5 as slow output  
    GPIOB->CRL |=  (GPIO_CRL_MODE5_0);
    GPIOB->CRL &= ~(GPIO_CRL_MODE5_1|GPIO_CRL_CNF5_0|GPIO_CRL_CNF5_1);

    //----------------ATENCION------------------
    //The PB3 and PB4 are use for jtap and swo to use them as GPIO is necessari add this lines
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; 
    AFIO->MAPR = AFIO_MAPR_SWJ_CFG_1;


    //PB4 as slow output  
    GPIOB->CRL |=  (GPIO_CRL_MODE4_0);
    GPIOB->CRL &= ~(GPIO_CRL_MODE4_1|GPIO_CRL_CNF4_0|GPIO_CRL_CNF4_1);

    //PB3 as slow output 
    GPIOB->CRL |=  (GPIO_CRL_MODE3_0);
    GPIOB->CRL &= ~(GPIO_CRL_MODE3_1|GPIO_CRL_CNF3_0|GPIO_CRL_CNF3_1);
    
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
    //      -----B3-----
    //      |          |
    //      |          |
    //      B8         B4
    //      |          |
    //      |          |
    //       ----B9----
    //      |          |
    //      |          |
    //      B7         B5
    //      |          |
    //      |          |
    //       ----B6----
   
    // Converter the upper case char in lower case
    if(c >= 'A' && c <='Z') c += 'a' - 'A' ;

    //Check wich char was recived by the usart
    switch (c){

        case '9':
            //turn on or turn off the segments of the display
            //to form the letter or number
            GPIOB->ODR |=  ( GPIO_ODR_ODR9); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR8); 
            GPIOB->ODR &=  ~(GPIO_ODR_ODR7);
            GPIOB->ODR |=  ( GPIO_ODR_ODR6); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR5); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR4); 
            GPIOB->ODR |=  ( GPIO_ODR_ODR3); 
            break;
        
        case '8': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3); 
            break;

        case '7': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case '6': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case '5': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3); 
            break;

        case '4': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case '3': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3); 
            break;

        case '2': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case '1': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR9); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case '0': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3); 
            break;

        case 'a': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'b': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 'c': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'd': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 'e': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'f': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'g': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'h': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 'i': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 'j': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'k':

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3); 
            break;

        case 'l': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3); 
            break;

        case 'm': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3); 
            break;

        case 'n': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 'o': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3);
            break;

        case 'p': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'q': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case 'r': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case 's': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR4); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR3);
            break;

        case 't': 

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR5); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case 'u': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case 'v': 

            GPIOB->ODR  &= ~(GPIO_ODR_ODR9); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case 'x':

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR7); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3); 
            break;

        case 'y':

            GPIOB->ODR  |=  (GPIO_ODR_ODR9); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR8); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR7); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR6); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR5); 
            GPIOB->ODR  |=  (GPIO_ODR_ODR4); 
            GPIOB->ODR  &= ~(GPIO_ODR_ODR3);
            break;

        case 'z': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   |=  (GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case '_': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case '-': 

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        case '?': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   |=  (GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   |=  (GPIO_ODR_ODR5);
            GPIOB->ODR   |=  (GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

        case ' ': 

            GPIOB->ODR   &= ~(GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR3);
            break;

        default:

            GPIOB->ODR   |=  (GPIO_ODR_ODR9);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR8);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR7);
            GPIOB->ODR   |=  (GPIO_ODR_ODR6);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR5);
            GPIOB->ODR   &= ~(GPIO_ODR_ODR4);
            GPIOB->ODR   |=  (GPIO_ODR_ODR3);
            break;

    }
}
#endif
