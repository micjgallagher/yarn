//Header for Yarn library
struct stringStruct{
	char *body;
	size_t length;
	size_t capacity;
};

typedef struct stringStruct string;

string construct_string(size_t capacity);