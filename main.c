#include <stdio.h>
#include <ctype.h>
#include "myBank.h"

// defines

// scan data types
#define PRINT_AMOUNT " %0.2f"    // print amount
#define SCAN_AMOUNT " %lf"       // scan amonut
#define SACN_CHAR " %c"          // scan char
#define SCAN_ID " %d"            // scan account number or integers

// numbers
#define RUN 1                    // run the while loop
#define STOP 0                   // stop the while loop
#define WAR -1                   // get warning from functions

// texts
#define AMOUNT "Please enter amount for deposit: "
#define FAILED_AMOUNT "Failed to read the amount\n"
#define ACCOUNT "Please enter account number: "
#define NEW_ACCOUNT "New account number is: %d \n"
#define FAILED_ACCOUNT "Failed to read the account number\n"
#define CLOSED "This account is closed\n"
#define BALANCE "The balance of account number %d is: %0.2f\n"
#define NEW_BALANCE "The new balance is: %0.2f\n"
#define WITHDRAW "Please enter the amount to withdraw: "
#define INTEREST "Please enter interest rate: "
#define FAILED_INTEREST "Failed to read the interest rate\n"
#define CANNOT_WITHDRAW "Cannot withdraw more than the balance\n"
#define INVALID "Invalid transaction type\n"

// main function
int main() {
    
    int execute = RUN;
    int account_number;
    double rate;
    double amount;
    char transaction = ' ';

    while (execute) {

        // getting transaction
        //transaction = ' ';
        printf("\nPlease choose a transaction type:");
        printf("\n O-Open Account");
        printf("\n B-Balance Inquiry");
        printf("\n D-Deposit");
        printf("\n W-Withdrawal");
        printf("\n C-Close Account");
        printf("\n I-Interest");
        printf("\n P-Print");
        printf("\n E-Exit\n");
        scanf(SACN_CHAR, &transaction);

        switch (transaction) {

        // create new account
        case 'O':
            
            // getting amount
            printf(AMOUNT);
            int b = scanf(SCAN_AMOUNT, &amount) == 1;

            // if amount is NaN
            if(!b) {
                    
                printf(FAILED_AMOUNT);

            // if amount is valid
            } else {
                
                // trying to create an account
                // can't create an account

                int param = createAccount(amount);

                if(param == WAR) {
                    printf("number of accounts are full");

                // create and account
                } else {
                    printf(NEW_ACCOUNT, param);
                }
            }
            break;

        // get remainder of an account
        case 'B':
            
            // getting account_number
            printf(ACCOUNT);
            scanf(SCAN_ID, &account_number);

            // checking if account_number is between 901 and 950
            if(validAccountNumber(account_number)) {

                // checking if the account number is open
                if(isOpen(account_number)) {
                    printf(BALANCE, account_number, getRemainder(account_number));

                // account number is closed
                } else {
                    printf(CLOSED);
                }

            // invalid account number input
            } else {
                printf(FAILED_ACCOUNT);
            }

            break;

        // deposit
        case 'D':

            // getting account_number
            printf(ACCOUNT);
            scanf(SCAN_ID, &account_number);

            // checking if account_number is between 901 and 950
            if(validAccountNumber(account_number)) {

                // checking if the account number is open
                if(isOpen(account_number)) {

                    // getting amount
                    printf(AMOUNT);
                    scanf(SCAN_AMOUNT, &amount);
                    printf(PRINT_AMOUNT, deposit(account_number, amount));

                // account number is closed
                } else {
                    printf(CLOSED);
                }

            // invalid account number input
            } else {
                printf(FAILED_ACCOUNT);
            }

            break;

        // pull money
        case 'W':

            // getting account_number
            printf(ACCOUNT);
            scanf(SCAN_ID, &account_number);

            // checking if account_number is between 901 and 950
            if(validAccountNumber(account_number)) {

                // checking if the account number is open
                if(isOpen(account_number)) {

                    // getting amount
                    printf(WITHDRAW);
                    scanf(SCAN_AMOUNT, &amount);

                    // checking if there is enough money in the account
                    // if there is
                    double param = pullMoney(account_number, amount);
                    if(param == WAR) {
                        printf(CANNOT_WITHDRAW);

                    // if there not
                    } else {
                        printf(NEW_BALANCE, param);
                    }

                // account number is closed
                } else {
                    printf(CLOSED);
                }

            // invalid account number input
            } else {
                printf(FAILED_ACCOUNT);
            }
            
            break;

        // close account
        case 'C':

            // getting account_number
            printf(ACCOUNT);
            scanf(SCAN_ID, &account_number);

            // checking if account_number is between 901 and 950
            if(validAccountNumber(account_number)) {

                // checking if the account number is open
                if(isOpen(account_number)) {

                   closeAccount(account_number);

                // account number is closed
                } else {
                    printf(CLOSED);
                }

            // invalid account number input
            } else {
                printf(FAILED_ACCOUNT);
            }
            
            break;

        // adding interest rate
        case 'I':
            
            // getting interest rate
            printf(INTEREST);
            int c = scanf(SCAN_AMOUNT, &rate) == 1;

            if(!c) {
                printf(FAILED_INTEREST);
            } else {
                interest(rate);
            }

            break;

        // print all open accounts and remainder
        case 'P':
            
            print();

            break;

        // close all accounts and exit program
        case 'E':

            execute = STOP;

            break;
        
        default:
            printf(INVALID);
        }

    }

    // end of program
    return STOP;
}