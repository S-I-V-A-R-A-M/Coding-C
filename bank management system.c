#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100
#define ACCOUNT_NAME_LENGTH 50
#define ACCOUNT_TYPE_LENGTH 20
struct Account 
{
 char name[ACCOUNT_NAME_LENGTH];
 char type[ACCOUNT_TYPE_LENGTH];
 float balance;
};
int num_accounts = 0;
struct Account accounts[MAX_ACCOUNTS];
void add_account(char *name, char *type, float balance) 
{
 strcpy(accounts[num_accounts].name, name);
 strcpy(accounts[num_accounts].type, type);
 accounts[num_accounts].balance = balance;
 num_accounts++;
}
void deposit(char *name, float amount) 
{
 int i;
 for (i = 0; i < num_accounts; i++)
 {
 if (strcmp(accounts[i].name, name) == 0) 
{
 accounts[i].balance += amount;
 printf("Deposited %.2f to %s's account\n", amount, name);return;
 }
 }
 printf("Account not found\n");
}
void withdraw(char *name, float amount)
 {
 int i;
 for (i = 0; i < num_accounts; i++)
 {
 if (strcmp(accounts[i].name, name) == 0) {
 if (accounts[i].balance < amount) 
 {
 printf("Insufficient balance\n");
 return;
 }
 accounts[i].balance -= amount;
 printf("Withdrew %.2f from %s's account\n", amount, name);
 return;
 }
 }
 printf("Account not found\n");
}
void display_accounts() 
{
 int i;
 printf("\n");
 printf("Name\t\tType\t\tBalance\n");
 for (i = 0; i < num_accounts; i++)
 {
 printf("%s\t%s\t\t%.2f\n", accounts[i].name, accounts[i].type, accounts[i].balance);
}
}
int main() 
{
 add_account("John Doe", "Savings", 1000.00);
 add_account("Jane Doe", "Current", 500.00);
 add_account("Bob Smith", "Savings", 2000.00);
 display_accounts();
 deposit("John Doe", 100.00);
 withdraw("Jane Doe", 200.00);
 display_accounts();
 return 0;
} 