struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
}

// begin denotes the beginning of the linked list

song_node * insert_front(song_node * begin, song_node newfront);

song_node * insert(song_node * begin, song_node newnode);

void print_list(song_node * begin);

song_node * find_artist(song_node * begin, char* artist);

song_node * find_song(song_node * begin, char* artist);

song_node * random_node(song_node * begin);

song_node * delete_node(song_node * begin);

void free_list(song_node * begin);
