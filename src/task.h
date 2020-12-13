#include <string>
#include <ctime>
#include <iostream>

/**
 * @brief Struct task -- Info about a task.
 * 
 */
struct task
{
    std::string name;
    tm ddl;
    int level;

    /**
     * @brief Assign the value of @a t to this task.
     * 
     * @param t Source task.
     * @return task& A reference to *this.
     */
    task &operator=(const task &t);

    /**
     * @brief Get the priority of this task.
     * 
     * @return int 
     */
    int getpriority() const;

    /**
     * @brief Compare priority of tasks.
     * 
     * @param t A task to be compared to @a *this.
     * @return true @a t has greater priorty than @a *this 
     * @return false @a t has lower priorty than @a *this 
     */
    bool operator<(const task &t) const;

    void in()
    {
        std::cin >> name >> level >> ddl.tm_year >> ddl.tm_mon >> ddl.tm_mday;
    }
    void outf(std::ofstream &out)
    {
        out << name << " " << level << " " << ddl.tm_year << " " << ddl.tm_mon << " " << ddl.tm_mday << "\n";
    }
    void out()
    {
        std::cout << "task name:" << name << "   level:" << level << "   ";
        printf("deadline:%04d-%02d-%02d", ddl.tm_year, ddl.tm_mon, ddl.tm_mday);
    }
};
