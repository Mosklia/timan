#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>

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
    task& operator=(const task &t);

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

    /**
     * @brief Read a task from istream @a in.
     * 
     * @param in Source istream.
     * @param tk Variable to be write.
     * @return std::istream&
     */
    friend std::istream& operator>>(std::istream &in, task &tk);

    // void outf(std::ofstream &out)
    // {
    //     out << name << " " << level << " " << ddl.tm_year << " " << ddl.tm_mon << " " << ddl.tm_mday << "\n";
    // }
    // void out()
    // {
    //     std::cout << "task name:" << name << "   level:" << level << "   ";
    //     printf("deadline:%04d-%02d-%02d", ddl.tm_year, ddl.tm_mon, ddl.tm_mday);
    // }

    /**
     * @brief Write a task to ostream @a out.
     * 
     * @param out Ostream to write.
     * @param tk Source task.
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ofstream &out, const task &tk);
};
