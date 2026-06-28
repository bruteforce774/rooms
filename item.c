#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item *create_item(const char *name) {
  Item *item = malloc(sizeof(Item));
  if(item == NULL) {
    printf("Could not allocate memory.\n");
    return NULL;
  }
  strcpy(item->name, name);
  item->next = NULL;
  return item;
}
