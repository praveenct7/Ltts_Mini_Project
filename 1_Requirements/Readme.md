# Requirements
## Introduction
* The aim of this project is to try some of the most used identification numbers and checking the digit algorithms which will be using in the verification of many identification   numbers.
* Many items that we use in our daily life have an identification number which may or may not have a bar-code. Some examples are money orders, books, driver’s license, grocery     items, credit cards, electronics, etc. This identification number helps to encode the information about the items which are listed. These identification numbers are generally   separated by a space or a hyphen and each part of the item holds specific information about the item.

# Detail requirements
## High Level Requirements:

| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | User shall be able to Validate a IMEI number | Techincal | IMPLEMENTED | 
| HR02 | User shall be able to validate a US Postal Money Order Number | Techincal |  IMPLEMENTED  |
| HR03 | User shall be able to Validate a Universal Product Code | Techincal |  IMPLEMENTED  |
| HR04 | User shall be able to Validate a International Standard Book Number | Techincal |  IMPLEMENTED  |
| HR05 | User shall be able to save the output in a file | Techincal |  IMPLEMENTED  |
| HR06 | User shall be able to read data from a file | Techincal |  IMPLEMENTED  |
| HR07 | Data should not be lost in case of faliure | Scenario | FUTURE |
| HR08 | Data should always be stored when closing the system | Scenario |  FUTURE |

##  Low level Requirements:
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR01 | Id should be unique and validated from persistant file or else ID should not be accepted. | HR01 |  IMPLEMENTED  |
| LR02 | Checks the number with mod9 and returns 1 if true and return 0 if invalid. If checksum is not provided and is replaced by *, then the calculated checksum is returned | HR02 |  IMPLEMENTED |
| LR03 | Checks the number and if the checkdigit (the last digit) is not supplied, and is replaced by *, then the checkdigit is calculated and returns the checksum | HR03 | IMPLEMENTED |
| LR04 | Check the number for validity for a 10 digit ISBN number. If the checksum is not provided in the string (the last digit), and is replaced by *, then the calculated checksum is retured. | HR04 |  IMPLEMENTED  |
| LR05 | User shall be able to save the files, if file already exists then it should append to file and should not overwrite it and if file does not exists then it should create a new file | HR05 |  IMPLEMENTED  |
| LR06 | If opening the file fails, then the system shloud prompt the message "Unable to access file" and should not end the program execution | HR05, HR06, HR07, HR08 | FUTURE |
| LR07 | When user Log off the system perform check and save data to file (1). If new data in inserted add it to file (2). If New data is not inserted do not add anything to file | HR08 |  FUTURE  |

