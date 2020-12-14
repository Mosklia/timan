#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

#include "task.h"
#include "solve.h"

std::priority_queue<task>q;
int main() {
	inputmodule(q);
	std::string command;
	while(1) {
		std::cout<<">";
		std::cin>>command;
		if(command=="exit") break;
		else if(command=="add") {
			add(q);
		} else if(command=="check") {
			check(q);
		} else if(command=="list") {
			list(q);
		} else {
			std::cout<<"wrong\n";
			continue;
		}
	}
	outputmodule(q);
	return 0;
}
