#pragma once

#include <stdlib.h>
#include "types.h"

typedef struct dynlist_s {
	void *data;
	size_t dsize;
	uint32_t size, cap;
}	dynlist_t;
