#include<stdio.h>
#include<stdbool.h>

int main() {
    int firstDay, firstMonth, firstYear;
    int secondDay, secondMonth, secondYear;
    int daysOfFirstDate, daysOfSecondDate;

    printf("Enter first date (mm/dd//yy): ");
    scanf("%d/%d/%d", &firstMonth, &firstDay, &firstYear);

    printf("Enter second date (mm/dd//yy): ");
    scanf("%d/%d/%d", &secondMonth, &secondDay, &secondYear);

    daysOfFirstDate = (firstYear * 365) + (firstMonth * 30) + firstDay;
    daysOfSecondDate = (secondYear * 365) + (secondMonth * 30) + secondDay;

    if(daysOfFirstDate < daysOfSecondDate)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", firstMonth, firstDay, firstYear, secondMonth, secondDay, secondYear);
    else if(daysOfFirstDate > daysOfSecondDate)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", secondMonth, secondDay, secondYear, firstMonth, firstDay, firstYear);
    else printf("The two dates are the same\n");

    return 0;
}