#ifndef ROOM_H
#define ROOM_H

#include "item.h"

typedef struct Room {
  char name[50];
  char description[200];
  struct Room *exits[4];
  Item *items;
} Room;

void init_room(Room *r, const char *name, const char *description);
void print_room(Room *r);
void add_item(Room *r, Item *item);

#endif
