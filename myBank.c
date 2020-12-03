#include <stdio.h>
#include "myBank.h"

// defines
#define N 50        // number of account (rows)
#define COLS 2      // cols in the matrix
#define ID 901      // first id
#define LIMIT 950   // last id
#define DEFAULT 0   // col 0
#define RES 1       // col 1
#define WAR -1      // warning

// accounts matrix 50 x 2
double accounts[N][COLS] = {{DEFAULT}};

// counting the number of open accounts
int numberOfAccounts = DEFAULT;

// open new account
int createAccount(double amount) {

    // checking if there a free index in the matrix
    if(numberOfAccounts < N) {

        // finding close account
        int k = DEFAULT;
        for(int i = DEFAULT; i < N; i++) {
            if(accounts[i][DEFAULT] == DEFAULT) {
                k = i;
                break;
            }
        }
        
        // k is the new account index
        accounts[k][DEFAULT] = 1; // open = 1
        accounts[k][1] = amount; // amount
        numberOfAccounts++;
        
        return k + ID;

    // can't open new account
    } else {
        return WAR;
    }
}

// return the amount of an account
double getRemainder(int account_number) {
    return accounts[account_number - ID][1]; // retrun amount
}

// despoit amount to an account
double deposit(int account_number, double amount) {
    accounts[account_number - ID][1] += amount;

    // return the new amount
    return accounts[account_number - ID][1];
}

// pull money from an account
double pullMoney(int account_number, double amount) {

    // if the account do not have enough money
    if(accounts[account_number - ID][1] < amount) {
        return WAR;

    // substruct amount and return the new amount
    } else {
        accounts[account_number - ID][1] -= amount;
    return accounts[account_number - ID][1];
    }

}

// closing an account
void closeAccount(int account_number) {
    accounts[account_number - ID][DEFAULT] = DEFAULT;
    accounts[account_number - ID][1] = DEFAULT;
}

// interest by rate for all account
void interest(double rate) {
    for(int i = DEFAULT; i < N; i++) {
        if(accounts[i][DEFAULT] == 1) {
            accounts[i][1] *= (1 + rate / 100);
        }
    }

}

// prints all the open accounts
void print() {

    int count = ID;
    for (int i = DEFAULT; i < N; i++) {

        if(accounts[i][DEFAULT] == 1) {
            printf("The balance of account number %d is: %0.2f\n", count, accounts[i][1]);
        }
        count++;
    }

}

// checking if account is open or not
// return 1 if open else return 0
int isOpen(int account_number) {

    // account is open
    if(accounts[account_number - ID][DEFAULT] == 1) {
        return RES; 
    
    // account is closed
    } else {
        return DEFAULT;
    }
}

// checking if account number is valid and between 901 and 950
// return 1 if valid else return 0
int validAccountNumber(int account_number) {

    // valid
    if(account_number >= ID && account_number <= LIMIT) {
        return RES;

    // invalid
    } else {
        return DEFAULT;
    }

}