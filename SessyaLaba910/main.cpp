#include <iostream>

using namespace std;
#include "structures.h"
#include "file_reader.h"
#include "constants.h"
#include "manipulations.h"
#include "process.h"
#include <locale>


int main()
{
    setlocale(LC_ALL, "Russian");
    student_record* stdrec[MAX_FILE_ROWS_COUNT];
    int size;
    int session_length = 0;
    try
    {
        read("data.txt", stdrec, size);
        for (int i = 0; i < size; i++)
        {
            printStudentRecord(stdrec[i]);
        }
        
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    bool rpts = true;
    int rpts_value = 0;
    while (rpts == true)
    {
        cout << "Что делать дальше? " << endl << "1. Вывести всех студентов и их оценки по дисциплине «History of Belarus» " << endl << "2. Вывести всех студентов и дисциплины с оценками выше 7 баллов. ";
        cout << endl << "3. Сортировка вставками  " << endl << "4. Сортировка слиянием " << endl << "5. Выход " << endl << "6. Юнит Тест" << endl;

        cin >> rpts_value;
        switch (rpts_value)
        {
        case 1: printStudentsAndGrades(stdrec, size);
            break;
        case 2:printStudentsWithHighGrades(stdrec, size, 7);
            break;
        case 3:
        {
            cout << "Какой критерий?" << endl << "1. По возрастанию фамилии студента    2. По возрастанию названия дициплины, а в рамках одной дисциплины по убыванию оценки";
            int sort_id;
            cin >> sort_id;
            insertionSort(stdrec, size, sort_id);
            for (int i = 0; i < size; i++)
            {
                printStudentRecord(stdrec[i]);
            }
            break;
        }

        case 4:
        {
            cout << "Какой критерий?" << endl << "1. По возрастанию фамилии студента    2. По возрастанию названия дициплины, а в рамках одной дисциплины по убыванию оценки";
            int sort_id;
            cin >> sort_id;
            mergeSort(stdrec, size, sort_id);
            for (int i = 0; i < size; i++)
            {
                printStudentRecord(stdrec[i]);
            }
            break;
        }
        case 5:
        {
            rpts = false;
            break;
        }
        case 6:
        {
            session_length = calculateSessionDuration(stdrec, size);
            cout << "Длина сессии -> " << session_length << " Дней" << endl;
            break;
        }
        default: cout << "Invalid Input";
        }
    }
    for (int i = 0; i < size; i++)
    {
        delete stdrec[i];
    }
    return 0;
}