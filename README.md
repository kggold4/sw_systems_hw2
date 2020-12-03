# Assignments 2
## by Kfir Goldfarb
This assignments contains myBank.c file that implements the myBank.h header file functions,
The main program it is a bank accounts managment system,
The program gets from the user a single char that will execute one of this commands:

1. 'O' - Open Account: gets from the user amount and print the new account number
2. 'B' - Balance Inquiry: gets from the user account number and print the current balance
3. 'D' - Deposit: gets from the user account number and amount to deposit money to the account
4. 'W' - Withdrawal: gets from the user account number and amount to withdrawal money from the account
5. 'C' - Close Account: gets from the user account number to close the account
6. 'I' - Interest: gets from the user a interest rate value to interest all accounts that are open
7. 'P' - Print: print all the open accounts
8. 'E' - Exit: exit the program

* The program have a limit of 50 accounts and the range of the accounts numbers is from 901 to 950.

this program contains a Makefile with the commands:
1. all - compile entire program
2. clean - delete all .o .a .so .out and execute files