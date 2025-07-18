#pragma once

typedef union ivec2_u {
	struct { int x, y; };
	int raw[2];
}	ivec2_t;

typedef union vec2_u {
	struct { float x, y; };
	float raw[2];
}	vec2_t;

#define ivec2_of(x, y) ((ivec2_t){{ x, y }})
#define vec2_of(x, y) ((vec2_t){{ x, y }})
