#include <stdio.h>
#include "isogram.h"

int main() {
    int result = is_iso("hssh");
    if (result != 0) {
        printf("The text is not an isogram.\n");
        return 1;
    }
    printf("The phrase is an isogram.\n");
    return 0;
}