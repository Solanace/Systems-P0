#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "linked_list.h"

int main() {
    printf("LINKED LIST TESTS\n");
    struct song_node *head = 0;
    
    printf("==========\nTesting insert_order:\n----------\n");
    char name[256] = "Electric Jazz";
    char artist[256] = "Bobert";
    head = insert_order(head, name, artist);
    strcpy(name, "Frank");
    strcpy(artist, "Budding Soldier");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    strcpy(name, "Fright for Late Night");
    strcpy(artist, "Budding Soldier");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    strcpy(name, "The Swallow");
    strcpy(artist, "Ballast");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    strcpy(name, "Sing Me a Song");
    strcpy(artist, "Zharnach");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    strcpy(name, "Jill's Jellies");
    strcpy(artist, "Bobert");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    strcpy(name, "My Mice");
    strcpy(artist, "Bobert");
    printf("Inserting %s -- \"%s\"\n", name, artist);
    head = insert_order(head, name, artist);
    
    printf("----------\nTesting print_list:\n----------\n");
    print_list(head);
    
    printf("----------\nTesting find_node and find_artist:\n----------\n");
    struct song_node *random = find_random_node(head);
    printf("Finding %s -- \"%s\" and printing nodes following it:\n", random->artist, random->name);
    print_list(find_node(head, random->name, random->artist));
    random = find_random_node(head);
    printf("Finding first node by %s and printing nodes following it:\n", random->artist);
    print_list(find_artist_node(head, random->artist));
    
    printf("----------\nTesting find_random_node:\n----------\n");
    print_node(find_random_node(head));
    print_node(find_random_node(head));
    print_node(find_random_node(head));
    
    printf("----------\nTesting remove_node:\n----------\n");
    random = find_random_node(head);
    printf("Removing %s -- \"%s\"\n", random->artist, random->name);
    head = remove_node(head, random->name, random->artist);
    printf("New node list:\n");
    print_list(head);
    
    printf("----------\nTesting free_list:\n----------\n");
    head = free_list(head);
    print_list(head);
    return 0;
}
