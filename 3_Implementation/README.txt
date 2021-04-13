
CheckAlgo v.1.1

Checks various identification numbers for its validity.
Usage: checkalgo [options] number...

Options:
-help         Displays this screen.
-version      Displays the version and license information.
-imei         Checks an IMEI number for its validity (15 digits).
-issn         Checks an ISSN number for its validity (8 digits).
-bankcrd      Checks a bank card number (Credit, Debit or other bank cards).
-routing      Checks a Bank Routing number (9 digits).
-isbn10       Checks an ISBN (10 digits).
-isbn13       Checks an ISBN (13 digits).
-upc          Checks a UPC number (12 digits).
-ean          Checks an EAN number (13 digits).
-uspsmo       Checks a USPS money order number (12 digits).
-createMod10  Generates a valid number verified with mod10 algorithm.
-version      Displays the version.
-i            Reads the input from a file. Input file in Number,Type format.
              Ex: 5487934592459432,bankcrd. One entry per line.
-o            Puts the output into a file.

Example: checkalgo -imei 355340045855879
         checkalgo -isbn13 9780070635463 -o output.txt
         checkalgo -i input.txt -o output.txt




Generating a number verified with mod10 algorithm
===================================================

To generate a number verified with mod10 algorithm, type in the number in following format:

5482**22**222233 - Here the asterisk are those digits that are missing or the one that you're
		       not sure about.

So in this example : 

Example : checkalgo -createNumMod10 5497772206**45*0


Showing first 10 combinations...


5497772206234570
5497772206564570
5497772206334560
5497772206224530
5497772206574520
5497772206844550
5497772206284500
5497772206654520
5497772206614540
5497772206214580

See more combinations (Y/N)?


This applies to IMEI and some other type of identification numbers too. 
So, you can also use this option to create a valid IMEI number too.

----------------------------------------------------------------------------


Options for input file:

imei    - IMEI (15 digits)
issn    - ISSN (8 digits)
upc     - UPC (12 digits)
ean     - EAN (13 digits)
uspsmo  - USPS Money order
isbn10  - ISBN (10 digits)
isbn13  - ISBN (13 digits)
routing - ROUTING NUMBER
bankcrd - BANK CARD

Sample Input file:

5434872912349929,bankcrd
9781234582345,isbn13
0718345291,isbn10
335423492918472,imei

For any queries or suggestion, please email at shine_hack@yahoo.com.

