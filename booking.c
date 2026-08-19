#include <stdio.h> 
#include <string.h> 
#include "booking.h" 
#include "room.h" 
#include "room.c" 
int createBooking(struct Booking *bookings, int *bookingCount, int bookingCapacity,  
Room *rooms, int roomCount,struct Account *accounts, int accountCount,  
char *username, int roomID, int nights) { 
if (*bookingCount == bookingCapacity) { 
printf("Can't add more booking\n"); 
return 0 ;  
} 

Room *room = NULL ;  //temproom
room = searchRoomByID( rooms, roomCount, roomID); 
if (room == NULL) { 
  printf("Room not found!\n"); 
  return 0; 
 } 
  
 if (room->status != 'A') { 
   printf("Room is Not Available!\n"); 
  return 0; 
 } 
  
 if (nights <= 0) { 
  printf("Invalid number of nights!\n"); 
  return 0; 
 } 
  
 // Create new booking 
 struct Booking newBooking; 
 newBooking.bookingID = *bookingCount + 1; 
 strcpy(newBooking.username, username); 
 newBooking.roomID = roomID; 
 newBooking.nights = nights; 
 newBooking.totalCost = calculateTotalCost(room->price, nights); 
  

 *(bookings + *bookingCount) = newBooking; 
 ++*bookingCount; 
  
 // Update room status 
 updateRoomStatus(rooms, roomCount, roomID, 'O'); 
  
 // Update user's booking count 
 for (int i = 0; i < accountCount; i++) { 
  if (strcmp(accounts[i].username, username) == 0) { 
accounts[i].bookingCount++; 
break; 
  } 
 } 
  
 printf("Booking successful!\n"); 
 printf("Total cost: %.2f\n", newBooking.totalCost); 
 return 1; 
} 
// cancel booking 
int cancelBooking(struct Booking *bookings, int *bookingCount,  Room *rooms,  
int roomCount, struct Account *accounts, int accountCount, char *username,  
int bookingID) { 
  
 int found = -1; 
 int roomID = -1; 
  
 // Find booking 
 for (int i = 0; i < *bookingCount; i++) {
  if (bookings[i].bookingID == bookingID && strcmp(bookings[i].username, username) == 0) { 
found = i; 
roomID =bookings[i].roomID; 
break; 
  } 
 } 
  
 if (found == -1) { 
  printf("Booking not found or you don't have permission to cancel it!\n"); 
  return 0; 
 } 
  
 // Update room status 
 updateRoomStatus(rooms, roomCount, roomID, 'A'); 
  
 // Update user's booking count 
 for (int i = 0; i < accountCount; i++) { 
  if (strcmp(accounts[i].username, username) == 0) { 
accounts[i].bookingCount--; 
break; 
  } 
 } 
  
 // Remove booking by replace  
 --*bookingCount; 
 *(bookings+found) = *(bookings+ *bookingCount); 
 
  
 printf("Booking cancelled successfully!\n"); 
 return 1; 
} 
 
void printUserBookings(struct Booking *bookings, int bookingCount, char *username) { 
 int found = 0; 
  
 for (int i = 0; i < bookingCount; i++) { 
  if (strcmp(bookings[i].username, username) == 0) { 
if (!found) { 
    printf("\n Your Bookings:\n"); 
    printf("----------------------------------------\n"); 
    found = 1; 
} 
printf("Booking %d: Room %d, Nights %d, Cost %.2f\n", 
       bookings[i].bookingID, bookings[i].roomID, 
       bookings[i].nights, bookings[i].totalCost); 
  } 
 } 
  
 if (!found) { 
  printf("No bookings found.\n"); 
 } 
} 
 
float calculateTotalCost(float price, int nights) { 
 return price * nights; 
} 