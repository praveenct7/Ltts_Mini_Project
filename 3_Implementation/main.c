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
#include <string.h>
#include "checkalgo.c"



int main(int argc, char *argv[])
{
  int  pos=0, val = 0, outputfile = 0, len, i;
  char fname[30], str[60],num[30],opt[30];
  char outstr[200], ch;
  
  FILE *ofile, *ifile; //read and write file handle
  
  
  if(argc<2)
  { usage(); return 1; }
  
  //Checks whether the -o option has been supplied
  if(pos = checkArg("-o", argc, argv))
  { 
    ofile = fopen(argv[pos+1],"w");
    if(ofile==NULL)
     printf("\nUnable to open file.\n");
    else
     outputfile=1;
    pos = 0;
  }
  
 
  //Check if the input is to be taken from a file
  if(pos = checkArg("-i", argc, argv))
   { 
     strcpy(fname, argv[pos+1]);
     
     if( (ifile = fopen(fname,"r")) == NULL)
      { printf("\nUnable to open file.\n"); return 2; }
     
     
     while(!feof(ifile))
     {
       fgets(str,30,ifile);        //reads a line from the file
       pos = extractNum(str,num);  //gets the number from the line read
       extractOption(str,opt,pos); //gets the option from the line read
      
       //IMEI
       if(strcmp("imei", opt)==0)
       {
         if( (val = imei(num)) == VERIFIED )
          sprintf(outstr,"\n%s (IMEI) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (IMEI) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (IMEI): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (IMEI) - INVALID LENGTH", num);
       }
       
       //ISSN
       else if(strcmp("issn", opt)==0)
       {
         if( (val = issn(num)) == VERIFIED )
          sprintf(outstr,"\n%s (ISSN) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (ISSN) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISSN): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (ISSN) - INVALID LENGTH", num);
       }
       
       //ISBN-10
       else if(strcmp("isbn10", opt)==0)
       {
         if( (val = isbn_10(num)) == VERIFIED )
          sprintf(outstr,"\n%s (ISBN-10) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (ISBN-10) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISBN-10): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (ISBN-10) - INVALID LENGTH", num);
       }
       
       //ISBN-13
       else if(strcmp("isbn13", opt)==0)
       {
         if( (val = isbn_13(num)) == VERIFIED )
          sprintf(outstr,"\n%s (ISBN-13) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (ISBN-13) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISBN-13): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (ISBN-13) - INVALID LENGTH", num);
       }
       
       //UPC
       else if(strcmp("upc", opt)==0)
       {
         if( (val = upc_a(num)) == VERIFIED )
          sprintf(outstr,"\n%s (UPC) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (UPC) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (UPC): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (UPC) - INVALID LENGTH", num);
       }
       
       //EAN
       else if(strcmp("ean", opt)==0)
       {
         if( (val = ean(num)) == VERIFIED )
          sprintf(outstr,"\n%s (EAN) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (EAN) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (EAN): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (EAN) - INVALID LENGTH", num);
       }
       
       //USPS Money Order
       else if(strcmp("uspsmo", opt)==0)
       {
         if( (val = uspsmo(num)) == VERIFIED )
          sprintf(outstr,"\n%s (USPS MO) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (USPS MO) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (USPC MO): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (USPS MO) - INVALID LENGTH", num);
       }
       
       //ROUTING number
       else if(strcmp("routing", opt)==0)
       {
         if( (val = routing(num)) == VERIFIED )
          sprintf(outstr,"\n%s (ROUTING) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (ROUTING) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ROUTING): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (ROUTING) - INVALID LENGTH", num);
       }
       
       //BANKD CARD
       else if(strcmp("bankcrd", opt)==0)
       {
         if( (val = ibm_mod10(num)) == VERIFIED )
          sprintf(outstr,"\n%s (BANK CARD) - VALID", num);
         else if(!val)
          sprintf(outstr,"\n%s (BANK CARD) - INVALID", num);
         else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (BANK CARD): checksum => %d\n",num,val);
         else
          sprintf(outstr,"\n%s (BANK CARD) - INVALID LENGTH", num);
       }
       
      
       if(outputfile)
        fprintf(ofile,"%s\n",outstr); //puts the output to the file
       
       printf("\n%s",outstr);   
       
       clearArr(str); clearArr(num); clearArr(opt);
       clearArr(outstr);
       
       pos=0;
     }
    
     fclose(ifile);
     
     if(outputfile) 
       fclose(ofile);
    }
     
  //VERSION
  else if(pos = checkArg("-version", argc, argv))
   {
     version(); pos = 0; return 2; 
   }
  
  
  //IMEI 
  else if((pos = checkArg("-imei", argc, argv)))
  {
     if((val = imei(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (IMEI) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (IMEI) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
       sprintf(outstr,"\n%s (IMEI): checksum => %d\n",argv[pos+1],val);
    else 
      sprintf(outstr,"\n%s (IMEI) - INVALID LENGTH\n", argv[pos+1]);
    if(outputfile)
     {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
    printf("\n%s",outstr);
    
  }
  
  //ISSN
  else if((pos = checkArg("-issn", argc, argv)))
  { 
     if((val = issn(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (ISSN) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (ISSN) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISSN): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (ISSN) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
   }
   
  //ROUTING
  else if((pos = checkArg("-routing", argc, argv)))
  { 
     if((val = routing(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (ROUTING) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (ROUTING) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ROUTING): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (ROUTING) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  
  //ISBN-10
  else if((pos = checkArg("-isbn10", argc, argv)))
  { 
     if((val = isbn_10(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (ISBN-10) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (ISBN-10) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISBN-10): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (ISBN-10) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  //ISBN-13
  else if((pos = checkArg("-isbn13", argc, argv)))
  { 
     if((val = isbn_13(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (ISBN-13) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (ISBN-13) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (ISBN): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (ISBN-13) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  
  //UPC
  else if((pos = checkArg("-upc", argc, argv)))
  { 
     if((val = upc_a(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (UPC) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (UPC) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (UPC): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (UPC) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  //EAN
  else if((pos = checkArg("-ean", argc, argv)))
  { 
     if((val = ean(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (EAN) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (EAN) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (EAN): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (EAN) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
      {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  
  //USPS Money Order
  else if((pos = checkArg("-uspsmo", argc, argv)))
  { 
     if((val = uspsmo(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (USPSMO) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (USPSMO) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (USPSMO): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (USPSMO) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
     {  fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  //BANK CARD
  else if((pos = checkArg("-bankcrd", argc, argv)))
  { 
     if((val = ibm_mod10(argv[pos+1]))==VERIFIED)
       sprintf(outstr,"\n%s (BANK CARD) -  VALID\n", argv[pos+1]);
     else if(!val)
       sprintf(outstr,"\n%s (BANK CARD) - INVALID\n", argv[pos+1]);
     else if(val>=1 && val <=9)
          sprintf(outstr,"\n%s (BANK CARD): checksum => %d\n",argv[pos+1],val);
     else 
       sprintf(outstr,"\n%s (BANK CARD) - INVALID LENGTH\n", argv[pos+1]);
     if(outputfile)
     { fprintf(ofile,"%s\n",outstr);  fclose(ofile); }
     printf("\n%s",outstr);
  }
  
  //-createMod10
  else if((pos = checkArg("-createNumMod10", argc, argv)))
  {    
       len = strlen(argv[pos+1]);
       
       if(argv[pos+1][len-1]=='*')
       { createNumMod10(argv[pos+1],num);
         printf("%s\n",num);
         if(outputfile)
         { fprintf(ofile,"\n%s",num); fclose(ofile); }
       }
       
       else
       { 
         printf("\n\nShowing first 10 combinations...\n\n");
         do
         {
           for(i=0; i<10; i++)
           {
            clearArr(num);
            createNumMod10(argv[pos+1],num);
            printf("\n%s",num);
            if(outputfile)
            { fprintf(ofile,"\n%s",num); }
           }
           printf("\n\nSee more combinations (Y/N)?\n\n"); 
           ch = getch();
         }while(ch=='y' || ch=='Y');
         
          if(outputfile)
           fclose(ofile);
       }
   }
  
  
  else 
   usage();
  
  
  return 0;
}
