/*
 * BarGraph.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#ifndef BARGRAPH_H_
#define BARGRAPH_H_

#include "Graph.h"
#include "DataSet.h"
#include <SDL2/SDL.h>

namespace kgr {

class BarGraph: public virtual Graph {
public:
	BarGraph(DataSet s, Point begin, Point end, SDL_Color c, int separation);
	BarGraph(DataSet s, Point begin, Point end, SDL_Color c);
	BarGraph(DataSet s, Point begin, Point end);
	virtual ~BarGraph();

	void draw(SDL_Renderer *ren);
private:
	SDL_Color draw_color;
	int separation;
};

} /* namespace kgr */

#endif /* BARGRAPH_H_ */
