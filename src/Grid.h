/*
 * Grid.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#ifndef GRID_H_
#define GRID_H_

#include "helper.h"

namespace kgr {

class Grid {
public:

	Grid(Point begin, Point end, unsigned int v_dist, unsigned int h_dist, unsigned int dash_size, unsigned int stroke_size);
	Grid(Point begin, Point end, unsigned int v_dist, unsigned int h_dist);
	Grid(Point begin, Point end);

	virtual ~Grid();

	void draw(SDL_Renderer *ren);
	void set_v_dist(unsigned int v_dist) { this->v_dist = v_dist; }
	void set_h_dist(unsigned int h_dist) { this->h_dist = h_dist; }
	void set_dash_size(unsigned int dash_size) { this->dash_size = dash_size; }
	void set_stroke_size(unsigned int stroke_size) { this->stroke_size = stroke_size; }
private:
	Point begin;
	Point end;

	unsigned int v_dist;
	unsigned int h_dist;
	unsigned int dash_size;
	unsigned int stroke_size;
};

} /* namespace kgr */

#endif /* GRID_H_ */
