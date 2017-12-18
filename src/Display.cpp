/*
 * Display.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: kaiser
 */

#include "Display.h"

namespace kgr {

int max_val(std::list<int> ls) {
	if (ls.size() == 0)
		throw "Invalid list exception.";

	int max = ls.front();

	for (auto e = ls.begin(); e != ls.end(); ++e) {
		if (*e > max)
			max = *e;
	}

	return max;
}

int min_val(std::list<int> ls) {
	if (ls.size() == 0)
		throw "Invalid list exception.";

	int min = ls.front();

	for (auto e = ls.begin(); e != ls.end(); ++e) {
		if (*e < min)
			min = *e;
	}

	return min;
}

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

void Display::render_int_list(std::list<int> list, int separation, SDL_Color c) {
	SDL_Rect bar;
	bar.x = 0;
	bar.y = 0;
	bar.w = list.size() / width;
	bar.h = 0;
	int i = 0;
	int max = max_val(list);
	int min = min_val(list);

	for (auto e = list.begin(); e != list.end(); ++e) {
		bar.h = (int)(((*e) - min) / abs(min - max));
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
