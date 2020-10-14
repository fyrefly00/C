/**************************************************
 * hexor.c Author: Robert Walker
 * Purpose: XORs to hex strings
***************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Converts three digit hex string to integer
int hex_to_int(char* hexVal) {
    char result[100];
    unsigned int val = (int) strtol(hexVal, NULL, 16);
}

int main() {
    //Hex values to XOR
    char hexVal[1000] = "1c0111001f010100061a024b53535009181c";
    char xorVal[1000] = "686974207468652062756c6c277320657965";
    char ch[4];
    ch[3] = '\0'; //Put a null value at the end so that memcopy doesn't break
    char result[1000];
    result[0] = '\0';
    for(int i = 0; i < strlen(hexVal); i  ++) {
        if(i%3 == 0) { //Every three characters, send the substring to the sub function
            memcpy(ch, hexVal + i, 3);
            int val1 = hex_to_int(ch);
            memcpy(ch, xorVal+i, 3);
            int val2 = hex_to_int(ch);
            val1 = val1^val2; //XOR the two values
            char buff[100];
            sprintf(buff, "%x", val1);
            strcat(result, buff);
            // printf("%x", val1); //Print the value as hex
        }
     }
    printf(result);
    printf("\n");
}