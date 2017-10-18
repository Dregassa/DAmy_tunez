struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
}

// begin denotes the beginning of the linked list

song_node * insert_front(song_node * begin, song_node newfront);

song_node * insert(song_node * begin, song_node newnode);//why do you need begin???

void print_list(song_node * begin);

song_node * find_artist(char* artist);

song_node * find_song(char* artist);

song_node * random_node(song_node * begin);//why would you need any parameters here?

song_node * delete_node(song_node * begin);

void free_list();//dont need parameters because it just frees up the list which is the array and theres only one array
		 //free_node is a different function we will define later 
