#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "music_library.h"
#include "linked_list.h"

void *add_song(char name[], char artist[]) {
    srand(time(NULL));
    lowerfy(artist);
    //printf("%d", artist[0] - 97);
    table[artist[0] - 97] = insert_order(table[artist[0] - 97], name, artist);
}

struct song_node *find_song(char name[], char artist[]) {
    lowerfy(artist);
    return find_node(table[artist[0] - 97], name, artist);
}

struct song_node *find_artist(char artist[]) {
    lowerfy(artist);
    return find_artist_node(table[artist[0] - 97], artist);
}

void print_letter(char c) {
    printf("%c list\n", c);
    print_list(table[tolower(c) - 97]);
}

void print_artist(char artist[]) {
    lowerfy(artist);
    printf("%s: ", artist);
    struct song_node *head = find_artist(artist);
    while (head->next && !strcmp(artist, head->next->artist)) {
        printf("%s | ", head->name);
        head = head->next;
    }
    if (head && !strcmp(artist, head->artist)) printf("%s\n", head->name);
    else printf("\n");
}

void print_library() {
    int i;
    for (i = 0; i < 26; i ++) {
        if (table[i]) {
            print_letter(i + 97);
        }
    }
}

struct song_node *shuffle() {
    struct song_node *head = table[rand() % 26];
    if (head) return find_random_node(head);
    else return shuffle();
}

void delete_song(char name[], char artist[]) {
    lowerfy(artist);
    table[artist[0] - 97] = remove_node(table[artist[0] - 97], name, artist);
}

void delete_library() {
    int i;
    for (i = 0; i < 26; i ++) {
        table[i] = free_list(table[i]);
    }
}
