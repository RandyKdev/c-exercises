/**
 * @file
 * @brief A simple calculator
 */

#include <stdio.h> // for IO operations

void greet(); // Greets the user
void showOptions(); // Shows available options 
int getOption(); // Gets user's option
void getOperands(double *a, double *b); // Gets operands from user
void printResult(int option, double a, double b); // Prints result

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
    // Prints greeting message to the user
    printf("Hello, I'm here to make your life easier\n\n");
}

/**
 * @brief Shows the various options to the user
 * @returns void
 */
void showOptions() {
    // Prints the options available to the user
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("\n"); // prints empty line for better visual clarity
}

/**
 * @brief Gets the user option
 * @returns option choosen by user
 */
int getOption() {
    int option; // holds option chooosen by the user

    // Makes sure user's option is valid
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
    // Gets the 2 operands from the user
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

    // Branching to execute correct operation
    if(option == 1) {
        printf("%lf\n", a + b);
    } else if(option == 2) {
        printf("%lf\n", a - b);
    } else if(option == 3) {
        printf("%lf\n", a * b);
    } else {
        if(b != 0) { // checks if divisor is zero
            printf("%lf\n", a / b);
        } else {
            printf("ERROR, divisor is zero (0)\n");
        }
    }
}