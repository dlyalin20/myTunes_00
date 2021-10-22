#include "lists.h"

// Creates and returns a single song
struct song_node * create_song(char *artist, char *name) {
    struct song_node *node = calloc(1, sizeof(struct song_node));

    node->artist = artist;
    node->name = name;
    node->next = NULL;

    return node;
}

// Inserts a song to the front of the linked list
struct song_node * insert_front(struct song_node *front, char *name, char *artist) {
    struct song_node *node = create_song(name, artist);
    node->next = front;
    return node;
}

// Returns 1 (true) if b comes before a, else 0 (false)
int comes_before(struct song_node *a, struct song_node *b) {
    if (strcasecmp(a->artist, b->artist) >= 0 && strcasecmp(a->name, b->name)) return 1;
    else return 0;
}

// Helper to insert to avoid redundancy
struct song_node * insert_helper(struct song_node *front, struct song_node *node) {
    if (front == NULL) {
        return node;
    }
    if (comes_before(front, node)) {
        node->next = front;
        return node;
    }
    struct song_node *tmp = front;
    while (tmp->next) {
        if (comes_before(tmp->next, node)) {
            node->next = tmp->next;
            tmp->next = node;
            return front;
        }
        else tmp = tmp->next;
    }
    tmp->next = node;
    return front;
}

// Inserts song into linked list alphabetically, by artist then by song
// Takes as argument front of list and song node to insert
// Returns front of list
struct song_node * insert_song(struct song_node *front, char *artist, char *name) {
    struct song_node *node = create_song(artist, name);
    front = insert_helper(front, node);
    return front;
}

// Prints individual song
void print_song(struct song_node *node) {
    if (node)
        printf("%s: %s | ", node->artist, node->name);
}

// Prints list of songs
void print_list(struct song_node *front) {
    while (front) {
        print_song(front);
        front = front->next;
    }
    printf("\n");
}

// Returns true if node contains given data
int songs_equal(struct song_node *a, char *artist, char *name) {
    return !strcasecmp(a->artist, artist) && !strcasecmp(a->name, name);
}

// finds a given node in the list
struct song_node * find_node(struct song_node *front, char *artist, char *name) {
    printf("looking for [%s: %s]\n", artist, name);
    while (front) {
        if (songs_equal(front, artist, name)) {
            printf("\tsong found!\t");
            print_song(front);
            printf("\n");
            return front;
        }
        else front = front->next;
    }
    printf("\tsong not found\n");
    return NULL;
}

// finds first song by a given artist in the list
struct song_node * find_artist(struct song_node *front, char *artist) {
    printf("looking for %s\n", artist);
    while (front) {
        if (!(strcasecmp(front->artist, artist))) {
            printf("\tartist found! \t");
            print_song(front);
            printf("\n");
            return front;
        }
        else front = front->next;
    }
    printf("\tartist not found\n");
    return NULL;
}

// Returns random song node from linked list
struct song_node * random_song(struct song_node *front) {
    int counter;
    struct song_node *tmp = front;
    for (counter = 2; front; counter++) {
        if (!(rand() % counter)) {
            tmp = front;
        }
        front = front->next;
    }
    print_song(tmp);
    return tmp;
}

// Removes node with specified data from list
struct song_node * remove_song(struct song_node *front, char *artist, char *name) {
    printf("Removing [%s: %s]\n", artist, name);
    if (!front) return front;
    if (songs_equal(front, artist, name)) {
        return front->next;
    }
    struct song_node *tmp = front;
    while (tmp->next) {
        if (songs_equal(tmp->next, artist, name)) {
            tmp->next = tmp->next->next;
            return front;
        }
        else tmp = tmp->next;
    }
    printf("%s - %s not found\n", artist, name);
    return front;
}

struct song_node * free_list(struct song_node *front) {
    struct song_node *tmp;
    while (front != NULL) {
        tmp = front;
        front = front->next;
        printf("freeing node: %s - %s\n", tmp->artist, tmp->name);
        free(tmp);
    }
    return front;
}