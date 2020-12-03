#ifndef MYBANK_H
#define MYBANK_H

int createAccount(double);

double getRemainder(int);

double deposit(int, double);

double pullMoney(int, double);

void closeAccount(int);

void interest(double);

void print();

int isOpen(int);

int validAccountNumber(int);

#endif // MYBANK_H