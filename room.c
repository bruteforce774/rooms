#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "room.h"

void to_lower(char *str) {
  for(int i = 0; str[i]; i++)
    str[i] = tolower(str[i]);
}

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

Item *take_item(Room *r, const char *name) {
  Item *current = r->items;
  Item *prev = NULL;

  while(current) {
    if(!strcmp(current->name, name)) {
      // found it
      if (!prev) r->items = current->next; // was first item
      else prev->next = current->next; // middle or last
      return current; // hand back to caller
    }
    prev = current;
    current = current->next;
  }
  return NULL; // not found
}
