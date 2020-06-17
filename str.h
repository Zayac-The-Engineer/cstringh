#ifndef STR_Z 
#define STR_Z

#include <stdlib.h>
#include <string.h>

typedef struct string
{
	size_t alloc;
	size_t len;
	char* data;
} string;

string* createString(const char* str)
{
	string* s = malloc(sizeof(string));

	size_t strLength = 0;

	if (str!=NULL)
	{
		size_t strLength = strlen(str);
		memcpy(s->data, str, strLength);
	}
	s->alloc = strLength + 1;
	s->data = (char*)malloc(s->alloc);
	s->data[strLength] = '\0';
	s->len = 0;

	return s;
}

char* getStrData(string* s)
{
	return s->data;
}

char* strrealloc(string* s)
{
	s->alloc *= 2;
	char* newdata = (char*)malloc(s->alloc);
	memcpy(newdata, s->data, s->len);
	if(s->data != NULL)
	{
		free(s->data);
	}
	s->data = newdata;

	return newdata;
}

void append(string* s, char c)
{
	char* data = (strlen(s->data)+1 != sizeof(s)) ? s->data : strrealloc(s);
	data[s->len++] = c;
	data[s->len] = '\0';
}
#endif
