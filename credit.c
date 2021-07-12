// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/1/credit/

#include<stdio.h>
#include<math.h>

long int getNumberInPosition(long int cardNumber, int position);
long int getSection(long int cardNumber, int position);

long int addProductsDigits(long int number) {
    int sum = 0;
    int i = 1;
    long int temp;
    while((temp = getNumberInPosition(number, i++)) != -1)
        sum += temp;
    
    return sum;
}
int main(void) {
    long int cardNumber;
    printf("Input Credit Card Number: ");
    scanf("%ld", &cardNumber);

    long int sumOfEveryOtherDigit = 0;
    long int sumOfeveryDigit = 0;
    int i = 1, j = 2;
    while(1) {
        long int temp1 = getNumberInPosition(cardNumber, i);
        long int temp2 = getNumberInPosition(cardNumber, j);
    
        if(temp1 == -1 && temp2 == -1) break;
        if(temp1 == -1) temp1 = 0;
        if(temp2 == -1) temp2 = 0;

        sumOfeveryDigit += addProductsDigits(temp1);
        sumOfEveryOtherDigit += addProductsDigits(temp2 * 2);
        printf("%ld\n", sumOfEveryOtherDigit);
        i+=2;
        j+=2;
    }

    long int sum = sumOfEveryOtherDigit + sumOfeveryDigit;
    printf("%ld", sum);

    return 0;
}

long int getNumberInPosition(long int cardNumber, int position) {
    if(position == 1) return getSection(cardNumber, position);
    if(getSection(cardNumber, position - 1) == cardNumber) return -1;
    return (getSection(cardNumber, position) -  getSection(cardNumber, position - 1)) / (long int)pow(10, position -1);
}

long int getSection(long int cardNumber, int position) {
    return (cardNumber % (long int)pow(10, (position)));
}