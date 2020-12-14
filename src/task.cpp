#include "timeman.h"
#include "task.h"

task &task::operator=(const task &t)
{
	name = t.name;
	ddl = t.ddl;
	level = t.level;

	return *this;
}

int task::getpriority() const
{
	int value = 0;
	int t = ddl - gettime();

	// Increase priority when ddl is near.
	if (t <= 2)
	{
		value += 10000 * (3 - t);
	}

	value += level;
	return value;
}

bool task::operator<(const task &t) const
{
	return getpriority() < t.getpriority();
}

std::istream &operator>>(std::istream &in, task &tk)
{
	in >> tk.name >> tk.level >> tk.ddl.tm_year >> tk.ddl.tm_mon >> tk.ddl.tm_mday;
	return in;
}

std::ostream &operator<<(std::ostream &out, const task &tk)
{
	out << tk.name << ' ' << tk.level << ' ' << tk.ddl.tm_year << ' '
		<< tk.ddl.tm_mon << ' ' << tk.ddl.tm_mday;
	return out;
}

void task::printTo(std::ostream &out) const
{
	out << "Task name: " << name << "\nLevel: " << level << '\n';
	out << "Deadline: ";
	out << std::setfill('0') << std::setw(4) << ddl.tm_year
		<< '-' << std::setw(2) << ddl.tm_mon
		<< '-' << std::setw(2) << ddl.tm_mday
		<< std::endl;
	out << std::setfill(' ');
	// printf("deadline:%04d-%02d-%02d", ddl.tm_year, ddl.tm_mon, ddl.tm_mday);
}