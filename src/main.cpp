#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

#include "task.h"

std::priority_queue<task>q;
int main() {
	task tas;
	std::ifstream in("list.txt", std::ios::in);
	while(in>>tas.name>>tas.level>>tas.ddl.tm_year>>tas.ddl.tm_mon>>tas.ddl.tm_mday) q.push(tas);
	in.close();
	std::string command;
	std::cout<<"System is ready.\n";
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
			std::ifstream fin("list.txt", std::ios::in);
			while(fin>>tas.name>>tas.level>>tas.ddl.tm_year>>tas.ddl.tm_mon>>tas.ddl.tm_mday) {
				tas.out();
				putchar('\n');
			}
			fin.close();
		} else {
			std::cout<<"wrong\n";
			continue;
		}
	}
	std::ofstream out("list.txt", std::ios::out);
	while(!q.empty()) {
		tas=q.top();
		tas.outf(out);
		q.pop();
	}
	return 0;
}
