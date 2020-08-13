#include "str.h"

string* str_create(const char* str)
{
	string* s = malloc(sizeof(string));

	size_t strLength = 0;

	if (str!=NULL)
	{
		strLength = strlen(str);
		memcpy(s->data, str, strLength);
	}
	s->capacity = strLength + 1;
	s->data = (char*)malloc(s->capacity);
	s->data[strLength] = '\0';
	s->len = strLength;

	return s;
}

void str_destroy(string* s)
{
	free(s->data);
	free(s);
}

char* str_get_data(const string* s)
{
	return s->data;
}
/*
char str_get_element(const string* s, const size_t i)
{
	return s->data[i];
}
*/
void str_push_back(string* s, char c)
{
	char* data = (s->len+1 != s->capacity) ? s->data : realloc(s->data, s->capacity*2);
	s->capacity *= 2;
	data[s->len++] = c;
	data[s->len] = '\0';
}

string* str_join(const string* s, const char* c)
{
	string* result = str_create(NULL);
	result->data = strcat(s->data, c);
	result->len = strlen(result->data);

	return result;
}

string* str_input()
{
	char i;
	string* s = str_create(NULL);
	while(i!='\n')
	{
		i=getchar();
		str_push_back(s, i);

		/* printf("%s\n", s->data); */
	}
	return s;
}
