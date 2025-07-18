#include "dynlist.h"
#include "assert.h"
#include <string.h>

dynlist_t dynlist_create(size_t dsize, uint32_t cap)
{
	dynlist_t	list = {
		.cap = cap,
		.dsize = dsize,
	};

	list.data = malloc(dsize * cap);
	assert(list.data, "malloc failure");
	return list;
}

void	dynlist_add(dynlist_t *l, void *data)
{
	if (l->size >= l->cap)
	{
		l->cap *= 2;
		l->data = realloc(l->data, l->cap);
		assert(l->data, "realloc failure");
	}
	memcpy(l->data + l->size * l->dsize, data, l->dsize);
	l->size++;
}

void	dynlist_remove(dynlist_t *l, uint32_t index)
{
	if (index >= l->size)
		return ;
	if (index != l->size - 1)
		memcpy(l->data + index * l->dsize,
			l->data + (l->size - 1) * l->dsize, l->dsize);
	l->size--;
}

void	dynlist_destroy(dynlist_t *l)
{
	free(l->data);
	*l = (dynlist_t){0};
}
