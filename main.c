#include "room.h"

int main() {
  Room forest, cave;
  init_room(&forest, "Forest", "A dark, dense forest.");
  init_room(&cave, "Cave", "A cold, damp cave.");

  return 0;
}
