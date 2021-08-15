#include <stdio.h>

int main() {
    double a, b;
    char operator;
    printf("Enter first operand: ");
    scanf("%lf", &a);
    printf("Enter operator: ");
    scanf(" %c", &operator);
    printf("Enter second operand: ");
    scanf("%lf", &b);

    if(operator == '+') {
        printf("The sum of the two numbers is %lf\n", a + b);
    } else if(operator == '-') {
        printf("The difference of the two numbers is %lf\n", a - b);    
    } else if(operator == '*') {
        printf("The product of the two numbers is %lf\n", a * b);
    } else if(operator == '/') {
        if(b != 0) {
            printf("The quotient of the two numbers is %lf\n", a / b);
        } else {
            printf("The divisor is equal to zero. ERROR!\n");
        }
    } else {
        printf("Enter a valid mathematical operator\n");
    }

    return 0;
}




/*
double add(double a, double b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double dividend, double divisor) {
    return dividend / divisor;
}

double subtract(double subtrahend, double subtractor) {
    return subtrahend - subtractor;
}

 double sum = add(a, b);
    double product = multiply(a, b);
    double quotient = divide(a, b);
    double difference = subtract(a, b);
*/