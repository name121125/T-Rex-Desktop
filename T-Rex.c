#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#define WINDOW_WIDTH (1544)
#define WINDOW_HEIGHT (500)

int main() {
    int exit = 1;
    int distance = 0;
    SDL_Rect rect = {(WINDOW_WIDTH - 100)/2, 145, 150, 150};
   
    SDL_Rect back_rect = {0, 12, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect back_rect2 = {1544, 12, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect back_rect3 = {3088, 12, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_Rect message_dist = {10, 10, 100, 100};

    TTF_Font* Sans = TTF_OpenFont("FreeMono.ttf", 50);
    SDL_Color Grey = {83, 83, 83};

    SDL_Event event;

    SDL_Window* window = NULL;
    SDL_Surface* background_surface = NULL;
    SDL_Renderer* render = NULL;
    SDL_Texture* background_texture = NULL;
    SDL_Surface* trex_surface = NULL;
    SDL_Texture* trex_texture = NULL;
    SDL_Texture* trex_texture2 = NULL;
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "test", Grey);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(render, surfaceMessage);


    window = SDL_CreateWindow("T_Rex", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    	
    background_texture = IMG_LoadTexture(render, "res/background.png"); 
    trex_texture = IMG_LoadTexture(render, "res/dino.png");
    trex_texture2 = IMG_LoadTexture(render,"res/dino2.png");
    
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    
    while (exit) 
    {

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) exit = 0;

	distance = distance + 1;

	back_rect.x -= 10;
	back_rect2.x -= 10;
	back_rect3.x -= 10;
	
	if (back_rect.x < -1544) { back_rect.x = 3088; }
	if (back_rect2.x < -1544) { back_rect2.x = 3088; }
	if (back_rect3.x < -1544) { back_rect3.x = 3088; }
	
	SDL_RenderCopy(render, background_texture, NULL, &back_rect);
	SDL_RenderCopy(render, background_texture, NULL, &back_rect2);
	SDL_RenderCopy(render, background_texture, NULL, &back_rect3);
	if (distance % 2 == 0) {
	    SDL_RenderCopy(render, trex_texture, NULL, &rect);
	} else {
	
	    SDL_RenderCopy(render, trex_texture2, NULL, &rect);
	    
	}
	SDL_RenderCopy(render, Message, NULL, &message_dist);

	SDL_RenderPresent(render);
	SDL_Delay(100);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(trex_texture);
    SDL_DestroyTexture(background_texture);
    SDL_FreeSurface(trex_surface);
    SDL_FreeSurface(background_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

