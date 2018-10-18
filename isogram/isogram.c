#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *map[100];

int hash_value(char value, int size) {
    // Get the hash value of the of a char and insert it into the map array.
    int hash = value % size;
    printf("%d\n", hash);
    // Check to see if the value already exists within the map.
    if(map[hash] != NULL)
        return 1;
    return 0;
}

int is_iso(char *text) {
    int result;
    // Get the size.
    int size = strlen(text);
    // Now iterate through the string and see if a letter occurs more than once.
    for(int i = 0; i < size; i++) {
        result = hash_value(text[i], size);
        if(result != 0)
            return 1;
        printf("%c\n", text[i]);
    }
    return 0;
}

int main() {
    int result = is_iso("hssh");
    if (result != 0) {
        printf("The text is not an isogram.\n");
        return 1;
    }
    printf("The phrase is an isogram.\n");
    return 0;
}