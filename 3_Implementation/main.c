/*
 *  main.c - command line frontend for CheckAlgo
*/
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "checkalgo.h"



int main(int argc, char *argv[])
{
  int  position=0, value = 0, outfile = 0, len, i;
  char filename[30], str[60],number[30],option[30];
  char outputstring[200], ch;
  
  FILE *ofile, *ifile; //read and write file handle
  
  
  if(argc<2)
  { usage(); return 1; }
  
  //Checks whether the -o option has been supplied
  if(position = check_arguments("-o", argc, argv))
  { 
    ofile = fopen(argv[position+1],"w");
    if(ofile==NULL)
     printf("\nUnable to open file.\n");
    else
     outfile=1;
    position = 0;
  }
  
 
  //Check if the input is to be taken from a file
  if(position = check_arguments("-i", argc, argv))
   { 
     strcpy(filename, argv[position+1]);
     
     if( (ifile = fopen(filename,"r")) == NULL)
      { printf("\nUnable to open file.\n"); return 2; }
     
     
     while(!feof(ifile))
     {
       fgets(str,30,ifile);        //reads a line from the file
       position = extract_number(str,number);  //gets the number from the line read
       extract_option(str,option,position); //gets the option from the line read
      
       //imei_number
       if(strcmp("imei_number", option)==0)
       {
         if( (value = imei_number(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (imei_number) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (imei_number) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (imei_number): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (imei_number) - INVALID LENGTH", number);
       }
       
       //serial_number
       else if(strcmp("serial_number", option)==0)
       {
         if( (value = serial_number(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (serial_number) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (serial_number) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (serial_number): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (serial_number) - INVALID LENGTH", number);
       }
       
       //ISBN-10
       else if(strcmp("book_number_10", option)==0)
       {
         if( (value = book_number_10(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-10) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-10) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-10): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-10) - INVALID LENGTH", number);
       }
       
       //ISBN-13
       else if(strcmp("book_number_13", option)==0)
       {
         if( (value = book_number_13(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-13) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-13) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-13): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-13) - INVALID LENGTH", number);
       }
       
       //universal_product_code
       else if(strcmp("universal_product_code", option)==0)
       {
         if( (value = universal_product_code(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (universal_product_code) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (universal_product_code) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (universal_product_code): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (universal_product_code) - INVALID LENGTH", number);
       }
       
       
       //USPS Money Order
       else if(strcmp("us_postal", option)==0)
       {
         if( (value = us_postal(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (USPS MO) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (USPS MO) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (USPC MO): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (USPS MO) - INVALID LENGTH", number);
       }
       
       //rout numberber
       else if(strcmp("rout", option)==0)
       {
         if( (value = rout(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (rout) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (rout) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (rout): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (rout) - INVALID LENGTH", number);
       }
       
       //BANKD CARD
       else if(strcmp("bankcrd", option)==0)
       {
         if( (value = modulus10(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (BANK CARD) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (BANK CARD) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (BANK CARD): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (BANK CARD) - INVALID LENGTH", number);
       }
       
      
       if(outfile)
        fprintf(ofile,"%s\n",outputstring); //puts the output to the file
       
       printf("\n%s",outputstring);   
       
       clear_array(str); clear_array(number); clear_array(option);
       clear_array(outputstring);
       
       position=0;
     }
    
     fclose(ifile);
     
     if(outfile) 
       fclose(ofile);
    }
     
  
  //imei_number 
  else if((position = check_arguments("-imei_number", argc, argv)))
  {
     if((value = imei_number(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (imei_number) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (imei_number) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
       sprintf(outputstring,"\n%s (imei_number): checksum => %d\n",argv[position+1],value);
    else 
      sprintf(outputstring,"\n%s (imei_number) - INVALID LENGTH\n", argv[position+1]);
    if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
    printf("\n%s",outputstring);
    
  }
  
  //serial_number
  else if((position = check_arguments("-serial_number", argc, argv)))
  { 
     if((value = serial_number(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (serial_number) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (serial_number) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (serial_number): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (serial_number) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
   }
   
  //rout
  else if((position = check_arguments("-rout", argc, argv)))
  { 
     if((value = rout(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (rout) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (rout) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (rout): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (rout) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //ISBN-10
  else if((position = check_arguments("-book_number_10", argc, argv)))
  { 
     if((value = book_number_10(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISBN-10) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISBN-10) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-10): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISBN-10) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //ISBN-13
  else if((position = check_arguments("-book_number_13", argc, argv)))
  { 
     if((value = book_number_13(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISBN-13) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISBN-13) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISBN-13) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //universal_product_code
  else if((position = check_arguments("-universal_product_code", argc, argv)))
  { 
     if((value = universal_product_code(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (universal_product_code) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (universal_product_code) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (universal_product_code): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (universal_product_code) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //USPS Money Order
  else if((position = check_arguments("-us_postal", argc, argv)))
  { 
     if((value = us_postal(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (us_postal) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (us_postal) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (us_postal): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (us_postal) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //BANK CARD
  else if((position = check_arguments("-bankcrd", argc, argv)))
  { 
     if((value = modulus10(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (BANK CARD) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (BANK CARD) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (BANK CARD): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (BANK CARD) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
     { fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //-createMod10
  else if((position = check_arguments("-create_number_mod10", argc, argv)))
  {    
       len = strlen(argv[position+1]);
       
       if(argv[position+1][len-1]=='*')
       { create_number_mod10(argv[position+1],number);
         printf("%s\n",number);
         if(outfile)
         { fprintf(ofile,"\n%s",number); fclose(ofile); }
       }
       
       else
       { 
         printf("\n\nShowing first 10 combinations...\n\n");
         do
         {
           for(i=0; i<10; i++)
           {
            clear_array(number);
            create_number_mod10(argv[position+1],number);
            printf("\n%s",number);
            if(outfile)
            { fprintf(ofile,"\n%s",number); }
           }
           printf("\n\nSee more combinations (Y/N)?\n\n"); 
           ch = getch();
         }while(ch=='y' || ch=='Y');
         
          if(outfile)
           fclose(ofile);
       }
   }
  
  
  else 
   usage();
  
  
  return 0;
}
