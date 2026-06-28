#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
  char name[50];
  struct Item* next;
} Item;

Item *create_item(const char *name);

#endif
