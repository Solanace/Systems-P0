#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "music_library.h"
#include "linked_list.c"

void *add_song(char name[], char artist[]) {
    lowerfy(name);
    lowerfy(artist);
    return insert_order(table[artist[0] - 97], name, artist);
}

struct song_node *find_song(char name[], char artist[]) {
    lowerfy(name);
    lowerfy(artist);
    return insert_order(table[artist[0] - 97], name, artist);
}
struct song_node *find_artist(char artist[]);
void print_letter(char c);
void print_artist(char artist[]);
void print_library();
void shuffle();
void delete_song(char name[], char artist[]);
void delete_library();
