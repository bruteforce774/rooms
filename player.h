#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

typedef struct Player {
  char name[50];
  Item *inventory;
} Player;

#endif
