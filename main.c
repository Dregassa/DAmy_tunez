#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(){
  struct song_node ** table = calloc(sizeof(struct song_node *), 26);
  /*int i = 0;
  for (;i<26;i++){
  	table[i] = 0;
  }*/
  printf("%d", 'q' - 'a');
  add_song(table, "We Will Rock You", "queen");
  print_all(table);
  free(table);
}
