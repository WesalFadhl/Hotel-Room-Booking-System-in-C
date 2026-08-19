#ifndef _ACCOUNT_H 
#define _ACCOUNT_H 
 //===================================
 struct Account { 
 char username[21]; // 20 for username +1 for '\0' at the end
 char password[21]; // 20 for password +1 for '\0' at the end
 char fullName[41]; // 40 for fullName +1 for '\0' at the end
 int age; 
 int bookingCount; 
} ; 
 
int registerAccount(struct Account *accounts, int *accountCount, int capacity); 
int login(struct Account *accounts, int accountCount, char *username, char *password); 
 
#endif