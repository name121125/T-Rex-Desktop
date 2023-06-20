#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH (395)
#define WINDOW_HEIGHT (128)

int main() {
    int exit = 1;
    SDL_Rect rect = {(WINDOW_WIDTH - 48)/2, (WINDOW_HEIGHT - 48)/2, 48, 48};
   
    SDL_Rect back_rect = {0, 12, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect back_rect2 = {395, 12, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect back_rect3 = {790, 12, WINDOW_WIDTH, WINDOW_HEIGHT};

    SDL_Event event;

    SDL_Window* window = NULL;
    SDL_Surface* background_surface = NULL;
    SDL_Renderer* render = NULL;
    SDL_Texture* background_texture = NULL;
    SDL_Surface* trex_surface = NULL;
    SDL_Texture* trex_texture = NULL;

    window = SDL_CreateWindow("T_Rex", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    	
    background_texture = IMG_LoadTexture(render, "res/background.png"); 
    trex_texture = IMG_LoadTexture(render, "res/dino.png");
	
    while (exit) 
    {

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) exit = 0;
	
	back_rect.x -= 3;
	back_rect2.x -= 3;
	back_rect3.x -= 3;
	
	if (back_rect.x < -395) { back_rect.x = 790; }
	if (back_rect2.x < -395) { back_rect2.x = 790; }
	if (back_rect3.x < -395) { back_rect3.x = 790; }
	 
	SDL_RenderClear(render);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	SDL_RenderCopy(render, background_texture, NULL, &back_rect);
	SDL_RenderCopy(render, background_texture, NULL, &back_rect2);
	SDL_RenderCopy(render, background_texture, NULL, &back_rect3);
        SDL_RenderCopy(render, trex_texture, NULL,&rect);
	SDL_RenderPresent(render);
	SDL_Delay(1);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(trex_texture);
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(trex_surface);
    SDL_FreeSurface(background_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

