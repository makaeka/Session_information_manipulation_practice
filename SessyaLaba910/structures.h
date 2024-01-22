#ifndef NEW_DATA_H
#define NEW_DATA_H

#include "constants.h"

struct new_date
{
    int day;
    int month;
    int year;
};

struct name_parts
{
    char surname[MAX_STRING_SIZE];
    char first_name[MAX_STRING_SIZE];
    char patronymic[MAX_STRING_SIZE];
};

struct student_record
{
    name_parts full_name;
    new_date exam_date;
    int grade;
    char discipline[MAX_STRING_SIZE];
};

#endif