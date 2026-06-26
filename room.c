#include <string.h>
#include "room.h"

void init_room(Room *r, const char *name, const char *description) {
  strcpy(r->name, name);
  strcpy(r->description, description);
  for(int i = 0; i < 4; i++) {
    r->exits[i] = NULL;
  } 
}
