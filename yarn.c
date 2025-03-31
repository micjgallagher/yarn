#include "yarn.h"
#include <stdlib.h>
#include <string.h> //Using this for memcpy
#include <stdbool.h>


void copy_to(string *original, string *destination){
    //Before using this method make sure that the original has enough capacity to hold the new one
    for(int i=0; i <= original->length; i++){ //using <= to ensure that the null character is copied over
        destination->body[i] = original->body[i];
    }
}

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
    // Appends a single character into the specified string. Will expand memory buffer if needed.
    if(obj->length + 1 >= obj->capacity){
        expand_memory(obj, obj->capacity);
    }

    obj->body[obj->length] = input;
    obj->length++;
    obj->body[obj->length] = '\0';
}
void add_characters(string *obj, char *buffer, int buffer_length){
    //Unlike add_character, add_characters only allocates exactly how much space is needed to add the additional characters
    if(obj->capacity < obj->length + buffer_length + 1){ //check if this is off by one
        int free_memory = obj->capacity - obj->length - 1;
        int needed_memory = buffer_length - free_memory;
        expand_memory(obj, needed_memory);
        obj->capacity = obj->capacity + needed_memory;
    }
    //Copy buffer over
    char *dest = obj->body + obj->length;
    memcpy(dest, buffer, buffer_length);
    obj->length += buffer_length;
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
void shrink_to_fit(string* obj){
    int total_size = (obj->length + 1) * sizeof(char);
    char *buffer = malloc(total_size);
    memcpy(buffer, obj->body, total_size);
    free(obj->body);
    obj->body = buffer;
    obj->capacity = total_size;
}

string create_copy(string *obj){
    string copy = construct_string(obj->capacity);
    copy_to(obj, &copy);
    copy.length = obj->length;
    copy.capacity = obj->capacity;
    return copy;
}

string create_copy_memcpy(string *obj){
    string copy = construct_string(obj->capacity);
    memcpy(copy.body, obj->body, sizeof(char) * (obj->length+1)); //we add one to length to copy over the null char
    copy.length = obj->length;
    return copy;
}

bool check_string_equality(string* s1, string* s2){
    if(s1->length != s2->length){
        return false;
    }

    for(int i=0;i< s1->length;i++){
        if(s1->body[i] != s2->body[i]){
            return false;
        }
    }
    return true;
}
