//
// Created by National Cyber City on 2/18/2023.
//

#ifndef ONLINEBANKPJ_ONLINEBANK_H
#define ONLINEBANKPJ_ONLINEBANK_H
#include "stdio.h"
#include "stdlib.h"
#define USERSIZE 1000
#define DATA_COUNT 20

//Global Variable

int G_index=0; // for user counting
int email_found = -1; // for checking email exist
int space_array[DATA_COUNT];

// End of Global Variables

//function declaration
int check_input(char input[2]);
void rEgister();
void login();
int char_counting(char my_char[50]);
void loading_from_file();
void main_menu();
void space_counter();
void printing_all_data();

struct trans{
    char note[200];
};
struct info{

    unsigned int id;
    char name[50];
    char nrc[20];
    char email[50];
    char password[50];
    unsigned int phoneNumber;
    char encryption_key[50];
    char recovery_key[50];
    char account_status[10];
    int account_type; //1 personal ,2 business , 3 othersss......
    int account_level;
    int minimum_opening_deposit;
    char currency[5];
    unsigned long long int current_amount;//llu
    char loanStatus[1];
    unsigned int monthly_income;
    unsigned int loan_amount;
    float loan_rate;
    char address[100];

    struct trans tr[300]; //transaction

    // %u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s


};

struct info db[USERSIZE];


void main_menu(){

    char input[2];
    printf("Welcome to our OnlineBank-NCC!\n");
    printf("Press 1 to Login!\nPress 2 to Register!\nPress 3 to Exit!>>:");
    scanf(" %[^\n]",&input);

    int option = check_input(input);
    if(option == 49){
        login();
    }else if(option == 50){
        rEgister();
    } else if(option ==51){
        printf("Good Bye!\n");
        exit(2);
    } else{
        main_menu();
    }

}
//ascii value 0=48 , 9=57
int check_input(char input[2]){
    if( input[0]>=49 &&input[0]<= 57 && input[1]=='\0'){
        return input[0];
    } else{
        return -1;
    }
}

void login(){
    char l_email[50];
    printf("This is Online Bank Login!\n");
    printf("Enter your email to login!>>:");
    scanf(" %[^\n]",&l_email[0]);


}

void rEgister(){

    char re_email[50];
    printf("This is Online Bank Register !\n");
    printf("Enter your email to register>>:");
    scanf(" %[^\n]",&re_email[0]);
}

void email_exist_checking(char email[50]){
    int counter = char_counting(email);

    int same_counting=0;
    for(register int gcc=0; gcc<G_index ; gcc++){
        int db_email_count = char_counting(db[gcc].email);

        if(counter == db_email_count){

            for(register int a=0; a<counter ; a++){
                if( email[a] !=db[gcc].email[0]){
                    break;
                }
                same_counting++;
            }
        }

        if(counter== same_counting){
            email_found=gcc;
        }


    }


}

int char_counting(char my_char[50]){

    int count=0;
    for(register int a=0; a<50; a++){

        if(my_char[a]  == '\0') {
            break;
        }
        count++;
    }

    return count;

}

void loading_from_file(){

    FILE *fptr = fopen("encrypted_data.txt","r");

    if( fptr != NULL){

        for(register int user=0; user < USERSIZE ; user++){

            fscanf(fptr ,"%u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s",&db[user].id ,&db[user].name ,&db[user].nrc,&db[user].email,&db[user].password,&db[user].phoneNumber,&db[user].encryption_key,&db[user].recovery_key,&db[user].account_status,&db[user].account_type,&db[user].account_level,&db[user].minimum_opening_deposit,&db[user].currency,&db[user].current_amount,&db[user].loanStatus,&db[user].monthly_income,&db[user].loan_amount,&db[user].loan_rate,&db[user].address);

            for(register int trc=0; trc<= space_array[user]-19 ; trc++ ){
                fscanf(fptr , "%s",&db[user].tr[trc].note);
            }
            if(db[user].id == 0){
                break;
            }
            G_index++;

        }


    } else{
        printf("File opening error at Loading form file function!\n");
    }

    fclose(fptr);


}

void printing_all_data(){


    for(int user=0; user<G_index ; user++){

        printf("%u-%s-%s-%s-%s-%u-%s-%s-%s-%d-%d-%d-%s-%llu-%s-%u-%u-%f-%s",db[user].id ,db[user].name ,db[user].nrc,db[user].email,db[user].password,db[user].phoneNumber,db[user].encryption_key,db[user].recovery_key,db[user].account_status,db[user].account_type,db[user].account_level,db[user].minimum_opening_deposit,db[user].currency,db[user].current_amount,db[user].loanStatus,db[user].monthly_income,db[user].loan_amount,db[user].loan_rate,db[user].address);
        for(int gcc=0; gcc<= space_array[user]-19 ; gcc++){
            printf("-%s",db[user].tr[gcc].note);
        }
        printf("\n");

    }




}

void space_counter(){

    FILE *fptr = fopen("encrypted_data.txt","r");

    if(fptr != NULL){

        char c = fgetc(fptr);
        int index=0;

        while (!feof(fptr)){

            if(c !='\n'){
                if(c == ' '){
                    space_array[index] +=1;
                }
                c = fgetc(fptr);
            } else{

                index++;
                c = fgetc(fptr);
            }

        }


    } else{
        printf("\nFile opening error at space_counter function!\n");
    }

    for(int i=0; i<DATA_COUNT ; i++){

        printf(" %d",space_array[i]);
    }
    printf("\n");

}


#endif //ONLINEBANKPJ_ONLINEBANK_H
