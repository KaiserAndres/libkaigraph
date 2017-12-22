/*
 * Graph.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#import "DataSet.h"
#include <SDL2/SDL.h>

namespace kgr {

const SDL_Color WHITE = {255, 255, 255, 0};

struct Point {
	int x;
	int y;
};

class Graph {
public:
	Graph(DataSet s, Point begin, Point end) { this->set = s; this->begin = begin; this->end = end; }
	virtual void draw(SDL_Renderer *ren) = 0;
	~Graph() {}
protected:
	DataSet set;
	Point begin;
	Point end;
};

} /* namespace kgr */

#endif /* GRAPH_H_ */
