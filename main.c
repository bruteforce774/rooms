#include <stdio.h>
#include <string.h>
#include "room.h"

int main() {
  Room forest, cave, meadow, river, ruins;

  init_room(&forest, "Forest", "A dark, dense forest.");
  init_room(&cave, "Cave", "A cold, damp cave.");
  init_room(&meadow, "Meadow", "A wide open meadow with tall grass swaying in the breeze.");
  init_room(&ruins, "Ruins", "Ancient stone ruins, crumbling and covered in moss.");
  init_room(&river, "River", "A rushing river with cold, clear flowing water over smooth stones.");

  forest.exits[0] = &cave; // forest -> N -> cave
  forest.exits[1] = &meadow; // forest -> S -> meadow
  forest.exits[2] = &ruins; // forest -> E -> ruins
  forest.exits[3] = &river; // forest -> W -> river
  
  cave.exits[1] = &forest; // cave -> S -> forest
  meadow.exits[0] = &forest; // meadow -> N -> forest
  ruins.exits[3] = &forest; // ruins -> W -> forest
  river.exits[2] = &forest; // river -> E -> forest

  Room *current = &forest;
  
  while(1) {
    print_room(current);
    char input[50];
    printf("> ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';

    if(!strcmp(input, "quit")) break;

    if(!strcmp(input, "go north")) {
      if(current->exits[0]) current = current->exits[0];
      else printf("No exit that way.\n");
    }

    if(!strcmp(input, "go south")) {
      if(current->exits[1]) current = current->exits[1];
      else printf("No exit that way.\n");
    }

    if(!strcmp(input, "go east")) {
      if(current->exits[2]) current = current->exits[2];
      else printf("No exit that way.\n");
    }

    if(!strcmp(input, "go west")) {
      if(current->exits[3]) current = current->exits[3];
      else printf("No exit that way.\n");
    }
  }

  return 0;
}
