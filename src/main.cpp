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
	task tas;
	inputmodule(tas,q);
	std::string command;
	while(1) {
		std::cout<<">";
		std::cin>>command;
		if(command=="exit") break;
		else if(command=="add") {
			std::cout<<"Please write down the task:\nname level deadline(year month day)\n";
			tas.in();
			q.push(tas);
		} else if(command=="check") {
			if(q.empty()) std::cout<<"You have no task.\n";
			else {
				tas=q.top();
				tas.out();
				std::string c;
				std::cout<<"\nsolved?\n[y],[n]\n";
				std::cin>>c;
				if(c=="y") q.pop();
			}
		} else if(command=="list") {
			list(q);
		} else {
			std::cout<<"wrong\n";
			continue;
		}
	}
	outputmodule(tas,q);
	return 0;
}
