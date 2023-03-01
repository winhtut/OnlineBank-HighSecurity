//
// Created by National Cyber City on 3/1/2023.
//

#ifndef ONLINEBANKPJ_USER_SETTING_H
#define ONLINEBANKPJ_USER_SETTING_H

#include "stdio.h"
#include "onlineBank.h"

//global variable
int phone_found=-1;


// function declaration
void transfer_money();
void phone_number_finding(unsigned int to_find_ph);


void transfer_money(){

    unsigned int receiver_phone=0;
    phone_found=-1;
    while (phone_found==-1) {
        printf("Enter receiver phone number>>:");
        scanf("%u", &receiver_phone);

        if(phone_found==-1){
            printf("This is phone number is Not found in our bank\n");
        }

    }

    printf(" Enter amount to send for %s :  %s",db[phone_found].name,db[phone_found].email);





}

void phone_number_finding(unsigned int to_find_ph){

    for(int i=0; i<G_index; i++){

        if(to_find_ph == db[i].phoneNumber){
            phone_found=i;
            break;
        }
    }



}

#endif //ONLINEBANKPJ_USER_SETTING_H
