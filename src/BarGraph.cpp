/*
 * BarGraph.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#include "BarGraph.h"

namespace kgr {

BarGraph::BarGraph(DataSet s, Point begin, Point end, SDL_Color c, int separation) : Graph(s, begin, end) {
	draw_color = c;
	this->separation = separation;
}

BarGraph::BarGraph(DataSet s, Point begin, Point end, SDL_Color c) : Graph(s, begin, end) {
	draw_color = c;
	this->separation = 0;
}

BarGraph::BarGraph(DataSet s, Point begin, Point end) : Graph(s, begin, end) {
	draw_color = WHITE;
	this->separation = 0;
}

BarGraph::~BarGraph() {
	// TODO Auto-generated destructor stub
}

void BarGraph::draw(SDL_Renderer *ren) {
	SDL_Rect bar;
	bar.x = begin.x;
	bar.y = begin.y;
	bar.w = set.size() / (end.x - begin.x);
	bar.h = 0;
	int i = 0;

	for (auto e = set.begin(); e != set.end(); ++e) {
		bar.h = (int)(((*e) - set.min()) / abs(set.min() - set.max()));
		bar.y = (end.y - begin.y) - bar.h;
		bar.x = i * bar.w + (i+1) * separation;
		i++;

	    SDL_SetRenderDrawColor(ren, draw_color.r, draw_color.g, draw_color.b, draw_color.a);
		SDL_RenderFillRect(ren, &bar);
	}
}

} /* namespace kgr */
