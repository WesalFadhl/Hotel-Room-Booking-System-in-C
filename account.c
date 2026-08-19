#include <stdio.h> 
#include <string.h> 
#include "account.h" 
 //====================================================
int registerAccount(struct Account *accounts, int *accountCount, int capacity) { // we can change srructt==================
  if (*accountCount >= capacity) { 
  printf("list is full. \n"); 
  return 0 ;  
  } 
  
 struct Account temp; 
 printf("Username: "); 
 scanf("%20s", temp.username); 
  
 // Check for duplicate username 
 for (int i = 0; i < *accountCount; i++)  
  if (strcmp(accounts[i].username, temp.username) == 0) { 
printf("Username already exists!\n"); 
return 0; 
  } 
  
  
 printf("Password: "); 
 scanf("%20s", temp.password); 
  
 printf("Full Name: "); 
 scanf(" %[^\n]", temp.fullName); 
  
 printf("Age: "); 
 scanf("%d", &temp.age); 
  
 if (temp.age < 18) { 
  printf("Registration failed! Must be 18 years or older.\n"); 
  return 0; 
 } 
  
 temp.bookingCount = 0; 
 *(accounts+ *accountCount) = temp; 
 ++*accountCount; 
  return 1; 
} 
 
int login(struct Account *accounts, int accountCount, char *username, char *password) { 
 for (int i = 0; i < accountCount; i++)  
  if (strcmp(accounts[i].username, username) == 0 &&strcmp(accounts[i].password, password) == 0) { 
return i; 
  } 
  
 return -1; 
} 
