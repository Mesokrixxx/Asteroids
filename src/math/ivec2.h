#pragma once

typedef union ivec2_u {
	struct { int x, y; };
	int raw[2];
}	ivec2_t;

#define ivec2_of(x, y) ((ivec2_t){{ x, y }})
