# Requirements
## Introduction
* The purpose of this project is to learn about some of the most common identification numbers and check digit algorithms involved in the verification of these identification     numbers. This project will not be covering all of the identification numbers as there are a lot many out there to be covered in this project.
* Many products that we use have an identification number that may or may not have a bar-code. Some examples are books, electronics, grocery items, credit cards, money orders,     driver’s license, etc. The identification number helps encode the information about the product. These numbers are usually separated by a space or a hyphen and each part holds   specific information about the product.

## Research
![Description](Link to Pic)
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

## Cost and Features
![Description](Link to Pic)
-- Content 
## Defining Our System
    -- TBD
## SWOT ANALYSIS
![SWOT-Sample](Link to Pic)

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
