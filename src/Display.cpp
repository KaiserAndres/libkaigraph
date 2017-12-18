/*
 * Display.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: kaiser
 */

#include "Display.h"

namespace kgr {

Display::Display(std::string title, int width, int height) {
	this->width = width;
	this->height = height;

	logger = Logger();

	SDL_Init(SDL_INIT_EVERYTHING);

	win = SDL_CreateWindow(title.c_str(),
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				width, height,
				SDL_WINDOW_OPENGL);

	if (win == nullptr)
		logger.log(ERR, "Failed to initialize window" + SDL_GetError());

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == nullptr)
		logger.log(ERR, "Failed to initialize renderer" + SDL_GetError());

}

Display::~Display() {
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

} /* namespace kgr */
