#include "yarn.h"
#include <stdlib.h>

string construct_string(size_t capacity){
    //probably should check to see if capacity is valid
    string build;
    build.length  = 0;
    build.capacity = capacity;
    build.body = malloc(sizeof(char) * capacity);
    build.body[0] = '\0';

    return build;
}

