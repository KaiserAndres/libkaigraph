/*
 * DataSet.h
 *
 *  Created on: Dec 22, 2017
 *      Author: kaiser
 */

#ifndef DATASET_H_
#define DATASET_H_

#include <list>
#include <string>

namespace kgr {

class DataSet {
public:
	DataSet(std::list<int> ls, std::string x_label, std::string y_label);
	virtual ~DataSet();

	int max() { return max_val; }
	int min() { return min_val; }
	void setXlabel(std::string x_label) { this->x_label = x_label; }
	void setYlabel(std::string y_label) { this->y_label = y_label; }
	std::string getXlabel() { return x_label; }
	std::string getYlabel() { return y_label; }

	std::list<int>::iterator begin() { return list.begin(); }
	std::list<int>::iterator end() { return list.end(); }
	void push_back(int n);
	bool empty() { return list.empty(); }
	int size() { return list.size(); }
private:
	int min_val;
	int max_val;
	std::list<int> list;
	std::string x_label;
	std::string y_label;

};

} /* namespace kgr */

#endif /* DATASET_H_ */
