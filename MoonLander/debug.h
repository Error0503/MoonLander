#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#define RESET		"\033[0m"
#define OK			"\033[32m"
#define INFO		"\033[94m"
#define WARNING		"\033[33m"
#define	ERROR		"\033[37m"
#define FATAL		"\033[31m"

void Log(char* msg, int level);
void LogInt(int value);

#endif
