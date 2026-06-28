#include <stdio.h>
#include <string.h>
#include "room.h"

void init_room(Room *r, const char *name, const char *description) {
  strcpy(r->name, name);
  strcpy(r->description, description);
  for(int i = 0; i < 4; i++) {
    r->exits[i] = NULL;
  }
  r->items = NULL;
}

void print_room(Room *r) {
  printf("%s\n", r->name);
  printf("%s\n", r->description);
  const char *directions[4] = {"North", "South", "East", "West"};
  for(int i = 0; i < 4; i++) {
    if(r->exits[i]) printf("Exit: %s\n", directions[i]);
  }
  Item *i = r->items;
  while(i) {
    printf("Item: %s\n", i->name);
    i = i->next;
  }
}

void add_item(Room *r, Item *item) {
  item->next = r->items;
  r->items = item;
}
