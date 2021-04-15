/*
 *  checkalgo.c - functions for CheckAlgo
*/
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "checkalgo.h"




//Converts character to integer

int charToInt(char ch)
{
    int val = -1;
    
    switch(ch)
    {
       case '0' : val = 0; break;
       case '1' : val = 1; break;
       case '2' : val = 2; break;
       case '3' : val = 3; break;
       case '4' : val = 4; break;
       case '5' : val = 5; break;
       case '6' : val = 6; break;
       case '7' : val = 7; break;
       case '8' : val = 8; break;
       case '9' : val = 9; break;
    }
    
 
    return val;
}

//Converts integer to character
char intToChar(int ch)
{
     char val = NULLCHAR;
     
     switch(ch)
     {
       case 0 : val = '0'; break;
       case 1 : val = '1'; break;
       case 2 : val = '2'; break;
       case 3 : val = '3'; break;
       case 4 : val = '4'; break;
       case 5 : val = '5'; break;
       case 6 : val = '6'; break;
       case 7 : val = '7'; break;
       case 8 : val = '8'; break;
       case 9 : val = '9'; break;
     }
     
     return val;
}

//Parses the argument list to look for a specific string
int check_arguments(char s[], int noOfArg, char *argstr[])
{
  int i=1, position=0;
  
  for(i=1;i<noOfArg;i++)
  {
   if(strcmp(s,argstr[i])==0)
     position = i;
  }
  
  return position;
}

//extracts the number from the string
int  extract_number(char str[], char num[])
{
  int length,i,j;
  
  i=j=0;
  
  length = strlen(str);
  
  while(i<length && str[i]!=',')
  {
    num[j] = str[i];
    i++; j++;
  }
  num[j] = '\0';
  
  return i+1;
    
}

//extracts the option from the string
void extract_option(char str[], char opt[], int position)
{ 
  int i,j;
  
  i = position; j=0;
  
  while(i<strlen(str) && (str[i]!='\0') && (str[i]!='\n'))
  {
    opt[j] = str[i];
    i++; j++;
  }
}

//clears the array
void clear_array(char a[])
{
  int length=0,i;
  
  length = strlen(a);
  for(i=0; i<length; i++)
   a[i] = '\0';
}


//fills the number with random digits, leaving the last digit
void complete_number(char a[])
{
    int length,i;
  
    length = strlen(a);
  
    for(i=0; i<length-1; i++)
     { if(a[i] == '*')
        a[i] = intToChar(rand() %9); 
     }
}


//usage();
void usage(void)
{
  printf("\n\nChecks various identification numbers for its validity.");
  printf("\nUsage: checkalgo [options] number...");
  printf("\n\nOptions:\n");
  printf("-help         Displays this screen.\n");
  printf("-imei_number         Checks an imei_number number for its validity (15 digits).\n");
  printf("-serial_number         Checks an serial_number number for its validity (8 digits).\n");
  printf("-bankcrd      Checks a bank card number (Credit, Debit or other bank cards).\n");
  printf("-rout      Checks a Bank rout number (9 digits).\n");
  printf("-isbn10       Checks an ISBN (10 digits).\n");
  printf("-isbn13       Checks an ISBN (13 digits).\n");
  printf("-upc          Checks a UPC number (12 digits).\n");
  printf("-ean          Checks an EAN number (13 digits).\n");
  printf("-createMod10  Generates a valid number verified with mod10 algorithm.\n");
  printf("-i            Reads the input from a file. Input file in Number,Type format.\n");
  printf("              Ex: 5487934592459432,bankcrd. One entry per line.\n");
  printf("-o            Puts the output into a file.\n\n");
  printf("Example: checkalgo -imei_number 355340045855879\n");
  printf("         checkalgo -isbn13 9780070635463 -o output.txt\n");
  printf("         checkalgo -i input.txt -o output.txt\n");
  printf("Press any key to continue..."); getch();
  printf("\n\nGenerating a number verified with mod10 algorithm\n\n");
  printf("Example : checkalgo -create_number_mod10 5497*3922*29*23*\n\n");
  printf("\n\nOptions for input file:\n\n");
  printf("imei_number    - imei_number (15 digits)\n");
  printf("serial_number    - serial_number (8 digits)\n");
  printf("upc     - UPC (12 digits)\n");
  printf("ean     - EAN (13 digits)\n");
  printf("us_postal  - USPS Money order\n");
  printf("isbn10  - ISBN (10 digits)\n");
  printf("isbn13  - ISBN (13 digits)\n");
  printf("rout - rout NUMBER\n");
  printf("bankcrd - BANK CARD\n\n");
  printf("Sample Input file:\n\n");

  printf("5434872912349929,bankcrd\n");
  printf("9781234582345,isbn13\n");
  printf("0718345291,isbn10\n");
  printf("335423492918472,imei_number\n\n");
  
}


/*****************************************************************************
                            Mod10 algorithm - functions
******************************************************************************/

//Generates the check_sum
int mod10Checksum(char a[])
{
    int length, product, i, add, mod10;
    
    length = strlen(a);
    
    product = 2; add = 0;
    
    for(i=length-2; i>=0; i--)
     { 
        if( (charToInt(a[i])* product) >= 10 ) 
         add +=  ((charToInt(a[i])* product ) / 10) +((charToInt(a[i])* product ) % 10 );
       
        //if a[i] * product is less than 10 
        else
         add += charToInt(a[i])* product;
   
        if(product==2) product=1; //switches the value of product between 2 and 1
        else product=2;
     }   
     
    mod10 = add%10;
    
    if(mod10!=0)
      mod10 = 10 - mod10;
    
    return mod10;      
}



/* Check the number with mod10 algorithm and returns 1 if
   number is valid */
int modulus10(char a[])
{
   int i, length, product, add;
   int chksum;
   int mod10;
   
   
   length = strlen(a); //length of the string passed
 
   chksum = charToInt(a[length-1]); //Last element should be the check_sum
 

   product = 2; add=0;
   
   for(i=length-2; i>=0; i--)
   { 
    if( (charToInt(a[i])* product) >= 10 )
     add +=  ((charToInt(a[i])* product ) / 10) +((charToInt(a[i])* product ) % 10 );
    
    else
     add += charToInt(a[i])* product;
   
    if(product==2) product=1;
    else product=2;
   }
 
   mod10 = add%10;
 
   if(mod10) mod10 = 10 - mod10;
   
   if(mod10 == chksum)
    return VERIFIED;
       
   else
    return NOTVERIFIED;
}


//creates a number verified with mod10 algorithm
void create_number_mod10(char a[], char completenum[])
{
   int check_sum, orgcheck,length;
   
   strcpy(completenum, a);
   
   length = strlen(completenum);
   
   if(completenum[length-1] == '*')
   { complete_number(completenum);
     check_sum = mod10Checksum(completenum);
     completenum[length-1] = intToChar(check_sum);
   }
   
   else
    {
      do 
      { 
        clear_array(completenum);
        strcpy(completenum,a);
        complete_number(completenum);
        check_sum = mod10Checksum(completenum);
        orgcheck = charToInt(completenum[length-1]);
       // printf("\n%s  %d  %d",completenum,check_sum,orgcheck);        
      }while(orgcheck != check_sum);
    }
 }
     
/*-----------------------------------------------------------------------*/

/* 
                            US POSTAL MONEY ORDER
    mod9 algorithm
    
    Checks the number with mod9 and returns 1 if true and return 0 if invalid
    If check_sum is not provided and is replaced by *, then the calculated
    check_sum is returned
    
    US POSTAL MONEY ORDER number should be 12 digits
    
**************************************************************************/

int us_postal(char a[])
{
    int length=0, i, add=0, check_sum=0, mod9=0;
    
    length = strlen(a);
    
    
    if(length!=11)
     return INVALID;
    
    if(a[length-1]=='*')
    {
      for(i=0; i<length-1; i++)
       add += charToInt(a[i]);
       
      mod9 = add % 9;
      return mod9;
    }
    
    check_sum = charToInt(a[length-1]);
    
    for(i=0; i<length-1; i++)
      add += charToInt(a[i]);
       
    mod9 = add % 9;
      
    if(mod9 == check_sum )
     return VERIFIED;
    else
     return NOTVERIFIED;
}

/***************************************************************************/

/*
                     UNIVERSAL PRODUCT CODE (UPC) and EAN
  
  Checks the number and if the checkdigit (the last digit) is not supplied, 
  and is replaced by *, then the checkdigit is calculated and returns the 
  check_sum
  
  UPC should be of 12 digits
***************************************************************************/
int universal_product_code(char a[])
{
    int check_sum = 0;
    int i, length,product=3,add=0, mod10=0;
    
    length = strlen(a);
    
     
     if(length!=12)
      return INVALID;
      
      
    if(a[length-1] == '*')
     {
       for(i=0; i<length-1; i++)
       {
         add += charToInt(a[i]) * product;
         if(product==3) product=1;
         else product = 3;
       }
       mod10 = add%10;
       mod10 = 10 - mod10;
       return mod10;
     }                
    
    
    
    for(i=0; i<length; i++)
    {
      add += charToInt(a[i]) * product;
      if(product==3) product=1;
      else product = 3;
    }
    
    mod10 = add%10;
    
    if(mod10 == 0)
     return VERIFIED;
    else
     return NOTVERIFIED;
}
    

/****************************************************************************/

/****************************************************************************
               ISBN (International Standard Book Number)
  
  Check the number for validity for a 10 digit ISBN number.
  If the check_sum is not provided in the string (the last digit), and is 
  replaced by *, then the calculated check_sum is retured.
  
****************************************************************************/
int book_number_10(char a[])
{
    int check_sum = 0;
    int i, length,position=1,add=0, mod11;
    
    
    
    length = strlen(a);
    
    if(length!=10) 
     return INVALID;
    
    if(a[length-1]=='*')
    {
      for( i=0,position=1; i<length-1; i++,position++)
      add += charToInt(a[i]) * position;
    
      mod11 = add % 11;
      
      return mod11;
    }
                     
    
    
    check_sum = charToInt(a[length-1]);
    
    for( i=0,position=1; i<length-1; i++,position++)
     add += charToInt(a[i]) * position;
    
    mod11 = add % 11;
    if(mod11 == check_sum)
     return VERIFIED;
    else
     return NOTVERIFIED;
         
}

//ISBN check algorithm for 13 digit number
int book_number_13(char a[])
{
    int check_sum = 0;
    int i, length, product=1,add=0, mod10;
    
    
    length = strlen(a);
    
    
    if(length!=13)
     return INVALID;
    
    if(a[length-1]=='*')
    {
      for(i=0; i<length-1; i++)
      {
        add += charToInt(a[i]) * product;
        if(product==3) product=1;
        else product = 3;
      }
    
       mod10 = add%10;
       mod10 = 10-mod10;
       return mod10;
    }
    
    check_sum = charToInt(a[length-1]);
    
    for(i=0; i<length-1; i++)
    {
      add += charToInt(a[i]) * product;
      if(product==3) product=1;
      else product = 3;
    }
    
    mod10 = add%10;
    
    if( (10-mod10) == check_sum)
     return VERIFIED;
    else
     return NOTVERIFIED;
}
/***************************************************************************/

/***************************************************************************
                         Bank rout number check
   
   If the checkdigit is not mentioned in the string passed, this function
   returns the check_sum
   
****************************************************************************/
int rout(char a[])
{
    int check_sum = 0, length=0, add=0, mod10=0;
    
    length = strlen(a);
    
    if(length!=9)
     return INVALID;
    
    if(a[length-1] == '*')
    {
      add = (7 * ( charToInt(a[0]) + charToInt(a[3]) + charToInt(a[6]) )) + 
            (3 * ( charToInt(a[1]) + charToInt(a[4]) + charToInt(a[7]) )) +
            (9 * ( charToInt(a[2]) + charToInt(a[5]) ));
    
      mod10 = add % 10;
      return mod10;
    }

    
    check_sum = charToInt(a[length-1]);
    
    add = (7 * ( charToInt(a[0]) + charToInt(a[3]) + charToInt(a[6]) )) + 
          (3 * ( charToInt(a[1]) + charToInt(a[4]) + charToInt(a[7]) )) +
          (9 * ( charToInt(a[2]) + charToInt(a[5]) ));
    
    mod10 = add % 10;
    
    if(mod10 == check_sum)
     return VERIFIED;
    else
     return NOTVERIFIED;
}
/*****************************************************************************/

/***************************************************************************** 
                 serial_number (International Standard Serial Number)
   
   serial_number is an eight digit number
   If the checkdigit is not mentioned in the string passed, this function
   returns the check_sum
*****************************************************************************/

int serial_number(char a[])
{
   int length=0, mod11=0, position=8, i=0, add=0, check_sum=0;
   
   length = strlen(a);
   
   if(length!=8)
    return INVALID;
   
   if(a[length-1]=='*')
   {
     for(i=0,position=8; i<length-1; i++,position--)
      add += charToInt(a[i]) * position;
     
     mod11 = add % 11;
     if(mod11!=0) mod11 = 11 - mod11;
     
     return mod11;
   }
   
   check_sum = charToInt(a[length-1]);
   
   for(i=0,position=8; i<length-1; i++,position--)
      add += charToInt(a[i]) * position;
     
   mod11 = add % 11;
   if(mod11!=0) mod11 = 11 - mod11;
   
   if(mod11 == check_sum) 
    return VERIFIED;
   else
    return NOTVERIFIED;
}
    
/*****************************************************************************/

/*****************************************************************************
                    imei_number (International Mobile Equipment Identity)
    15 digit number
    
*****************************************************************************/
   
int imei_number(char a[])
{
   int i,length,product,add;
   int chksum;
   int mod10;

   length = strlen(a);
   
   if(length!=15)
    return INVALID;
    
   chksum = charToInt(a[length-1]); //Last element should be the check_sum
 

   product = 2; add=0;
   
   for(i=length-2;i>=0;i--)
   { 
    if( (charToInt(a[i])*product) >= 10 )
     add +=  ((charToInt(a[i])*product ) / 10) +((charToInt(a[i])*product ) % 10 );
    
    else
     add += charToInt(a[i])*product;
   
    if(product==2) product=1;
    else product=2;
   }
 
   mod10 = add%10;
 
   if(mod10) mod10 = 10 - mod10;
   if(mod10 == chksum) return VERIFIED;
   else 
    return NOTVERIFIED;
}

/***************************************************************************/
