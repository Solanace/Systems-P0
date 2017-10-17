#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

struct song_node *insert_front(struct song_node *front, char[] name, char[] artist) {
    struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
    new->name = name;
    new->artist = artist;
    new->next = front;
    return new;
}

struct song_node *insert_order(struct song_node *front, char[] name, char[] artist) {
    /* Loop through the artist names. If the new song's artist already has songs in the
    linked list, loop through the song names too. */
    // base case, front is null
    if (!front) {
        return insert_front(front, name, artist);
    }
    // front is not null
    struct song_node *prev = front;
    struct song_node *next = front->next;
    // loop through authors, stop at the one before the new song's
    while (next && strcmp(artist, next->artist) > 0) {
        prev = prev->next;
        next = next->next;
    }
    // loop through songs if necessary
    if (!strcmp(artist, next->artist)) {
        while (next && strcmp(name, next->name) > 0) {
            prev = prev->next;
            next = next->next;
        }
    }
    
    prev->next = insert_front(next, name, artist);
    prev->next->next = next;
    return front;
}

void print_list(struct song_node *front) {
    printf("Printing songs:\n");
    while (front) {
        printf("\"%s\" by %s\n", front->name, front->artist);
        front = front->next;
    }
}

struct song_node *find_song(struct song_node *front, char[] name) {
    struct song_node *loop = front;
    while (loop && strcmp(name, loop->name)) {
        loop = loop->next;
    }
    return loop;
}

struct song_node *find_artist(struct song_node *front, char[] artist) {
    struct song_node *loop = front;
    while (loop && strcmp(artist, loop->artist)) {
        loop = loop->next;
    }
    return loop;
}

struct song_node *find_random_song(struct song_node *front) {
    if (!front) {
        return front;
    }
    
    srand(time(NULL));
    struct song_node *loop = front;
    int i = 0;
    while (loop) {
        i ++;
        loop = loop->next;
    }
    
    loop = front;
    int j = rand() % i;
    while (j) {
        j --;
        loop = loop->next;
    }
    return loop;
}

struct song_node *remove_node(struct song_node *front, char[] name) {
    if (!front) {
        return front;
    }
    
    if (!strcmp(name, front->name)) {
        struct song_node *new_front = front->next;
        free(front);
        return new_front;
    }
    
    struct song_node *loop = front;
    while (loop->next && strcmp(name, loop->next->name)) {
        loop = loop->next;
    }
    
    if (!loop->next) {
        return NULL;
    }
    
    struct song_node *temp = loop->next->next;
    free(loop->next);
    loop->next = temp;
    return front;
}

struct song_node *free_list(struct song_node *front) {
    struct song_node *loop = front;
    while (loop) {
        struct song_node *temp = loop->next;
        free(loop);
        loop = 0;
        loop = temp;
    }
    return front;
}
