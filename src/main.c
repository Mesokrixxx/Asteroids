#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "types.h"
#include "assert.h"
#include "vectors.h"

typedef struct player_s {
	vec2_t pos;
	vec2_t velocity;
	vec2_t dir;
}	player_t;

typedef struct state_s {
	SDL_Window		*window;
	SDL_GLContext	glctx;
	ivec2_t			window_size;
	bool			running;
}	state_t;

int	main(void)
{
	state_t	game;

	assert(!SDL_Init(SDL_INIT_VIDEO), "failed to init sdl: %s", SDL_GetError());
	game.window_size = ivec2_of(1080, 720);
	game.window = SDL_CreateWindow(
		"Asteroids", 
		SDL_WINDOWPOS_CENTERED_DISPLAY(1), 
		SDL_WINDOWPOS_CENTERED_DISPLAY(1), 
		game.window_size.x, game.window_size.y, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	assert(game.window, "failed to create sdl window: %s", SDL_GetError());
	game.glctx = SDL_GL_CreateContext(game.window);
	assert(game.glctx, "failed to create gl context: %s", SDL_GetError());
	assert(glewInit() == GLEW_OK, "failed to init glew");
	game.running = true;
	while (game.running)
	{
		SDL_Event	ev;

		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case (SDL_QUIT):
					game.running = false;
					break ;
			};
			switch (ev.window.event)
			{
				case (SDL_WINDOWEVENT_RESIZED):
					game.window_size = ivec2_of(ev.window.data1, ev.window.data2);
					break ;
			};
		}
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(game.window);
	}
	SDL_GL_DeleteContext(game.glctx);
	SDL_DestroyWindow(game.window);
	SDL_Quit();
	return (0);
}
