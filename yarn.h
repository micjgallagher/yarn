#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

//Header for Yarn library
struct stringStruct{
	char *body;
	int length;
	int capacity;
};

typedef struct stringStruct string;

string construct_string(int capacity);
void destroy_string(string *obj);
void add_character(string *obj, char input);
void insert_at(string *obj, char letter, int pos);
void add_characters(string *obj, char * buffer, int buffer_length);
int expand_memory(string *obj, int amount);
void shrink_to_fit(string* obj);
string create_copy(string *obj); //figure out if this needs to actually take a pointer or if we can just pass the object
string create_copy_memcpy(string *obj);
bool check_string_equality(string* s1, string* s2);
