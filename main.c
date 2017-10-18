#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"

int main() {
    printf("Testing linked_list.c\n");
    struct song_node *head = 0;
    
    printf("Inserting songs:\n----------\n");
    char name[256] = "Electric Jazz";
    char artist[256] = "Bobert";
    head = insert_order(head, name, artist);
    strcpy(name, "Frank");
    strcpy(artist, "Budding Soldier");
    head = insert_order(head, name, artist);
    strcpy(name, "Fright for Late Night");
    strcpy(artist, "Budding Soldier");
    head = insert_order(head, name, artist);
    strcpy(name, "The Swallow");
    strcpy(artist, "Ballast");
    head = insert_order(head, name, artist);
    strcpy(name, "Sing Me a Song");
    strcpy(artist, "Zharnach");
    head = insert_order(head, name, artist);
    strcpy(name, "Jill's Jellies");
    strcpy(artist, "Bobert");
    head = insert_order(head, name, artist);
    strcpy(name, "My Mice");
    strcpy(artist, "Bobert");
    head = insert_order(head, name, artist);
    printf("----------\nPrinting list of songs:\n----------\n");
    print_list(head);
    printf("----------\nFinding songs and artists:\n----------\n");
    struct song_node *random = find_random_song(head);
    printf("Finding %s -- \"%s\" and printing songs following it:\n", random->artist, random->name);
    print_list(find_song(head, random->name, random->artist));
    random = find_random_song(head);
    printf("Finding first song by %s and printing songs following it:\n", random->artist);
    print_list(find_artist(head, random->artist));
    printf("----------\nShuffler enabled:\n----------\n");
    print_song(find_random_song(head));
    print_song(find_random_song(head));
    print_song(find_random_song(head));
    printf("----------\nRemoving songs:\n----------\n");
    random = find_random_song(head);
    printf("Removing %s -- \"%s\"\n", random->artist, random->name);
    head = remove_node(head, random->name, random->artist);
    printf("New song list:\n");
    print_list(head);
    printf("----------\nFreeing entire list:\n----------\n");
    head = free_list(head);
    print_list(head);
    return 0;
}
