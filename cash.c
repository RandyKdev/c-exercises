// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/1/cash/

#include<stdio.h>

int main(void) {
    float owed;
    do {
        printf("Enter the amount owed in dollars: ");
        scanf("%f", &owed);
    } while (owed < 0.0);

    int cents = (int) (owed * 100);
    int numberOfCoins = 0;

    while(cents > 0) {
        if(cents - 25 >= 0) cents -= 25;
        else if(cents - 10 >= 0) cents -= 10;
        else if(cents - 5 >= 0) cents -= 5;
        else cents -= 1;
        numberOfCoins++;
    }

    printf("Number of coins needed: %d\n", numberOfCoins);

    return 0;
}