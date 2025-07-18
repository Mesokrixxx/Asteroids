#pragma once

typedef union vec2_u {
	struct { float x, y; };
	float raw[2];
}	vec2_t;

#define vec2_of(x, y) ((vec2_t){{ x, y }})
