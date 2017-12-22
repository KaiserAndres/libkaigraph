/*
 * DataSet.cpp
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#include "DataSet.h"

namespace kgr {

DataSet::DataSet(std::list<int> ls, std::string x_label, std::string y_label) {
	list = ls;
	this->x_label = x_label;
	this->y_label = y_label;
	min_val = NULL; // TODO find a way to have clear defaut values for the empty set,
	max_val = NULL; // -∞ would be mathematically correct.

	int i = 0;
	for (auto e = list.begin(); e != list.end(); ++e) {
		if (i == 0) {
			min_val = *e;
			max_val = *e;
		}
		if (*e > max_val)
			max_val = *e;
		if (*e < min_val)
			min_val = *e;
	}
}

DataSet::~DataSet() {
	// TODO Auto-generated destructor stub
}

void DataSet::push_back(int n) {
	list.push_back(n);
	if (n < min_val)
		min_val = n;
	if (n > max_val)
		max_val = n;
}

} /* namespace kgr */
