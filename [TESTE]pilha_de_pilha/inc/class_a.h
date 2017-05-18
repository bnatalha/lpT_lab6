#ifndef CLASS_A_H
#define CLASS_A_H

#include "header.h"

class A_class{

private:
	static const int my_default = 3;
	int my;

public:
	A_class(){
		my = my_default;
	}

	void print_my() {
		cout << my << endl;
	}

};

#endif