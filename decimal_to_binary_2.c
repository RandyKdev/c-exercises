#include<stdio.h>
#include<assert.h>

void decimalToBinary(int);

void test() {
    
}

int main(void) {
    int decimal;
    printf("Enter the decimal to convert to binary: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    
    return 0;
}

void decimalToBinary(int decimal) {
    int number_of_bits = sizeof(int) * 8;
    int temp;
    int flag = 0;
    for(number_of_bits--; number_of_bits >= 0; number_of_bits--) {
        temp = decimal >> number_of_bits;
        if(temp & 1) {
            flag = 1;
            printf("1");
        }
        else if(flag) printf("0");
    }
    printf("\n");
}