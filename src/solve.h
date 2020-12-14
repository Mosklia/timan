#ifndef SOLVE
#define SOLVE

#include<queue>

#include "task.h"

void inputmodule(std::priority_queue<task> &q);
void outputmodule(std::priority_queue<task> &q);
//command
void add(std::priority_queue<task> &q);
void check(std::priority_queue<task> &q);
void list(std::priority_queue<task> &q);

#endif
