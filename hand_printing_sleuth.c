#include <string.h>
#include <stdio.h>

int integer_to_bin(int inVal) {
    int binNumber[8];
    int i = 0;
    while(inVal > 0) {
        printf("%d", inVal % 2);
        printf("\n");
        binNumber[i] = inVal % 2;
        inVal = inVal / 2;
        i ++;
    }
    i = 0;
    for(i = 0; i < 8; i ++) {
        printf("%d", binNumber[i]);
    }
}
int main () {
    char inputValues [1000];
    gets(inputValues);
    // printf(inputValues);
    char delim[] = ",";
    char* ptr;
    ptr = strtok(inputValues, delim);
    int bitmap[8][8];
    while(ptr != NULL) {
        printf("%s\n", ptr);
        ptr=strtok(NULL, delim);
        int val = (int) strtol(ptr, NULL, 2);
        printf(val);
        integer_to_bin(val);

    }
    // printf(ptr);
}

