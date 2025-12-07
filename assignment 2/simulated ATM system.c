#include <stdio.h>

float balance = 0.0;

// Function to verify PIN
int login()
{
    int correctPIN = 1234;
    int enteredPIN;
    int attempts = 0;
    printf("Hello! Welcome to the ATM,\n ");

    while (attempts < 3) {
        printf("\nEnter your PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == correctPIN) {
            printf("Login process is successful!!\n");
            return 1;
        }
        attempts++;
        printf("You have entered the Incorrect pin. Attempts left: %d\n", 3 - attempts);
    }
    printf("Access denied. Too many failed attempts.\n");
    return 0;
}

// Function to show the ATM menu
void showMenu() {
    printf("\n--- ATM Menu ---\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

// Function to check balance
void checkBalance() {
    printf("Your current balance is: %.2f\n", balance);
}

// Function to deposit money
void deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        printf("Deposited: %.2f\n", amount);
        printf("Current balance is: %.2f\n", balance);
    } else {
        printf("Invalid deposit amount. Must be positive.\n");
    }
}

// Function to withdraw money
void withdraw(float amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount. Must be positive.\n");
    } else if (amount > balance) {
        printf("Insufficient funds. Withdrawal denied.\n");
    } else {
        balance -= amount;
        printf("Withdrawn: %.2f\n", amount);
        printf("Current balance is: %.2f\n", balance);
    }
}

// Main function
int main() {
    if (!login()) return 0;

    int choice;
    float amount;

    do {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(amount);
                break;
            case 4:
                printf("\nThank you for using the ATM.\nPleasure to serve you!!\n");
                break;
            default:
                printf("\nInvalid option.\nPlease try again.\n");
        }
    } while (choice != 4);

    return 0;
}
