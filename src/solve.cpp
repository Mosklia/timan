#include "solve.h"
#include "task.h"

void inputmodule(std::priority_queue<task> &q) {
	task task_;
	std::ifstream in("list.txt", std::ios::in);
	while(in>>task_.name>>task_.level>>task_.ddl.tm_year>>task_.ddl.tm_mon>>task_.ddl.tm_mday) q.push(task_);
	in.close();
	std::cout<<"System is ready.\n";
}
void outputmodule(std::priority_queue<task> &q) {
	std::ofstream out("list.txt", std::ios::out);
	task task_;
	while(!q.empty()) {
		task_=q.top();
		task_.outf(out);
		q.pop();
	}
}

//command
void add(std::priority_queue<task> &q) {
	task task_;
	std::cout<<"Please write down the task:\nname level deadline(year month day)\n";
	task_.in();
	q.push(task_);
}
void check(std::priority_queue<task> &q) {
	if(q.empty()) std::cout<<"You have no task.\n";
	else {
		task task_=q.top();
		task_.out();
		std::string c;
		std::cout<<"\nsolved?\n[y],[n]\n";
		std::cin>>c;
		if(c=="y") q.pop();
	}
}
void list(std::priority_queue<task> &q) {
	std::priority_queue<task> qq;
	task task_;
	while(!q.empty()) {
		task_=q.top();
		q.pop();
		task_.out();
		putchar('\n');
		qq.push(task_);
	}
	while(!qq.empty()) {
		q.push(qq.top());
		qq.pop();
	}
}
