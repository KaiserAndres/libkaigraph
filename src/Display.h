/*
 * Display.h
 *
 *  Created on: Dec 18, 2017
 *      Author: kaiser
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include <string>
#include <list>
#include <math.h>

#include "Logger.h"
#include "DataSet.h"
#include "BarGraph.h"

namespace kgr {

class Display {
public:
	Display(std::string title, int width, int height);

	void render_barGraph(BarGraph b);
	virtual ~Display();

private:

	int width, height;
	Logger logger;
	SDL_Window *win;
	SDL_Renderer *ren;
};

} /* namespace kgr */

#endif /* DISPLAY_H_ */
