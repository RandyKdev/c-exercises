// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/1/credit/

#include<stdio.h>
#include<math.h>

int getNumberInPosition(long int cardNumber, int position);
long int getSection(long int cardNumber, int position);
int addProductsDigits(int number);
int getNumberLength(long int cardNumber);

int main(void) {
    long int cardNumber;
    printf("Input Credit Card Number: ");
    scanf("%ld", &cardNumber);

    long int sumOfEveryOtherDigit = 0, sumOfEveryDigit = 0;
    int i = 1, j = 2, length = getNumberLength(cardNumber);
    
    while(i <= length || j <= length) {
        int temp1 = getNumberInPosition(cardNumber, i);
        int temp2 = getNumberInPosition(cardNumber, j);
    
        if(temp1 == -1) temp1 = 0;
        else if(temp2 == -1) temp2 = 0;
        
        sumOfEveryDigit += addProductsDigits(temp1);
        sumOfEveryOtherDigit += addProductsDigits(temp2 * 2);
        
        i+=2;
        j+=2;
    }

    long int sum = sumOfEveryOtherDigit + sumOfEveryDigit;

    if(sum % 10 != 0) {
        printf("INVALID\n");
        return 0;
    }
    
    int lastTwoDigits = (getNumberInPosition(cardNumber, length) * 10) + getNumberInPosition(cardNumber, length - 1);
    
    if(length == 15 && (lastTwoDigits == 34 || lastTwoDigits == 37))
        printf("AMEX\n");
    else if(length == 16 && (lastTwoDigits == 51 || lastTwoDigits == 52 || lastTwoDigits == 53 || lastTwoDigits == 54 || lastTwoDigits == 55))
        printf("MASTERCARD\n");
    else if((length == 13 || length == 16) && (getNumberInPosition(lastTwoDigits, 2) == 4))
        printf("VISA\n");
    else printf("INVALID\n");

    return 0;
}

int getNumberInPosition(long int cardNumber, int position) {
    if(position == 1) return getSection(cardNumber, position);
    if(getSection(cardNumber, position - 1) == cardNumber) return -1;
    return (getSection(cardNumber, position) -  getSection(cardNumber, position - 1)) / (long int)pow(10, position -1);
}

int addProductsDigits(int number) {
    int sum = 0, i = 0, temp;
    while((temp = getNumberInPosition(number, ++i)) != -1)
        sum += temp;    
    return sum;
}

int getNumberLength(long int cardNumber) {
    int length = 0;
    while(getNumberInPosition(cardNumber, ++length) != -1);
    return length - 1;
}

long int getSection(long int cardNumber, int position) {
    return (cardNumber % (long int)pow(10, (position)));
}