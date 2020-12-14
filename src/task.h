#ifndef TASK
#define TASK


#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "timeman.h"

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

    /**
     * @brief Write a task to ostream @a out.
     * 
     * @param out Ostream to write.
     * @param tk Source task.
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream &out, const task &tk);

    // void outf(std::ofstream &out)
    // {
    //     out << name << " " << level << " " << ddl.tm_year << " " << ddl.tm_mon << " " << ddl.tm_mday << "\n";
    // }

    /**
     * @brief Print @a *this to ostream @a out, ending with @a end.
     * 
     * @param out Output stream.
     * @param end Ending character(s).
     */
    void printTo(std::ostream &out) const;
};

#endif