#ifndef MONTY_H
#define MONTY_H
#define INVALID_ARGUMENT_NUMBER 10
#define INVALID_FILE 11
#define INVALID_PARSING_ARGUMENT 12
#define INVALID_ARGUMENT_FORMAT 13
#define EMPTY_STACK 14

#define BUFFER_SIZE 1024
#define COMMAND_SEPARATOR " \n"

#include <sys/types.h>
#include <sys/stat.h>
@@ -49,14 +51,17 @@ typedef struct data_s
{
	char **arguments;
	char *buffer;
	FILE *fileDescriptor;
	stack_t *queue;
	int lineNumber;
} data_t;

extern data_t *appData;

void _addWord(char *prmWord, int *prmIndex, char **prmArray);
int _atoi(char *prmString);
void *_calloc(unsigned int prmNumber, unsigned int prmSize);
int _checkArguments();
int _checkEscapeSeparators(char prmChar, char *prmEscapeSeparators);
int _checkSeparators(char prmChar, char *prmSeparators);
char *_cleanString(char *prmString);
@@ -74,6 +79,7 @@ char *_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit);
char *_memset(char *prmString, char prmCharacter, unsigned int prmLimit);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void *_realloc(void *prmPtr, unsigned int prmOldSize, unsigned int prmNewSize);
int _strcmp(char *prmString1, char *prmString2);
char *_strcpy(char *prmDest, char *prmSrc);
char *_strdup(char *prmString);
int _strlen(char *prmStr);
char *_strncpy(char *prmDest, char *prmSrc, int prmLimit);
char **_strtow(char *prmString, char *prmSeparators, char *prmEscapeSeparators);
int _wordNumber(char *prmString, char *prmSeparators);
#endif
