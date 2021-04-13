/*
 *  main.c - command line frontend for CheckAlgo
 *
 *  Copyright (c) 2012  Shine Jayakumar (shine_hack@yahoo.com)
 *
 *  This file is part of CheckAlgo.
 *
 *  CheckAlgo is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your optionion) any later version.
 *
 *  CheckAlgo is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURpositionE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CheckAlgo.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkalgo.c"



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
       position = extractnumber(str,number);  //gets the numberber from the line read
       extractoptionion(str,option,position); //gets the optionion from the line read
      
       //IMEI
       if(strcmp("imei", option)==0)
       {
         if( (value = imei(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (IMEI) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (IMEI) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (IMEI): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (IMEI) - INvalueID LENGTH", number);
       }
       
       //ISSN
       else if(strcmp("issn", option)==0)
       {
         if( (value = issn(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISSN) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISSN) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISSN): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISSN) - INvalueID LENGTH", number);
       }
       
       //ISBN-10
       else if(strcmp("isbn10", option)==0)
       {
         if( (value = isbn_10(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-10) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-10) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-10): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-10) - INvalueID LENGTH", number);
       }
       
       //ISBN-13
       else if(strcmp("isbn13", option)==0)
       {
         if( (value = isbn_13(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ISBN-13) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ISBN-13) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-13): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ISBN-13) - INvalueID LENGTH", number);
       }
       
       //UPC
       else if(strcmp("upc", option)==0)
       {
         if( (value = upc_a(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (UPC) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (UPC) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (UPC): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (UPC) - INvalueID LENGTH", number);
       }
       
       //EAN
       else if(strcmp("ean", option)==0)
       {
         if( (value = ean(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (EAN) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (EAN) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (EAN): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (EAN) - INvalueID LENGTH", number);
       }
       
       //USPS Money Order
       else if(strcmp("uspsmo", option)==0)
       {
         if( (value = uspsmo(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (USPS MO) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (USPS MO) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (USPC MO): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (USPS MO) - INvalueID LENGTH", number);
       }
       
       //ROUTING numberber
       else if(strcmp("routing", option)==0)
       {
         if( (value = routing(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (ROUTING) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (ROUTING) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ROUTING): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (ROUTING) - INvalueID LENGTH", number);
       }
       
       //BANKD CARD
       else if(strcmp("bankcrd", option)==0)
       {
         if( (value = ibm_mod10(number)) == VERIFIED )
          sprintf(outputstring,"\n%s (BANK CARD) - valueID", number);
         else if(!value)
          sprintf(outputstring,"\n%s (BANK CARD) - INvalueID", number);
         else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (BANK CARD): checksum => %d\n",number,value);
         else
          sprintf(outputstring,"\n%s (BANK CARD) - INvalueID LENGTH", number);
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
       sprintf(outputstring,"\n%s (IMEI) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (IMEI) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
       sprintf(outputstring,"\n%s (IMEI): checksum => %d\n",argv[position+1],value);
    else 
      sprintf(outputstring,"\n%s (IMEI) - INvalueID LENGTH\n", argv[position+1]);
    if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
    printf("\n%s",outputstring);
    
  }
  
  //ISSN
  else if((position = checkArg("-issn", argc, argv)))
  { 
     if((value = issn(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISSN) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISSN) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISSN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISSN) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
   }
   
  //ROUTING
  else if((position = checkArg("-routing", argc, argv)))
  { 
     if((value = routing(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ROUTING) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ROUTING) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ROUTING): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ROUTING) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //ISBN-10
  else if((position = checkArg("-isbn10", argc, argv)))
  { 
     if((value = isbn_10(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISBN-10) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISBN-10) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN-10): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISBN-10) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //ISBN-13
  else if((position = checkArg("-isbn13", argc, argv)))
  { 
     if((value = isbn_13(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (ISBN-13) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (ISBN-13) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (ISBN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (ISBN-13) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //UPC
  else if((position = checkArg("-upc", argc, argv)))
  { 
     if((value = upc_a(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (UPC) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (UPC) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (UPC): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (UPC) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //EAN
  else if((position = checkArg("-ean", argc, argv)))
  { 
     if((value = ean(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (EAN) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (EAN) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (EAN): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (EAN) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
      {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  
  //USPS Money Order
  else if((position = checkArg("-uspsmo", argc, argv)))
  { 
     if((value = uspsmo(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (USPSMO) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (USPSMO) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (USPSMO): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (USPSMO) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
     {  fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //BANK CARD
  else if((position = checkArg("-bankcrd", argc, argv)))
  { 
     if((value = ibm_mod10(argv[position+1]))==VERIFIED)
       sprintf(outputstring,"\n%s (BANK CARD) -  valueID\n", argv[position+1]);
     else if(!value)
       sprintf(outputstring,"\n%s (BANK CARD) - INvalueID\n", argv[position+1]);
     else if(value>=1 && value <=9)
          sprintf(outputstring,"\n%s (BANK CARD): checksum => %d\n",argv[position+1],value);
     else 
       sprintf(outputstring,"\n%s (BANK CARD) - INvalueID LENGTH\n", argv[position+1]);
     if(outfile)
     { fprintf(ofile,"%s\n",outputstring);  fclose(ofile); }
     printf("\n%s",outputstring);
  }
  
  //-createMod10
  else if((position = checkArg("-createnumberMod10", argc, argv)))
  {    
       len = strlen(argv[position+1]);
       
       if(argv[position+1][len-1]=='*')
       { createnumberMod10(argv[position+1],number);
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
            createnumberMod10(argv[position+1],number);
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
