#include "stdio.h"
#include "onlineBank.h"

int main(){
//    space_counter();
//    loading_from_file();
//    printing_all_data();
//    main_menu();

    //get_time();


//    integer_to_charArrayFun(1500);
//    printf(" char array %s",int_to_charArray);

    char myarr[5]={'1','2','5','0'};
    unsigned int data =char_to_integer_fun(myarr);
    printf(" data %u",data);
    return 0;
}