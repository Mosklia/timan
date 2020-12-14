#ifndef TASK
#define TASK


#include <string>
#include <ctime>
#include <iostream>
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
        std::cin >>name>>level;
        char c=getchar();
        int a[3]={0,0,0},i;
        for(i=0;i<3;i++){
            if(c=='\n')break;
            while(c==' ') c=getchar();
            while(c>='0'&&c<='9'){
                a[i]*=10;
                a[i]+=c-'0';
                c=getchar();
            }
        }
        ddl.tm_mday=a[0];
        ddl.tm_mon=a[1];
        ddl.tm_year=a[2];
        if(i<3) ddl.tm_year=gettime().tm_year;
        if(i<2) ddl.tm_mon=gettime().tm_mon;
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
#endif
