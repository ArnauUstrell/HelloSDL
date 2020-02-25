#include "SDL/include/SDL.h"
#pragma comment(lib,"SDL/libx86/SDL2.lib")
#pragma comment(lib,"SDL/libx86/SDL2main.lib")
#include <iostream>


//Mides window
#define WINDOW_WIDTH 640 //amplada
#define WINDOW_HEIGHT 480 //altura



void logSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

void clear(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void draw(SDL_Renderer* renderer, SDL_Rect* rect) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, rect);
	SDL_RenderPresent(renderer);
}



int main(int argc, char** argv) {
	/*
	//STARTING SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//CREATING A WINDOW (X,Y,W,H, ?????????????)
	SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN); //QUE FA LA ULTIMA OPCIO (SDL_WINDOW_SHOWN)
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	//CREATING A RENDERER
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}*/


	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("An SDL2 window",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Rect rectangle;
	rectangle.x = 50;
	rectangle.y = 50;
	rectangle.w = 50;
	rectangle.h = 50;

	clear(renderer);

	int quit = 0;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				// Handle arrow keys
				switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_LEFT:
					rectangle.x -= 10;
					break;
				case SDL_SCANCODE_RIGHT:
					rectangle.x += 10;
					break;
				case SDL_SCANCODE_UP:
					rectangle.y -= 10;
					break;
				case SDL_SCANCODE_DOWN:
					rectangle.y += 10;
					break;
				default:
					break;
				}

			}
			else if (event.type == SDL_QUIT) {
				quit = 1;
				puts("QUIT!");
				break;
			}
		}

		clear(renderer);
		draw(renderer, &rectangle);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;




	//system("PAUSE");


	
	/*
	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	//Clear rendering target
	SDL_RenderClear(ren);

	//Draw some geometry
	int n = 0;
	const int cx = WINDOW_WIDTH >> 1,
		cy = WINDOW_HEIGHT >> 1;
	SDL_Rect rc = { 0, cy, 10, 10 };	//x, y, w, h
	float alpha;
	while (n < 360)
	{
		alpha = n * M_PI / 180.0f;
		rc.x += 17;

		SDL_SetRenderDrawColor(ren, n * 0.7f, 192, 0, 255);
		SDL_RenderFillRect(ren, &rc);

		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderDrawLine(ren, cx, cy, cx + cy * cos(alpha), cy - cy * sin(alpha));

		//Wait a specified number of milliseconds
		SDL_Delay(100);

		//Update screen
		SDL_RenderPresent(ren);

		n += 10;
	}
	SDL_Delay(1000);

	//Clean up all SDL initialized subsystems
	SDL_Quit();
	

	*/








	/*
	//LOADING A BITMAP IMAGE
	std::string imagePath = getResourcePath("Lesson1") + "hello.bmp"; //NO SE COM ARREGLAR AIXÒ
	SDL_Surface* bmp = SDL_LoadBMP(imagePath.c_str());
	if (bmp == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}





	for (int i = 0; i < 3; ++i) {
		//First clear the renderer
		SDL_RenderClear(ren);
		//Draw the texture
		SDL_RenderCopy(ren, tex, NULL, NULL);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
		SDL_Delay(1000);
	}


	*/


	//system("pause");
	//return 0;
}

//https://www.willusher.isdl2%20tutorials/2013/08/17/lesson-1-hello-world