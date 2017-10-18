struct song_node{
	char name[256];
	char artist[256];
	struct song_node * next;
}

// begin denotes the beginning of the linked list

song_node * insert_front(song_node * begin, song_node newfront);

song_node * insert(song_node * begin, song_node newnode);//why do you need begin???

void print_list(song_node * begin);

song_node * find_song(song_node * begin, char * artist, char * song);

song_node * find_first_song(song_node * begin, char * artist);

song_node * random_node(song_node * begin);//why would you need any parameters here?

song_node * delete_node(song_node * begin);

void free_list(song_node * begin);//dont need parameters because it just frees up the list which is the array and theres only one array
		 //free_node is a different function we will define later 

		 /*we're not freeing the array here, we're freeing a linked list, which there are 26 of
		  However, you bring up a good point when we get to the array. The question I asked
		  dw was whether or not we should write our program to be able to support only one array
		  or mulitiple ones. He said that was up to us. so if we choose to make it so that there
		  is only one array, then for the array function in the playlist.h file we wouldn't need any parameters.
		  * */
