#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

using namespace std;

int main() {
	SDL_Window* window= nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "cannot init" << SDL_GetError() << endl;
	}
	window = SDL_CreateWindow("test", 20, 20, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* render = nullptr;
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (TTF_Init() == -1) {
		cout << "could not init SDL_ttf error: " << SDL_GetError() << endl;
	}
	
	TTF_Font* ourfont = TTF_OpenFont("FreeMono.ttf", 50);

	if (ourfont == nullptr) {
		cout << "cannot load font" << endl;

	}

	SDL_Surface* surfacetext = TTF_RenderText_Solid(ourfont, "test", {255, 255, 255});
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surfacetext);
	SDL_FreeSurface(surfacetext);
	SDL_Rect rectangle;
	SDL_Event event;
	
	rectangle.x = 10;
	rectangle.y = 10;
	rectangle.w = 100;
	rectangle.h = 100;
	bool run = true;
	while (run) {
		while (SDL_PollEvent(&event)) {
	 		if (event.type == SDL_QUIT) {
	 			run = false;
	 		}
		
		}
	SDL_SetRenderDrawColor(render, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
 	SDL_RenderClear(render);
	SDL_RenderCopy(render, texture, NULL, &rectangle);
	SDL_RenderPresent(render);
			
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
}
