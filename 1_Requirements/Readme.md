# Requirements
## Introduction
* The purpose of this project is to learn about some of the most common identification numbers and check digit algorithms involved in the verification of these identification     numbers. This project will not be covering all of the identification numbers as there are a lot many out there to be covered in this project.
* Many products that we use have an identification number that may or may not have a bar-code. Some examples are books, electronics, grocery items, credit cards, money orders,     driver’s license, etc. The identification number helps encode the information about the product. These numbers are usually separated by a space or a hyphen and each part holds   specific information about the product.

## Research

## Check Digits
A check digit is added to the identification number (usually the last digit). This digit is used to verify the identification number for its legitimacy. Check digit is added to the number to detect any errors made while typing the number into the system. The check digit is calculated with an algorithm. Some most common algorithms are mod9, mod10, and mod11. We will further notice that the mod10 algorithm is the most common and is used in most of the identification numbers.

Now will discuss some of the common identification numbers used.

## IMEI (International Mobile Equipment Identity) 
The IMEI number is a unique 15 digit number used to identify mobile phones as well as some of the satellite phones. The IMEI number can be found on the box in which the phone was packed, inside the phone in the battery compartment, and you can even find the IMEI by typing *#06# or *#0000# on some phones. The IMEI number is used by the GSM network to identify a valid device.

## Structure of IMEI
The IMEI number is a 15 digit number (14 digit plus the last digit which is the check digit). The IMEI contains the origin, model, and the serial number of the device plus the check digit for validation. The first eight digits, known as the TAC (Type Allocation Code), hold the information about the origin and model. The next six digits are the serial number defined by the manufacturer. The last digit is the check digit. Figure 1.1 illustrates the structure of an IMEI number.

## Calculation of the Check Digit
The check digit is calculated using the LUHN’s algorithm (mod10 algorithm). The LUHN’s algorithm was created by Hans Peter Luhn, a scientist at IBM. Here are the steps to calculate the check digit using mod10 algorithm:

## Starting from the right, double every second digit.
Add the digits together if the doubling gives you a two digit number.
Now add the doubled digits with the digits that were not doubled.
Divide the sum by 10 and check if the remainder is zero. If the remainder is zero then that is the check digit. If the number is not zero, then subtract the remainder from 10. The resulting number will be the check digit.

## Bank Card numbers
Bank card number are found on credit, debit, and other cards issued from the bank and some gift cards can also be verified with Luhn’s algorithm. The first digit of the card number is the Major Industry Identified (MII), which tells us which category of the entity issued the card. For example, if the number begins with 1 or 2, it’s issued by Airlines industry. If the number begins with 4, 5, or 6, it is issued by the financial and banking industry. The first six digits of the card number (including the MII) is known as the Issuer Identification number (IIN). Examples - 4 stands for Visa, 51 or 55 stand for MasterCard, and 34 or 37 for American Express. The numbers left are issued by the bank and the last digit is the check digit.

Verifying the card number using mod10 algorithm

## Routing Numbers
Routing number is a nine digit bank code designed to facilitate the sorting, bundling, and shipment of paper checks back to the drawer’s account. The RTN is also used by Federal Reserve Bank to process Fedwire fund transfers, and by the Automatic Clearing house to process direct deposits and other automatic transfers.

## Routing number format
Routing number appears in two formats: ) Fraction form and MICR (Magnetic ink character recognition) form. Both forms give the same information. Fraction form was used when MICR form was not invented, however it is still used as a backup.

MICR form: XXXXYYYYC
Here XXXX is the Federal Reserve Routing Symbol, YYYY is ABA Institution Identifier, and C is the check digit.

Calculation of the Check Digit
The check digit can be calculated by using this formula:

check digit (d9) = [7x(d1 + d4 + d7) + 3(d2 + d5+ d8) + 9(d3 + d6)] mod 10
et's calculate the check digit for this routing number: 2540 7011 6. Here, the check digit is 6. 
According to the formula, check digit (d9) = 7x(2+0+1) + 3x(5+7+1) + 9x(4+0)

=> 7x3 + 3x13 + 9x4 => 21 + 39 + 36 => 96. Now, 96 mod 10 => 6. Hence 6 is the check digit.

## USPS money order number
The US Postal office uses an identification number for postal orders. It’s an 11 digit number and the last number is the check digit as we have seen in other cases.

## Calculation of the check digit
To calculate the check digit, add up the first 10 digits and the sum is divided by 9. The remainder is the check digit. Let's calculate the check digit for 84310325021. Check digit => 8+4+2+1+0+3+2+5+0+2+1 => 28 mod 9 => 1. Hence 1 is the check digit.

## International Standard Book Number (ISBN)
This is a unique number created by Gordon Foster in 1961. The 10 digit format was developed by ISO (International Organization for Standardization). An ISBN is assigned to each edition of a book.

10 digit is assigned before Jan 1, 2007 and 13 digits is assigned after that.
Three parts:
the group identifier
the publisher code
the item number (title of the book).
Separated by spaces or hyphen.
Group Identifier: 1-5 digits (country, language).
The Publisher code: The national ISBN agency assigns the publisher number.
The publisher selects the item number.
Example: 9971-5-0210-0, 0-943396-04-2, 0-85131-041-9

## Calculation of the check digit
* ISBN check digit (10 digits) - mod11 algorithm
  The last digit in an ISBN is the check digit, must range from 0 to 10. The ISBN uses a weighted system of checking. Each digit from left to right is assigned a weight from ten   to one. Each digit is multiplied by its position weight and the resulting numbers are summed.

  Let's calculate the check digit for 0-07-063546-3.

  (0x1) + (0x2) + (7x3) + (0x4) + (6x5) + (3x6) + (5x7) + (4x8) + (6x9) => 190
  190mod11 => 3.
  Hence 3 is the check digit. Here is an illustration.
 
* ISBN check digit (13 digits)
  Each digit, starting from the left to right, is multiplied by 1 or 3 alternatively. The sum of the products modulo 10 gives us either zero or a number between 1 to 9. Subtract   the number from 10 and it gives us the checksum.

  978-0-07-063546-3
  1x9 + 3x7 + 1x8 + 3x0 + 1x0 + 3x7 + 1x0 + 3x6 + 1x3 + 3x5 + 1x4 + 3x6
  =>  9 + 21 + 8 + 21 + 18 + 3 + 15 + 4 + 18
  => 117 => 117 mod 10 => 7 => 10 – 7 => 3.
  Hence 3 is the check digit.
  
## ISSN (International Standard Serial Number)
An ISSN is a unique eight number used to identify a print or electronic periodical publication. The code format is divided by a hyphen into a four digit number. The last number is the check digit as in the other codes that we have covered.

## Calculation of the check digit
Starting from the left, each digit is multiplied by its position in the number. Add those numbers and the sum is divided by 11 (mod11). If the remainder is not zero, then the remainder is subtracted from 11 and that gives us the check digit. So for example, this number – 0378-5955.

Leave out the last digit because we want to verify this digit: 0x8 + 3x7 + 7x6 + 8x5 + 5x4 + 9x3 + 5x2 = >160 % 11 = 6.

Now because the remainder is a non-zero digit, we will subtract it from 11 to get the check digit, so 11 - 6 => 5. Hence the check digit is 5.

## UPC and EAN
The UPC (Universal Product Code) is a barcode symbol and is used to track trade items in stores. The most common form of UPC is the UPC-A which consists of 12 digits which is unique for a trade item. It consists of a strip of black and white spaces which can be scanned. The area that can be scanned in a UPC-A follows this pattern:

SLLLLLLLMRRRRRRE
Here S -> Start, M -> Middle and E -> End
L -> Left and R -> Right make the barcode unique. The last digit in the barcode is the check digit.
Calculation and Verification of the check digit
Verification: To verify the number, we can use this formula:

[3.d1 + 1.d2 + 3.d3 + 1.d4 + 3.d5 + 1.d6 + 3.d7 + 1.d8 + 3.d9 + 1.d10 + 3.d11 + 1.d12] mod10 = 0
Here d1, d2, d3...etc. are the digits. Starting from the left, we multiply the digits with 3 and 1 alternatively.

Example: 036000 291452

3x0 + 1x3 + 3x6 + 1x0 + 3x0 + 1x0 + 3x2 + 1x9 + 3x1 + 1x4 + 3x5 + 1x2
=> 0+3+18+0+0+0+9+3+4+15+2 => 60 => 60mod10 => 0.
Hence the number is verified:

Calculation: To calculate the check digit, we use the same formula but subtract the remainder from 10 to get the check digit.
Example: 036000 29145?

3x0 + 1x3 + 3x6 + 1x0 + 3x0 + 1x0 + 3x2 + 1x9 + 3x1 + 1x4 + 3x5 + x
=>  0+3+18+0+0+0+9+3+4+15+x => 58 => 58mod10 => 8
10 - 8 => 2
Hence 2 is the check digit.

## EAN
The EAN-13 (European Article Number) is a 13 digit barcode which is a superset of the UPC (12 digits), and is used worldwide for marking products sold at retail points of sale (POS). EAN also indicates the country in which the company who sells the product is based in.

## Calculation of the check digit
Verification: To verify the number, multiply the digits with 1 or 3 with respect to the position they have in the digits, starting from the left.

Example: 8 901526 206056

1x8 + 3x9 + 1x0 + 3x1 + 1x5 + 3x2 + 1x6 + 3x2 + 1x0 + 3x6 + 1x0 + 3x5+ 1x6
=> 8 + 27 + 3 + 5 + 6 + 6 + 6 + 18 + 15 + 6 => 100 mod10 => 0. Hence number is verified
Calculation: We use the same method as above, however we will omit the last digit from the calculation because that is the digit we want to find. Here if the remainder is a non-zero number then it is subtracted from 10.

Example: 8 901526 206056

1x8 + 3x9 + 1x0 + 3x1 + 1x5 + 3x2 + 1x6 + 3x2 + 1x0 + 3x6 + 1x0 + 3x5
=> 8 + 27 + 3 + 5 + 6 + 6 + 6 + 18 + 15 => 94 mod10 => 6. 10 - 4 = > 6.
Hence 6 is the check digit.

## SWOT ANALYSIS
https://imagizer.imageshack.com/img924/7008/GXxQZw.png

# 4W&#39;s and 1&#39;H

## Who:

**TBD**

## What:

**TBD**

## When:

**TBD**

## Where:

**TBD**

## How:

**TBD**

# Detail requirements
## High Level Requirements:
--- TBD in Tabular Format 
-- ID | Description | Status (Implemented/Future)


##  Low level Requirements:
--- TBD in Tabular Format 
-- ID | Description | Status (Implemented/Future)
