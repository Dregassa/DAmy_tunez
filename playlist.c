void add_song(char *song, char *artist){
  int i	= artist[0] - 'a';
  struct song_node *begin = table[i];
  struct song_node *add;
  add->name = song;
  add->artist =	artist;
  insert(begin,add);
}



void print_songs(char *artist){
  int i = artist[0] - 'a';
  struct song_node * begin = table[i];
  while (begin){
    if (strcmp(begin->artist,artist)==0) printf("%s\n", begin->name);
  }
}


void print_letter(char *letter){
  int i = letter - 'a';
  struct song_node * begin = table[i];
  while (begin){
    printf("Artist: %s , Song: %s\n", begin->artist, begin->song);
    begin = negin->next;
  }
}


void print_all(){
  int i = 0;
  for (;i <26;i++){
    print_list(table[i]);
  }
}
