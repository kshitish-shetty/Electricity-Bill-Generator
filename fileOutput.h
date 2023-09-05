#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <stdio.h>
#include "struct.h"
#include "fileOutput.h"

void print_(int, FILE*);
void printHead_(int, FILE*);
void printInFormat(Info*,FILE*);
int printBilltoFile(Info*);


/*
NOTE SETUP FOR ADMIN :
One can easily include the file name as header file 
#include "fileOutput.h"

 OVERVIEW OF THE FUNCTION
 these are the auxillary methods used for the Print requirements of the method 
 printBilltoFile(Info* username)
 three auxillary methods are present to provide the interface.
*/

int printBilltoFile(Info* username) {
/*-----INTERFACE FILE-DRIVING METHOD----*/
    Info* user_ = username;
    FILE* file_ = fopen("ElectricityBill.txt","a");
    printInFormat(user_,file_);
    fclose(file_);
    return 0;
}

void print_(int howMuch , FILE* file){
/*-----this method is responsible to print dash ----*/
    fprintf(file,"\n");
    fprintf(file,"+");
    for (int dash = 0; dash < howMuch; dash++) {
        fprintf(file,"-");
    }
    fprintf(file,"+");
    fprintf(file,"\n");
}
void printHead_(int howMuch, FILE* file){
/*-----is responsible to print ELECTRICTY-BILL ----*/
    fprintf(file,"\n");
    for (int dash = 0; dash < howMuch/2; dash++) {
        fprintf(file,"-");
    }
    fprintf(file,"ELECTRICTY-BILL");
     for (int dash = 0; dash < howMuch/2; dash++) {
        fprintf(file,"-");
    }
    fprintf(file,"\n");
}
void printInFormat(Info* user,FILE* file){
/*-----this method is responsible to print all the user data to the file in format----*/
    int TILE_DASH = 26, DASH = 39;         // always we can adjust the size of the area here
    printHead_(TILE_DASH,file);
    print_(DASH,file);
    fprintf(file,"\nCustomer Name          : %s",user->name); // the struct name member should be accessed
    fprintf(file,"\nCustomer ID            : %s",user->ID);   // the struct ID member should be accessed 
    fprintf(file,"\nMonth                  : %d",user->month);  // the struct Month member should be accessed

    print_(DASH,file);
    fprintf(file,"\nPrevious Meter Reading : %.2f unit",user->pmr);   // the struct PMR member should be accessed
    fprintf(file,"\nCurrent Meter Reading  : %.2f unit",user->cmr);   // the struct CMR member should be accessed
    fprintf(file,"\nTotal Units. Used      : %.2f unit",user->units);  // the struct Total Units. member should be accessed
    fprintf(file,"\nEnergy Charges.        : %.2lf unit",user->amount); // the struct Energy Charges. member should be accessed

    print_(DASH,file);
    fprintf(file,"\nYour Electricity BILL  : Rs. %.2lf \n",user->amount); // the struct Total Amount calculated should be added

    print_(DASH,file);
    fprintf(file,"NOTE:DUE IS 30 DAYS FROM TODAY\n\tBILL MUST BE PAID WITHIN THE DUE.\n\tELSE YOU MAY BE CHARGED EXTRA.\n\n");
}

#endif