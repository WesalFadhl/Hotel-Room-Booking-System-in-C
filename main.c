#include <stdio.h> 
#include <string.h> 
#include "room.h" 
#include "account.h" 
#include "account.c" 
#include "booking.h" 
#include "booking.c" 
#define ROOM_No 20 
#define ACCOUNT_No 20 
#define BOOKING_No 20 
int main() { 
Room rooms[ROOM_No] ; 
int roomCount = 3; 
struct Account accounts[ACCOUNT_No]; 
int accountCount = 0; 
struct Booking bookings[BOOKING_No]; 
int bookingCount = 0; 
// Initialize rooms 
initRooms(rooms); 
int currentUserIndex ; 
int choice; 
do { 
printf("\n=== Main Menu ===\n"); 
printf("1. Register\n"); 
printf("2. Login\n"); 
printf("3. Exit\n"); 
printf("Choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1:  // Register 
if (registerAccount(accounts, &accountCount , ACCOUNT_No)==0)  
printf(" Registration  faild\n");  
else 
printf("Registered successfully!\n"); 
break; //case1
case 2:  // Login 
char username[21], password[21]; 
printf("Username: "); 
scanf("%20s", username); 
printf("Password: "); 
scanf("%20s", password); 
currentUserIndex = login(accounts, accountCount, username, password); 
if (currentUserIndex == -1){  
printf("Login failed! Invalid credentials.\n"); 
break;  //case2
} 
printf("Welcome %s!\n", accounts[currentUserIndex].fullName); 
int ch2 ;  
do{  
printf("\n=== User Menu ===\n"); 
printf("1. View Rooms\n"); 
printf("2. Search by Type\n"); 
printf("3. Book Room\n"); 
printf("4. View My Bookings\n"); 
printf("5. Cancel Booking\n"); 
printf("6. Logout\n"); 
printf("Choice: "); 
scanf("%d", &ch2); 
switch (ch2) { 
case 1: // View Rooms 
printRooms(rooms, roomCount); 
break; //case1
case 2:  // Search by Type 
int type; 
printf("Enter type (0=STANDARD, 1=DELUXE, 2=SUITE): "); 
scanf("%d", &type); 
if (type >= 0 && type <= 2)  
searchRoomByType(rooms, roomCount, (enum RoomType)type); 
else  
printf("Invalid room type!\n"); 
break; //case2
case 3:  // Book Room 
int roomID, nights; 
printf("Enter Room ID to book: "); 
scanf("%d", &roomID); 
printf("Enter number of nights: "); 
scanf("%d", &nights); 
createBooking(bookings, &bookingCount, BOOKING_No, 
rooms, roomCount, accounts, accountCount, 
username, roomID, nights); 
break; //case3
case 4: // View My Bookings 
printUserBookings(bookings, bookingCount, username); 
break; //case4
case 5:  // Cancel Booking 
int bookingID; 
printf("Enter Booking ID to cancel: "); 
scanf("%d", &bookingID); 
cancelBooking(bookings, &bookingCount, rooms, roomCount, 
accounts, accountCount, username, bookingID); 
break; //case5
case 6: // Logout 
printf("Logged out.\n"); 
currentUserIndex = -1; 
break; //case6
default: 
printf("Invalid choice!\n"); 
}// end switch user menu 
}while(ch2 != 6 );  
break;  // end case login   // break of case 2 of Main menu 
case 3: // Exit 
printf("Exiting...\n"); 
break;  //case3
default: 
printf("Invalid choice!\n"); 
} 
}while(choice != 3 ) ;  
return 0; 
}// end main 