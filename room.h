#ifndef _ROOM_H 
#define _ROOM_H 
//===============

enum RoomType{ 
STANDARD, 
DELUXE, 
SUITE 
} ; 
typedef struct  { 
int roomID; 
enum  RoomType roomType; 
int capacity; 
float price; 
char status; 
char amenities[3][20];   
int amenityCount; 
} Room; 
void initRooms( Room* rooms ); 
void printRooms( Room *rooms, int roomCount); 
Room* searchRoomByID( Room* rooms, int roomCount, int roomID); 
void searchRoomByType( Room* rooms, int roomCount, enum RoomType type); 
void updateRoomStatus( Room* rooms, int roomCount, int roomID, char status); 
#endif