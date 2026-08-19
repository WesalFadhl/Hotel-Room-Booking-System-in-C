#ifndef _BOOKING_H 
#define _BOOKING_H 
#include "account.h" 
#include "room.h" 
struct Booking { 
int bookingID; 
char username[21];// 20 for username +1 for '\0' at the end 
int roomID; 
int nights; 
float totalCost; 
} ; 
int createBooking(struct Booking *bookings, int *bookingCount, int bookingCapacity,  
Room *rooms, int roomCount, struct Account *accounts, int accountCount,  
char *username, int roomID, int nights); 
int cancelBooking(struct Booking *bookings, int *bookingCount,  Room *rooms, int 
roomCount,  
struct Account *accounts, int accountCount, char *username, int bookingID); 
void printUserBookings(struct Booking *bookings, int bookingCount, char *username); 
float calculateTotalCost(float price, int nights); 
#endif 