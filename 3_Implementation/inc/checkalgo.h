/*
 *  checkalgo.h - function definations for CheckAlgo
 *
 */
 

#ifndef CHECKALGO_H
#define CHECKALGO_H

#define   NULLCHAR      '\0'
#define   VERIFIED       77
#define   NOTVERIFIED     0
#define   INVALID        -1
          


int  charToInt(char ch);              //converts character to integer
char intToChar(int ch);               //converts integer to character

int  check_arguments(char s[], int noOfArg, char *argstr[]);//checks the argument

int  extract_number(char str[], char num[]);             //extracts the number
void extract_option(char str[], char opt[], int pos); //extracts the option

void clear_array(char a[]);              //clears an array
void complete_Number(char a[]);        //fills incomplete number


int  modulus10(char a[]);            //mod10 check
int  mod10Checksum(char a[]);   //creates checksum
void create_number_mod10(char a[], char completenum[]); //generates a valid number


int  us_postal(char a[]);                //usps money order  


int  universal_product_code(char a[]);                 //upc check




int  book_number_10(char a[]);               //isbn 10 digits
int  book_number_13(char a[]);               //isbn 13 digits


int  rout(char a[]);               //routing number check

int  serial_number(char a[]);                  //issn check

int  imei_number(char a[]);                  //imei check
void usage(void);                     //displays the usage information

#endif

