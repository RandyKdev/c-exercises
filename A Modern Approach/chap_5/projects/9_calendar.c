/**
 * @file 
 * @brief Finds the smaller dates of two dates 
 */

#include <stdio.h> // for IO operations

int main() {
    short unsigned int firstDay, firstMonth, secondDay, secondMonth;
    unsigned int firstYear, secondYear;
    unsigned int daysOfFirstDate, daysOfSecondDate;

    printf("Enter first date (mm/dd//yy): ");
    scanf("%hu/%hu/%u", &firstMonth, &firstDay, &firstYear);

    printf("Enter second date (mm/dd//yy): ");
    scanf("%hu/%hu/%u", &secondMonth, &secondDay, &secondYear);

    // Converting dates entered to days
    daysOfFirstDate = (firstYear * 365) + (firstMonth * 30) + firstDay;
    daysOfSecondDate = (secondYear * 365) + (secondMonth * 30) + secondDay;

    if(daysOfFirstDate < daysOfSecondDate)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", firstMonth, firstDay, firstYear, secondMonth, secondDay, secondYear);
    else if(daysOfFirstDate > daysOfSecondDate)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", secondMonth, secondDay, secondYear, firstMonth, firstDay, firstYear);
    else printf("The two dates are the same\n");

    return 0;
}