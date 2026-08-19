#include <stdio.h> 
#include <string.h> 
#include "room.h" 
void initRooms( Room* rooms ) { 
// Room 101 
rooms[0].roomID = 101; 
rooms[0].roomType = STANDARD; 
rooms[0].capacity = 2; 
rooms[0].price = 100.00; 
rooms[0].status = 'A'; 
strcpy(rooms[0].amenities[0], "WiFi"); 
strcpy(rooms[0].amenities[1], "TV"); 
rooms[0].amenityCount = 2; 
// Room 201 
rooms[1].roomID = 201; 
rooms[1].roomType = DELUXE; 
rooms[1].capacity = 3; 
rooms[1].price = 200.00; 
 rooms[1].status = 'A'; 
 strcpy(rooms[1].amenities[0], "WiFi"); 
 strcpy(rooms[1].amenities[1], "MiniBar"); 
 rooms[1].amenityCount = 2; 
  
 
  
 // Room 301 
rooms[2].roomID = 301; 
 rooms[2].roomType = SUITE; 
 rooms[2].capacity = 4; 
 rooms[2].price = 350.00; 
 rooms[2].status = 'A'; 
 strcpy(rooms[2].amenities[0], "WiFi"); 
 strcpy(rooms[2].amenities[1], "TV"); 
 strcpy(rooms[2].amenities[2], "MiniBar"); 
rooms[2].amenityCount = 3; 
  
} 
 
void printRooms( Room* rooms, int roomCount) { 
 printf("\n%-5s %-10s %-5s %-10s %-7s %s\n",  
  "ID", "Type", "Cap", "Price", "Status", "Amenities"); 
 printf("------------------------------------------------------------\n"); 
  
 for (int i = 0; i < roomCount; i++) { 
  const char *type; 
  switch (rooms[i].roomType) { 
case STANDARD: type= "STANDARD"; break; 
case DELUXE:  type= "DELUXE"; break; 
case SUITE: type= "SUITE"; break; 
default:    type="unknown"; break;
  } 

  printf("%-5d %-10s %-5d %-10.2f %-7c ", 
rooms[i].roomID, type, rooms[i].capacity, 
rooms[i].price, rooms[i].status); 
 
for(int j = 0 ;j <rooms[i].amenityCount ; j++)  
printf("%s  , " , rooms[i].amenities[j]  ); 
printf("\n");  
 } 
} //End printRooms
 
 Room* searchRoomByID( Room *rooms, int roomCount, int roomID) { 
 for (int i = 0; i < roomCount; i++) { 
  if (rooms[i].roomID == roomID) { 
return &rooms[i]; 
  } 
 } 
 return NULL; 
} // End searchRoomByID
 
void searchRoomByType( Room* rooms, int roomCount, enum RoomType type) { 
 printf("\n%-5s %-10s %-5s %-10s %-7s %s\n",  
  "ID", "Type", "Cap", "Price", "Status", "Amenities"); 
 printf("------------------------------------------------------------\n"); 
  
 for (int i = 0; i < roomCount; i++) { 
  if (rooms[i].roomType == type) { 
  const char *typeStr; 
switch (rooms[i].roomType) { 
 case STANDARD:
 typeStr= "STANDARD"; 
 break; 
 case DELUXE:
 typeStr= "DELUXE";
 break; 
 case SUITE:
 typeStr= "SUITE";
 break; 
 default:
 typeStr="unknwon";
  break;
} 
 
char amenitiesStr[100] = ""; 
for (int j = 0; j < rooms[i].amenityCount; j++) { 
 strcat(amenitiesStr, rooms[i].amenities[j]); 
 if (j < rooms[i].amenityCount - 1) { 
  strcat(amenitiesStr, ", "); 
 } 
} 
 
printf("%-5d %-10s %-5d %-10.2f %-7c %s\n", 
 rooms[i].roomID, typeStr, rooms[i].capacity, 
 rooms[i].price, rooms[i].status, amenitiesStr); 
  } 
 } 
} // End searchRoomByType
 
void updateRoomStatus( Room* rooms, int roomCount, int roomID, char s) { 
  Room* room = searchRoomByID(rooms, roomCount, roomID); 
 if (room != NULL) { 
  room->status = s; 
 } 
 else 
 printf("Room with ID %d not found!\n" , roomID);
} //updateRoomStatus 