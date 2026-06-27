#include <stdio.h>
#include <string.h>
#include "room.h"

int main() {
  Room forest, cave;
  init_room(&forest, "Forest", "A dark, dense forest.");
  init_room(&cave, "Cave", "A cold, damp cave.");

  forest.exits[0] = &cave; // forest -> N -> cave
  cave.exits[1] = &forest; // cave -> S -> forest
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
