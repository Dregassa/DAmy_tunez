#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(){
  struct song_node ** table = calloc(sizeof(struct song_node *), 26);

  add_song(table, "We Will Rock You", "queen");
  add_song(table, "thriller", "michael jackson");
  add_song(table, "the way you make me feel", "michael jackson");
  
  
  printf("---------\n");
  printf("add_song\n");
  print_all(table);
  
  printf("---------\n");
  printf("find_artist\n");
  print_list(find_artist(table, "michael jackson"));
  
  printf("---------\n");
  printf("find_in_table\n");
  print_list(find_in_table(table,"michael jackson", "thriller"));
  

  printf("---------\n");
  printf("remove_song\n");
  remove_song(table, "michael jackson", "thriller");
  print_all(table);
  add_song(table, "trash", "justin beiber"); //just kidding!
  //print_all(table);
  
  printf("---------\n");
  printf("shuffle\n");
  shuffle(table, 3);
  
  add_song(table, "cant stop the feeling", "justin timberlake");

  printf("---------\n");
  printf("print_songs\n");
  
  print_songs(table,"justin beiber");

  printf("---------\n");
  printf("print_letter\n");
  
  print_letter(table,"j");


  remove_all(table);
  printf("---------\n");
  printf("Printing after free\n");
  print_all(table);

  //add_song(table, "can't stop the feeling", "justin timberlake");

  //print_songs(table,"justin beiber");
  //print_letter(table,"j");
  free(table);
}
