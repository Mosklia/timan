#pragma once
#include <ctime>

/**
 * @brief Get current time.
 * 
 * @return tm Current time.
 */
tm gettime();

/**
 * @brief Check if the given year is a leap year.
 * 
 * @param y Number of the year to be checked.
 * @return true  @a y is a leap year.
 * @return false @a y is not a leap year.
 */
bool checkforleap(int y);

/**
 * @brief Calculate how many days the given month has.
 * 
 * @param m Number of the month to be calculated.
 * @return int Length of the month.
 */
int getmonthlen(int m);

/**
 * @brief Compare two given time.
 * 
 * @param t1 First time to be compared.
 * @param t2 Second time to be compared.
 * @return true @a t1 is earlier than @a t2.
 * @return false @a t1 is not earlier than @a t2.
 */
bool operator<(tm t1, tm t2);

/**
 * @brief Calculate difference between two time (by days).
 * 
 * @param t1 First time.
 * @param t2 Second time.
 * @return int @a t2 - @a t1 by day
 */
int operator-(tm t1, tm t2); //计算时间差（精确到天）

#include "timeman.cpp"