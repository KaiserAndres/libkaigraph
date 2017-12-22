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
		logger.log(ERR, "Failed to initialize window" + *SDL_GetError());

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == nullptr)
		logger.log(ERR, "Failed to initialize renderer" + *SDL_GetError());

}

void Display::render_int_list(DataSet s, int separation, SDL_Color c) {
	SDL_Rect bar;
	bar.x = 0;
	bar.y = 0;
	bar.w = s.size() / width;
	bar.h = 0;
	int i = 0;

	for (auto e = s.begin(); e != s.end(); ++e) {
		bar.h = (int)(((*e) - s.min()) / abs(s.min() - s.max()));
		bar.y = height - bar.h;
		bar.x = i * bar.w + (i+1) * separation;
		i++;

	    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
		SDL_RenderDrawRect(ren, &bar);
	}
}

Display::~Display() {
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

} /* namespace kgr */
