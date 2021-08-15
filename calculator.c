/**
 * @file
 * @brief A simple calculator
 */

#include <stdio.h>

void greet();
void showOptions();
int getOption();
void getOperands(double *a, double *b);
void printResult(int option, double a, double b);

int main() {
    greet(); // greets the user

    int option; // holds the option the user will choose
    double a, b; // a and b holds the 2 operands entered by the user

    // An infinite while loop
    while(1) {
        showOptions(); // show various options for math operations
        option = getOption(); // gets the user option
        
        // checks if the user decided to quit the program
        if(option == 5) break;

        getOperands(&a, &b); // gets the 2 operands from the user
        printResult(option, a, b); // prints the result of the operation

        // prints a divider
        printf("_____________________________________________________________________\n\n");
    }

    return 0;
}

/**
 * @brief Greets the user
 * @returns void
 */
void greet() {
    printf("Hello, I'm here to make your life easier\n\n");
}

/**
 * @brief Shows the various options to the user
 * @returns void
 */
void showOptions() {
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("\n");
}

/**
 * @brief Gets the user option
 * @returns option choosen by user
 */
int getOption() {
    int option;
    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &option);
    } while(option < 1 || option > 5);

    return option;
}

/**
 * @brief Gets the operands from the user
 * @param a the first operand
 * @param b the second operand
 * @returns void
 */
void getOperands(double *a, double *b) {
    printf("\nEnter any two numbers: ");
    scanf("%lf %lf", a, b);
}

/**
 * @brief Prints the result of the operation
 * @param option option chosen by the user
 * @param a the first operand
 * @param b the second operand
 * @returns void
 */
void printResult(int option, double a, double b) {
    printf("\nResult: ");

    if(option == 1) {
        printf("%lf\n", a + b);
    } else if(option == 2) {
        printf("%lf\n", a - b);
    } else if(option == 3) {
        printf("%lf\n", a * b);
    } else {
        if(b != 0) {
            printf("%lf\n", a / b);
        } else {
            printf("ERROR, divisor is zero (0)\n");
        }
    }
}