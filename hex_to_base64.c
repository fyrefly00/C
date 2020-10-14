/**************************************************
 * hex_to_base64.c Author: Robert Walker
 * Purpose: Converts a hex string to base64 
***************************************************/
#include <stdio.h>
#include <string.h>

//Compares the values to indexes in the reference string and prints them
void integer_to_base64(int intVal) {
    char alphabet[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char val[2];
    val[2] = "\0";
    memcpy(val, alphabet+intVal, 1);
    printf(val);
}

//Converts the hex value to an integer
void hex_to_int(char* hexVal) {
    char result[100];
    unsigned int val = (int) strtol(hexVal, NULL, 16);
    unsigned int val2 = 0b111111;
    unsigned int finalVal = val & val2; //Take the first half of the integer
    unsigned int finalVal2 = (val>>6)& val2; //Bitwise shift to get the second half
    integer_to_base64(finalVal2);
    integer_to_base64(finalVal);
}

//Main method. Handles breaking the hex string into three bit pieces and passing them along
int main () { 
    char hexVal[10000] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char ch[4];
    ch[3] = '\0'; //Put a null value at the end so that memcopy doesn't break
    for(int i = 0; i < strlen(hexVal); i  ++) {
        if(i%3 == 0) { //Every three characters, send the substring to the sub function
            memcpy(ch, hexVal + i, 3);
            hex_to_int(ch);
        }
     }
    printf("\n");
}