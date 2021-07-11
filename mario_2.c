// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/1/mario/more/

#include<stdio.h>

int main(void) {
    int height;
    do {
        printf("Height: ");
        scanf("%d", &height);
    } while(height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++) {
            if(j < height - i - 1) printf(" ");
            else printf("#");
        }

        printf("  ");

        for (int k = 0; k <= i; k++)
            printf("#");

        printf("\n");
    }
    
    return 0;
}