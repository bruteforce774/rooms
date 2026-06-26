#ifndef ROOM_H
#define ROOM_H

typedef struct Room {
  char name[50];
  char description[200];
  struct Room *exits[4];
} Room;

#endif
