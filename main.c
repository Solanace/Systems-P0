#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

int main() {
    printf("Testing linked_list.c\n");
    struct song_node *head = 0;
    head = insert_front(head, "Electric Jazz", "Bobert");
    head = insert_front(head, "Potato", "Frank");
    print_list(head);
    return 0;
}
