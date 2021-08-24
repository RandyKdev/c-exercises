// link to problem statement 
// https://cs50.harvard.edu/x/2021/labs/1/population

#include<stdio.h>

int main(void) {
    int start_size;
    do{
        printf("Start size: ");
        scanf("%d", &start_size);
    }while(start_size < 9);
    
    int end_size;
    do {
        printf("End size: ");
        scanf("%d", &end_size);
    }while(end_size < start_size);

    int number_of_years = 0;
    int number_dead, number_born;
    while(start_size < end_size) {
        number_born = start_size / 3;
        number_dead = start_size / 4;
        start_size += number_born - number_dead;
        number_of_years++;
    } 

    printf("Years: %d\n", number_of_years);
    
    return 0;

}