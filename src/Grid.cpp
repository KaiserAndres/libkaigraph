/*
 * Grid.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#include "Grid.h"

namespace kgr {

Grid::Grid(Point begin, Point end, unsigned int v_dist, unsigned int h_dist, unsigned int dash_size, unsigned int stroke_size) {
	this->begin = begin;
	this->end = end;
	this->v_dist = v_dist;
	this->h_dist = h_dist;
	this->dash_size = dash_size;
	this->stroke_size = stroke_size;
}

Grid::Grid(Point begin, Point end, unsigned int v_dist, unsigned int h_dist) : Grid(begin, end, v_dist, h_dist, 0, 0) {}

Grid::Grid(Point begin, Point end) : Grid(begin, end, (end.y - begin.y)/10 , (end.x - begin.x)/10 , 0, 0) {}

Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

void Grid::draw(SDL_Renderer *ren) {
	if (!dash_size) {
		// No dashes case
		for (int i = 0; i < (end.y - begin.y)/v_dist; i++) {
			SDL_RenderDrawLine(ren, begin.x, v_dist*i, end.x, v_dist*i);
		}
		for (int i = 0; i < (end.x - begin.x)/h_dist; i++) {
			SDL_RenderDrawLine(ren, h_dist*i, begin.y, h_dist*i, end.y);
		}
	}
	// Dashed case

	for (int i = 0; i < (end.y - begin.y)/v_dist; i++) {
		for (int j = begin.x; j < end.x; j += stroke_size + dash_size) {
			SDL_RenderDrawLine(ren, j, v_dist*i, j + stroke_size, v_dist*i);
		}
	}
	for (int i = 0; i < (end.x - begin.x)/h_dist; i++) {
		for (int j = begin.y; j < end.y; j += stroke_size + dash_size) {
			SDL_RenderDrawLine(ren, h_dist*i, j, h_dist*i, j + stroke_size);
		}
	}
}

} /* namespace kgr */
