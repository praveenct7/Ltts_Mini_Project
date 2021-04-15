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
  if(position = checkArg("-o", argc, argv))
  { 
    ofile = fopen(argv[position+1],"w");
    if(ofile==NULL)
     printf("\nUnable to open file.\n");
    else
     outfile=1;
    position = 0;
  }
  
 
  //Check if the input is to be taken from a file
  if(position = checkArg("-i", argc, argv))
   { 
     strcpy(filename, argv[position+1]);
     
     if( (ifile = fopen(filename,"r")) == NULL)
      { printf("\nUnable to open file.\n"); return 2; }
     
     
     while(!feof(ifile))
     {
       fgets(str,30,ifile);        //reads a line from the file
       position = extractNum(str,number);  //gets the number from the line read
       extractOption(str,option,position); //gets the option from the line read
      
       //IMEI
       if(strcmp("imei", option)==0)
       {
         if( (value = imei(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (IMEI) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (IMEI) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (IMEI): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (IMEI) - INVALID LENGTH", number);
       }
       
       //ISSN
       else if(strcmp("issn", option)==0)
       {
         if( (value = issn(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISSN) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISSN) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISSN): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISSN) - INVALID LENGTH", number);
       }
       
       //ISBN-10
       else if(strcmp("isbn10", option)==0)
       {
         if( (value = isbn_10(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-10) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-10) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-10): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-10) - INVALID LENGTH", number);
       }
       
       //ISBN-13
       else if(strcmp("isbn13", option)==0)
       {
         if( (value = isbn_13(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-13) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-13) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-13): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-13) - INVALID LENGTH", number);
       }
       
       //UPC
       else if(strcmp("upc", option)==0)
       {
         if( (value = upc_a(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (UPC) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (UPC) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (UPC): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (UPC) - INVALID LENGTH", number);
       }
       
       //EAN
       else if(strcmp("ean", option)==0)
       {
         if( (value = ean(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (EAN) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (EAN) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (EAN): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (EAN) - INVALID LENGTH", number);
       }
       
       //USPS Money Order
       else if(strcmp("uspsmo", option)==0)
       {
         if( (value = uspsmo(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (USPS MO) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (USPS MO) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (USPC MO): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (USPS MO) - INVALID LENGTH", number);
       }
       
       //ROUTING numberber
       else if(strcmp("routing", option)==0)
       {
         if( (value = routing(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ROUTING) - VALID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ROUTING) - INVALID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ROUTING): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ROUTING) - INVALID LENGTH", number);
       }
       
       //BANKD CARD
       else if(strcmp("bankcrd", option)==0)
       {
         if( (value = ibm_mod10(number)) == VERIFIED )
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
       
       clearArr(str); clearArr(number); clearArr(option);
       clearArr(outputstring);
       
       position=0;
     }
    
     fclose(ifile);
     
     if(outfile) 
       fclose(ofile);
    }
     
  //VERSION
  else if(position = checkArg("-version", argc, argv))
   {
     version(); position = 0; return 2; 
   }
  
  
  //IMEI 
  else if((position = checkArg("-imei", argc, argv)))
  {
     if((value = imei(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (IMEI) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (IMEI) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
       sprintf(outputstring,"\n%s (IMEI): checksum => %d\n",argv[position+1],value);
    else 
      sprintf(outputstring,"\n%s (IMEI) - INVALID LENGTH\n", argv[position+1]);
    if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
    printf("\n%s",outputstring);
    
  }
  
  //ISSN
  else if((position = checkArg("-issn", argc, argv)))
  { 
     if((value = issn(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISSN) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISSN) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISSN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISSN) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
   }
   
  //ROUTING
  else if((position = checkArg("-routing", argc, argv)))
  { 
     if((value = routing(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ROUTING) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ROUTING) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ROUTING): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ROUTING) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //ISBN-10
  else if((position = checkArg("-isbn10", argc, argv)))
  { 
     if((value = isbn_10(argv[position+1]))==VERIFIED)
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
  else if((position = checkArg("-isbn13", argc, argv)))
  { 
     if((value = isbn_13(argv[position+1]))==VERIFIED)
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
  
  
  //UPC
  else if((position = checkArg("-upc", argc, argv)))
  { 
     if((value = upc_a(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (UPC) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (UPC) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (UPC): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (UPC) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //EAN
  else if((position = checkArg("-ean", argc, argv)))
  { 
     if((value = ean(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (EAN) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (EAN) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (EAN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (EAN) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //USPS Money Order
  else if((position = checkArg("-uspsmo", argc, argv)))
  { 
     if((value = uspsmo(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (USPSMO) -  VALID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (USPSMO) - INVALID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (USPSMO): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (USPSMO) - INVALID LENGTH\n", argv[position+1]);
     if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //BANK CARD
  else if((position = checkArg("-bankcrd", argc, argv)))
  { 
     if((value = ibm_mod10(argv[position+1]))==VERIFIED)
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
  else if((position = checkArg("-createnumberMod10", argc, argv)))
  {    
       len = strlen(argv[position+1]);
       
       if(argv[position+1][len-1]=='*')
       { createNumMod10(argv[position+1],number);
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
            clearArr(number);
            createNumMod10(argv[position+1],number);
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
