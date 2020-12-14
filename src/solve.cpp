#include "solve.h"
#include "task.h"

void inputmodule(task &tas,std::priority_queue<task> &q) {
	std::ifstream in("list.txt", std::ios::in);
	while(in>>tas.name>>tas.level>>tas.ddl.tm_year>>tas.ddl.tm_mon>>tas.ddl.tm_mday) q.push(tas);
	in.close();
	std::cout<<"System is ready.\n";
}
void outputmodule(task &tas,std::priority_queue<task> &q) {
	std::ofstream out("list.txt", std::ios::out);
	while(!q.empty()) {
		tas=q.top();
		tas.outf(out);
		q.pop();
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
