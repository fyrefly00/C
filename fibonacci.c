#include <stdio.h>

int recurse(int a) {
    if(a <=1) {
        return a;
    }
    else {
        return(recurse(a-1) + recurse(a-2));
    }
}

int main() {
    printf("Enter a value\n");
    int input;
    scanf("%d", &input);
    input --;
    printf("%d\n", recurse(input));
}

