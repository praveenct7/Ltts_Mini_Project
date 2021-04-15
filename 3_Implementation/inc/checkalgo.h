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
          


int  char2int(char ch);              //converts character to integer
char int2char(int ch);               //converts integer to character

int  checkArg(char s[], int noOfArg, char *argstr[]);//checks the argument

int  extractNum(char str[], char num[]);             //extracts the number
void extractOption(char str[], char opt[], int pos); //extracts the option

void clearArr(char a[]);              //clears an array
void completeNumber(char a[]);        //fills incomplete number


int  ibm_mod10(char a[]);            //mod10 check
int  ibm_mod10_checksum(char a[]);   //creates checksum
void createNumMod10(char a[], char completenum[]); //generates a valid number


int  uspsmo(char a[]);                //usps money order  


int  upc_a(char a[]);                 //upc check
int  ean(char a[]);                   //ean check




int  isbn_10(char a[]);               //isbn 10 digits
int  isbn_13(char a[]);               //isbn 13 digits


int  routing(char a[]);               //routing number check

int  issn(char a[]);                  //issn check

int  imei(char a[]);                  //imei check


void version(void);                   //displays the version information
void usage(void);                     //displays the usage information

#endif

