#include "room.h"

int main() {
  Room forest, cave;
  init_room(&forest, "Forest", "A dark, dense forest.");
  init_room(&cave, "Cave", "A cold, damp cave.");

  forest.exits[0] = &cave; // forest -> N -> cave
  cave.exits[1] = &forest; // cave -> S -> forest
  print_room(&forest);

  return 0;
}
