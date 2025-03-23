#include "yarn.h"
#include <stdlib.h>

string construct_string(int capacity){
    //probably should check to see if capacity is valid
    string build;
    build.length  = 0;
    build.capacity = capacity;
    build.body = malloc(sizeof(char) * capacity);
    build.body[0] = '\0';

    return build;
}

void destroy_string (string* obj){
    free(obj->body);
    obj->body = 0;
    obj->capacity = 0;
    obj->length = 0;
}

void add_character(string *obj, char input){
    
    if(obj->length + 1 >= obj->capacity){
        //Reallocate memory here
    }

    obj->body[obj->length] = input;
    obj->length++;
    obj->body[obj->length] = '\0';
}

int expand_memory(string *obj, int amount){
    //Expands the buffer size to capacity + amount
    //returns 0 on success, 1 on error
    int total_memory = obj -> capacity + amount;
    char *buffer = malloc(sizeof(char) * total_memory);

    for(int i=0; i < obj->length + 1; i++){ //we are checking one additional element past length to ensure that the null character is copied over
        buffer[i] = obj->body[i];
    }
    free(obj->body); 
    obj->body = buffer;
    obj->capacity += amount;

    return 0;
}