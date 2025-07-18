#pragma once

#include <stdio.h>
#include <stdlib.h>

#define assert(c, fmt, ...) \
	do { \
		if (!(c)) { \
			fprintf(stderr, "[ASSERTION FAILED][%s::%d]["\
				fmt "]\n", \
				__FILE__, __LINE__, ##__VA_ARGS__); \
			exit(1); \
		} \
	}	while (0);
