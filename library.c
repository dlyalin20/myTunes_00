#include "library.h"

// Creates library
struct song_node ** create_library() {
    struct song_node (*library)[28] = calloc(28, sizeof(struct song_node *));
    return library;
}

// Adds song node to library
struct song_node ** add_song_node(struct song_node **library, struct song_node *node) {
    if (isalpha((node->artist)[0])) 
        library[(tolower((node->artist)[0])) - 97] = insert_helper(library[(tolower((node->artist)[0])) - 97], node);
    else  
        library[27] = insert_helper(library[27], node);
    return library;
}

// Adds custom song to library
struct song_node ** add_song(struct song_node **library, char *artist, char *name) {
    struct song_node *song = create_song(artist, name);
    library = add_song_node(library, song);
    return library;
}

// Prints library
void print_library(struct song_node **library) {
    char counter;
    for (counter = 'a'; counter < 125; counter++) {
        if (library[counter - 97]) {
            printf("%c: ", counter);
            print_list(library[counter - 97]);
        }
    }
    printf("\n");
}

// Searches library for song given artist and name
struct song_node * find_song(struct song_node **library, char *artist, char *name) {
    if (isalpha(artist[0]))  
        return find_node(library[(tolower((artist)[0])) - 97], artist, name);

    else 
        return find_node(library[27], artist, name);
}

// finds specific artist in library
struct song_node * find_artist_library(struct song_node **library, char *artist) {
    if (isalpha(artist[0])) 
        return find_artist(library[(tolower((artist)[0])) - 97], artist);
    else
        return find_artist(library[27], artist);
}

// prints all entries starting with specific letter
void print_letter(struct song_node **library, char letter) {
    if (isalpha(letter))
        print_list(library[tolower(letter) - 97]);
    else 
        print_list(library[27]);
}

// prints out all songs by an artist, does first twice
void print_artist(struct song_node **library, char *artist) {
    struct song_node *tmp = find_artist_library(library, artist);
    while (tmp && strcasecmp(artist, tmp->artist) == 0) {
        print_song(tmp);
        tmp = tmp->next;
    }
    printf("\n");
}

// Generates one random song from library
void shuffle_helper(struct song_node **library) {
    int i = (rand() % (27 - 1 + 1)) + 1;
    if (library[i]) 
        random_song(library[i]);
    else shuffle_helper(library);
}

// Prints random assortment of songs 
// Important: amount of songs is variable but will be at least 1; songs can repeat
void shuffle(struct song_node **library) {
    shuffle_helper(library);
    while (rand() % 5) 
        shuffle_helper(library);
}

// Deletes a song from library
struct song_node ** remove_song_library(struct song_node **library, char *artist, char *name) {
    if (isalpha(artist[0])) {
       library[(tolower((artist)[0])) - 97] = remove_song(library[(tolower((artist)[0])) - 97], artist, name);
    }
    else {
        library[27] = remove_song(library[27], artist, name);
    }
    return library;
}

// Clear library
struct song_node ** free_library(struct song_node **library) {
    int counter;
    for (counter = 0; counter < 28; counter++) {
        library[counter] = free_list(library[counter]);
    }
    return library;
}

/* // Helper for create function that iterates over every node to initialize
struct library * create_helper(struct library *lib) {
    char counter = 'a';
    struct library *end = lib;
    for ( ; counter < 124; counter++) {
        end->letter = counter;
        end->songs = NULL;
        struct library *tmp = calloc(1, sizeof(struct library));
        end->next = tmp;
        end = end->next;
    }
    return lib;
}

// Generates linked list of library structures
struct library * create_library() {
    struct library *lib = calloc(1, sizeof(struct library));
    lib = create_helper(lib);
    return lib;
}

// Tests proper generation
void print_test(struct library *lib) {
    while (lib) {
        printf("%c ", lib->letter);
        lib = lib->next;
    }
    printf("\n");
}

struct library * add_song(struct library *lib, struct song_node *song) {
   struct library *tmp = lib;
   int counter;
   for (counter = 0; counter < 27; counter++) {
       if (tmp->letter == (song->artist)[0]) {
           tmp->songs = insert_helper(tmp->songs, song);
           break;
       }
       else tmp = tmp->next;
   }

} */