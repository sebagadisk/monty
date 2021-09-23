#ifndef MONTY_H
#define MONTY_H
#define INVALID_ARGUMENT_NUMBER 10
#define INVALID_FILE 11
#define INVALID_PARSING_ARGUMENT 12

#define BUFFER_SIZE 1024
#define COMMAND_SEPARATOR " "

#include <sys/types.h>
#include <sys/stat.h>
@@ -48,6 +48,8 @@ typedef struct instruction_s
typedef struct data_s
{
	char **arguments;
	char *buffer;
	stack_t *queue;
} data_t;

extern data_t *appData;
@@ -59,12 +61,15 @@ int _checkEscapeSeparators(char prmChar, char *prmEscapeSeparators);
int _checkSeparators(char prmChar, char *prmSeparators);
char *_cleanString(char *prmString);
void _errorHandler(int prmErrorCode);
void _freeAppData();
void _freeCharDoublePointer(char **prmPtr);
void _freeStackList(stack_t *prmHeadNode);
void (*_getCustomFunction(char *prmCommand))(stack_t **, unsigned int);
char *_getword(char *prmGlobal, int prmOffset, int prmSize);
int _inArray(char prmChar, char *prmArray);
int _isdigit(char prmChar);
void _initAppData();
int _isNumber(char *s);
char *_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit);
char *_memset(char *prmString, char prmCharacter, unsigned int prmLimit);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void *_realloc(void *prmPtr, unsigned int prmOldSize, unsigned int prmNewSize);
int _strcmp(char *prmString1, char *prmString2);
char *_strcpy(char *prmDest, char *prmSrc);
char *_strdup(char *prmString);
int _strlen(char *prmStr);
char *_strncpy(char *prmDest, char *prmSrc, int prmLimit);
char **_strtow(char *prmString, char *prmSeparators, char *prmEscapeSeparators);
int _wordNumber(char *prmString, char *prmSeparators);
#endif
