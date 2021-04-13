/*
 *  checkalgo.c - functions for CheckAlgo
 *
 *  Copyright (c) 2012  Shine Jayakumar (shine_hack@yahoo.com)
 *
 *  This file is part of CheckAlgo.
 *
 *  CheckAlgo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CheckAlgo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CheckAlgo.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 

#include <stdio.h>
#include <stdlib.h>
#include "checkalgo.h"




//Converts character to integer

int char2int(char ch)
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
char int2char(int ch)
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
int checkArg(char s[], int noOfArg, char *argstr[])
{
  int i=1, pos=0;
  
  for(i=1;i<noOfArg;i++)
  {
   if(strcmp(s,argstr[i])==0)
     pos = i;
  }
  
  return pos;
}

//extracts the number from the string
int  extractNum(char str[], char num[])
{
  int len,i,j;
  
  i=j=0;
  
  len = strlen(str);
  
  while(i<len && str[i]!=',')
  {
    num[j] = str[i];
    i++; j++;
  }
  num[j] = '\0';
  
  return i+1;
    
}

//extracts the option from the string
void extractOption(char str[], char opt[], int pos)
{ 
  int i,j;
  
  i = pos; j=0;
  
  while(i<strlen(str) && (str[i]!='\0') && (str[i]!='\n'))
  {
    opt[j] = str[i];
    i++; j++;
  }
}

//clears the array
void clearArr(char a[])
{
  int len=0,i;
  
  len = strlen(a);
  for(i=0; i<len; i++)
   a[i] = '\0';
}


//fills the number with random digits, leaving the last digit
void completeNumber(char a[])
{
    int len,i;
  
    len = strlen(a);
  
    for(i=0; i<len-1; i++)
     { if(a[i] == '*')
        a[i] = int2char(rand() %9); 
     }
}


//usage();
void usage(void)
{
  printf("\nCheckAlgo v.1.1");
  printf("\n\nChecks various identification numbers for its validity.");
  printf("\nUsage: checkalgo [options] number...");
  printf("\n\nOptions:\n");
  printf("-help         Displays this screen.\n");
  printf("-version      Displays the version and license information.\n");
  printf("-imei         Checks an IMEI number for its validity (15 digits).\n");
  printf("-issn         Checks an ISSN number for its validity (8 digits).\n");
  printf("-bankcrd      Checks a bank card number (Credit, Debit or other bank cards).\n");
  printf("-routing      Checks a Bank Routing number (9 digits).\n");
  printf("-isbn10       Checks an ISBN (10 digits).\n");
  printf("-isbn13       Checks an ISBN (13 digits).\n");
  printf("-upc          Checks a UPC number (12 digits).\n");
  printf("-ean          Checks an EAN number (13 digits).\n");
  printf("-uspsmo       Checks a USPS money order number (12 digits).\n");
  printf("-createMod10  Generates a valid number verified with mod10 algorithm.\n");
  printf("-version      Displays the version.\n");
  printf("-i            Reads the input from a file. Input file in Number,Type format.\n");
  printf("              Ex: 5487934592459432,bankcrd. One entry per line.\n");
  printf("-o            Puts the output into a file.\n\n");
  printf("Example: checkalgo -imei 355340045855879\n");
  printf("         checkalgo -isbn13 9780070635463 -o output.txt\n");
  printf("         checkalgo -i input.txt -o output.txt\n");
  printf("Press any key to continue..."); getch();
  printf("\n\nGenerating a number verified with mod10 algorithm\n\n");
  printf("Example : checkalgo -createNumMod10 5497*3922*29*23*\n\n");
  printf("\n\nOptions for input file:\n\n");
  printf("imei    - IMEI (15 digits)\n");
  printf("issn    - ISSN (8 digits)\n");
  printf("upc     - UPC (12 digits)\n");
  printf("ean     - EAN (13 digits)\n");
  printf("uspsmo  - USPS Money order\n");
  printf("isbn10  - ISBN (10 digits)\n");
  printf("isbn13  - ISBN (13 digits)\n");
  printf("routing - ROUTING NUMBER\n");
  printf("bankcrd - BANK CARD\n\n");
  printf("Sample Input file:\n\n");

  printf("5434872912349929,bankcrd\n");
  printf("9781234582345,isbn13\n");
  printf("0718345291,isbn10\n");
  printf("335423492918472,imei\n\n");
  printf("For any queries or suggestion, please email at shine_hack@yahoo.com.\n\n");
  
  
  
}

//version information
void version(void)
{
  printf("\nCheckAlgo v.1.1\n");
  printf("\nVersion : 1.1");
  printf("\nAuthor  : Shine Jayakumar");
  printf("\nEmail   : shine_hack@yahoo.com");
  printf("\nLicence : GNU GENERAL PUBLIC LICENSE  - Version 3, 29 June 2007\n\n");
  printf("Copyright (c) 2012  Shine Jayakumar (shine_hack@yahoo.com)\n\n");
  
  printf("CheckAlgo is free software: you can redistribute it and/or modify\n");
  printf("it under the terms of the GNU General Public License as published by\n");
  printf("the Free Software Foundation, either version 3 of the License, or\n");
  printf("(at your option) any later version.\n\n");   
  printf("CheckAlgo is distributed in the hope that it will be useful,\n");
  printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
  printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
  printf("GNU General Public License for more details.\n\n");
  printf("You should have received a copy of the GNU General Public License\n");
  printf("along with CheckAlgo.  If not, see <http://www.gnu.org/licenses/>.\n");
}
   
  
  
  
  
/****************************************************************************/


/*****************************************************************************
                            Mod10 algorithm - functions
******************************************************************************/

//Generates the checksum
int ibm_mod10_checksum(char a[])
{
    int len, mul, i, sum, m10;
    
    len = strlen(a);
    
    mul = 2; sum = 0;
    
    for(i=len-2; i>=0; i--)
     { 
        if( (char2int(a[i])* mul) >= 10 ) 
         sum +=  ((char2int(a[i])* mul ) / 10) +((char2int(a[i])* mul ) % 10 );
       
        //if a[i] * mul is less than 10 
        else
         sum += char2int(a[i])* mul;
   
        if(mul==2) mul=1; //switches the value of mul between 2 and 1
        else mul=2;
     }   
     
    m10 = sum%10;
    
    if(m10!=0)
      m10 = 10 - m10;
    
    return m10;      
}



/* Check the number with mod10 algorithm and returns 1 if
   number is valid */
int ibm_mod10(char a[])
{
   int i, len, mul, sum;
   int chksum;
   int m10;
   
   
   len = strlen(a); //length of the string passed
 
   chksum = char2int(a[len-1]); //Last element should be the checksum
 

   mul = 2; sum=0;
   
   for(i=len-2; i>=0; i--)
   { 
    if( (char2int(a[i])* mul) >= 10 )
     sum +=  ((char2int(a[i])* mul ) / 10) +((char2int(a[i])* mul ) % 10 );
    
    else
     sum += char2int(a[i])* mul;
   
    if(mul==2) mul=1;
    else mul=2;
   }
 
   m10 = sum%10;
 
   if(m10) m10 = 10 - m10;
   
   if(m10 == chksum)
    return VERIFIED;
       
   else
    return NOTVERIFIED;
}


//creates a number verified with mod10 algorithm
void createNumMod10(char a[], char completenum[])
{
   int checksum, orgcheck,len;
   
   strcpy(completenum, a);
   
   len = strlen(completenum);
   
   if(completenum[len-1] == '*')
   { completeNumber(completenum);
     checksum = ibm_mod10_checksum(completenum);
     completenum[len-1] = int2char(checksum);
   }
   
   else
    {
      do 
      { 
        clearArr(completenum);
        strcpy(completenum,a);
        completeNumber(completenum);
        checksum = ibm_mod10_checksum(completenum);
        orgcheck = char2int(completenum[len-1]);
       // printf("\n%s  %d  %d",completenum,checksum,orgcheck);        
      }while(orgcheck != checksum);
    }
 }
     
/*-----------------------------------------------------------------------*/

/* 
                            US POSTAL MONEY ORDER
    mod9 algorithm
    
    Checks the number with mod9 and returns 1 if true and return 0 if invalid
    If checksum is not provided and is replaced by *, then the calculated
    checksum is returned
    
    US POSTAL MONEY ORDER number should be 12 digits
    
**************************************************************************/

int uspsmo(char a[])
{
    int len=0, i, sum=0, checksum=0, mod9=0;
    
    len = strlen(a);
    
    
    if(len!=11)
     return INVALID;
    
    if(a[len-1]=='*')
    {
      for(i=0; i<len-1; i++)
       sum += char2int(a[i]);
       
      mod9 = sum % 9;
      return mod9;
    }
    
    checksum = char2int(a[len-1]);
    
    for(i=0; i<len-1; i++)
      sum += char2int(a[i]);
       
    mod9 = sum % 9;
      
    if(mod9 == checksum )
     return VERIFIED;
    else
     return NOTVERIFIED;
}

/***************************************************************************/

/*
                     UNIVERSAL PRODUCT CODE (UPC) and EAN
  
  Checks the number and if the checkdigit (the last digit) is not supplied, 
  and is replaced by *, then the checkdigit is calculated and returns the 
  checksum
  
  UPC should be of 12 digits
***************************************************************************/
int upc_a(char a[])
{
    int checksum = 0;
    int i, len,mul=3,sum=0, m10=0;
    
    len = strlen(a);
    
     
     if(len!=12)
      return INVALID;
      
      
    if(a[len-1] == '*')
     {
       for(i=0; i<len-1; i++)
       {
         sum += char2int(a[i]) * mul;
         if(mul==3) mul=1;
         else mul = 3;
       }
       m10 = sum%10;
       m10 = 10 - m10;
       return m10;
     }                
    
    
    
    for(i=0; i<len; i++)
    {
      sum += char2int(a[i]) * mul;
      if(mul==3) mul=1;
      else mul = 3;
    }
    
    m10 = sum%10;
    
    if(m10 == 0)
     return VERIFIED;
    else
     return NOTVERIFIED;
}

//checks an ean
int ean(char a[])
{
    int len=0,i=0, sum=0, mul=1, mod10, checksum;
    
    len = strlen(a);
    
    if(len!=13)
     return INVALID;
    
    if(a[len-1] == '*')
    {
      for(i=0; i<len-1; i++)
      {
        sum += char2int(a[i]) * mul;
        if(mul==1) mul = 3;
        else mul = 1;
        
      }
     mod10 = sum % 10; 
     mod10 = 10 - mod10;
     return mod10;
    }
    
    checksum = char2int(a[len-1]);
    for(i=0; i<len-1; i++)
      {
        sum += char2int(a[i]) * mul;
        if(mul==1) mul = 3;
        else mul = 1;
        
      }
     mod10 = sum % 10; 
     mod10 = 10 - mod10;
     
     if(mod10 == checksum)
      return VERIFIED;
     else
      return NOTVERIFIED;
}
    

    
    

/****************************************************************************/

/****************************************************************************
               ISBN (International Standard Book Number)
  
  Check the number for validity for a 10 digit ISBN number.
  If the checksum is not provided in the string (the last digit), and is 
  replaced by *, then the calculated checksum is retured.
  
****************************************************************************/
//ISBN for 10 digits
int isbn_10(char a[])
{
    int checksum = 0;
    int i, len,pos=1,sum=0, m11;
    
    
    
    len = strlen(a);
    
    if(len!=10) 
     return INVALID;
    
    if(a[len-1]=='*')
    {
      for( i=0,pos=1; i<len-1; i++,pos++)
      sum += char2int(a[i]) * pos;
    
      m11 = sum % 11;
      
      return m11;
    }
                     
    
    
    checksum = char2int(a[len-1]);
    
    for( i=0,pos=1; i<len-1; i++,pos++)
     sum += char2int(a[i]) * pos;
    
    m11 = sum % 11;
    if(m11 == checksum)
     return VERIFIED;
    else
     return NOTVERIFIED;
         
}

//ISBN check algorithm for 13 digit number
int isbn_13(char a[])
{
    int checksum = 0;
    int i, len,mul=1,sum=0, m10;
    
    
    len = strlen(a);
    
    
    if(len!=13)
     return INVALID;
    
    if(a[len-1]=='*')
    {
      for(i=0; i<len-1; i++)
      {
        sum += char2int(a[i]) * mul;
        if(mul==3) mul=1;
        else mul = 3;
      }
    
       m10 = sum%10;
       m10 = 10-m10;
       return m10;
    }
    
    checksum = char2int(a[len-1]);
    
    for(i=0; i<len-1; i++)
    {
      sum += char2int(a[i]) * mul;
      if(mul==3) mul=1;
      else mul = 3;
    }
    
    m10 = sum%10;
    
    if( (10-m10) == checksum)
     return VERIFIED;
    else
     return NOTVERIFIED;
}
/***************************************************************************/

/***************************************************************************
                         Bank routing number check
   
   If the checkdigit is not mentioned in the string passed, this function
   returns the checksum
   
****************************************************************************/
int routing(char a[])
{
    int checksum = 0, len=0, sum=0, m10=0;
    
    len = strlen(a);
    
    if(len!=9)
     return INVALID;
    
    if(a[len-1] == '*')
    {
      sum = (7 * ( char2int(a[0]) + char2int(a[3]) + char2int(a[6]) )) + 
            (3 * ( char2int(a[1]) + char2int(a[4]) + char2int(a[7]) )) +
            (9 * ( char2int(a[2]) + char2int(a[5]) ));
    
      m10 = sum % 10;
      return m10;
    }

    
    checksum = char2int(a[len-1]);
    
    sum = (7 * ( char2int(a[0]) + char2int(a[3]) + char2int(a[6]) )) + 
          (3 * ( char2int(a[1]) + char2int(a[4]) + char2int(a[7]) )) +
          (9 * ( char2int(a[2]) + char2int(a[5]) ));
    
    m10 = sum % 10;
    
    if(m10 == checksum)
     return VERIFIED;
    else
     return NOTVERIFIED;
}
/*****************************************************************************/

/***************************************************************************** 
                 ISSN (International Standard Serial Number)
   
   ISSN is an eight digit number
   If the checkdigit is not mentioned in the string passed, this function
   returns the checksum
*****************************************************************************/

int issn(char a[])
{
   int len=0, m11=0, pos=8, i=0, sum=0, checksum=0;
   
   len = strlen(a);
   
   if(len!=8)
    return INVALID;
   
   if(a[len-1]=='*')
   {
     for(i=0,pos=8; i<len-1; i++,pos--)
      sum += char2int(a[i]) * pos;
     
     m11 = sum % 11;
     if(m11!=0) m11 = 11 - m11;
     
     return m11;
   }
   
   checksum = char2int(a[len-1]);
   
   for(i=0,pos=8; i<len-1; i++,pos--)
      sum += char2int(a[i]) * pos;
     
   m11 = sum % 11;
   if(m11!=0) m11 = 11 - m11;
   
   if(m11 == checksum) 
    return VERIFIED;
   else
    return NOTVERIFIED;
}
    
/*****************************************************************************/

/*****************************************************************************
                    IMEI (International Mobile Equipment Identity)
    15 digit number
    
*****************************************************************************/
   
int imei(char a[])
{
   int i,len,mul,sum;
   int chksum;
   int m10;

   len = strlen(a);
   
   if(len!=15)
    return INVALID;
    
   chksum = char2int(a[len-1]); //Last element should be the checksum
 

   mul = 2; sum=0;
   
   for(i=len-2;i>=0;i--)
   { 
    if( (char2int(a[i])*mul) >= 10 )
     sum +=  ((char2int(a[i])*mul ) / 10) +((char2int(a[i])*mul ) % 10 );
    
    else
     sum += char2int(a[i])*mul;
   
    if(mul==2) mul=1;
    else mul=2;
   }
 
   m10 = sum%10;
 
   if(m10) m10 = 10 - m10;
   if(m10 == chksum) return VERIFIED;
   else 
    return NOTVERIFIED;
}

/***************************************************************************/
