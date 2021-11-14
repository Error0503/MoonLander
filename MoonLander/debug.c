#include "debug.h"

void Log(char* msg, int level) {
	switch (level) {
		case 0:
			printf(OK "[OK]" RESET " %s", msg);
			break;
		case 1:
			printf(INFO "[INFO]" RESET " %s", msg);
			break;
		case 2:
			printf(WARNING "[WARNING]" RESET " %s", msg);
			break;
		case 3:
			printf(ERROR "[ERROR]" RESET " %s", msg);
			break;
		case 4:
			printf(FATAL "[FATAL]" RESET " %s", msg);
			break;
	}
}

void LogInt(int value) {
	printf(INFO "%d\n" RESET, value);
}