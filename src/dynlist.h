#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct dynlist_s {
	void *data;
	size_t dsize;
	uint32_t size, cap;
}	dynlist_t;

dynlist_t	dynlist_create(size_t dsize, uint32_t cap);
void		dynlist_add(dynlist_t *l, void *data);
void		dynlist_remove(dynlist_t *l, uint32_t index);
void		dynlist_destroy(dynlist_t *l);
