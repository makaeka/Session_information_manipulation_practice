#include "file_reader.h"
#include "constants.h"
#include <iostream>
#include <fstream>
#include <cstring>



name_parts parseName(char* str)
{
    name_parts result;
    char* context = NULL;
    char* token = strtok_s(str, ",", &context);
    if (token) {
        strncpy_s(result.surname, token, MAX_STRING_SIZE - 1);
        result.surname[MAX_STRING_SIZE - 1] = '\0'; // Ensure null-termination
    }
    token = strtok_s(NULL, ",", &context);
    if (token) {
        strncpy_s(result.first_name, token, MAX_STRING_SIZE - 1);
        result.first_name[MAX_STRING_SIZE - 1] = '\0'; // Ensure null-termination
    }
    token = strtok_s(NULL, " ", &context);
    if (token) {
        strncpy_s(result.patronymic, token, MAX_STRING_SIZE - 1);
        result.patronymic[MAX_STRING_SIZE - 1] = '\0'; // Ensure null-termination
    }
    return result;
}
new_date convertDate(char* str)
{
    new_date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, student_record* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            student_record* item = new student_record;
            file >> tmp_buffer; // Убираем точку в начале
            file >> tmp_buffer;
            item->full_name = parseName(tmp_buffer);
            file >> tmp_buffer;
            item->exam_date = convertDate(tmp_buffer);
            file >> item->grade;
            file.ignore(); // skip the newline character
            file.getline(tmp_buffer, MAX_STRING_SIZE);
            strncpy_s(item->discipline, tmp_buffer, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }

}
