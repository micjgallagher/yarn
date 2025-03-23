#include <stdlib.h>
#include <stddef.h>

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
int expand_memory(string *obj, int amount);