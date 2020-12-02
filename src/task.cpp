#include "task.h"
#include "timeman.h"

task& task::operator=(const task& t)
{
	name  = t.name;
	ddl   = t.ddl;
	level = t.level;

    return *this;
}

int task::getpriority() const
{
	int value = 0;
	int t = ddl - gettime();

    // Increase prrioity when ddl is near.
	if (t <= 2)
    {
        value+=10000*(3-t);
    }

	value+=level;
	return value;
}

bool task::operator<(const task &t) const
{
    return getpriority() < t.getpriority();
}

std::istream& operator>>(std::istream &in, task &tk)
{
	in >> tk.name >> tk.level >> tk.ddl.tm_year >> tk.ddl.tm_mon >> tk.ddl.tm_mday;
	return in;
}

std::ostream& operator<<(std::ostream &out, const task &tk)
{
	out << tk.name << tk.level << tk.ddl.tm_year << tk.ddl.tm_mon << tk.ddl.tm_mday;
	return out;
}