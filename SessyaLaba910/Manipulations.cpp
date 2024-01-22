#include <iostream>
#include "structures.h"
#include "file_reader.h"
#include "constants.h"
#include <algorithm>

using namespace std;

void printStudentRecord(student_record* record)
{
    cout << record->full_name.surname << "  ";
    cout << record->full_name.first_name << "  ";
    cout << record->full_name.patronymic << "  ";
    cout << record->exam_date.day << ".";
    cout << record->exam_date.month << ".";
    cout << record->exam_date.year << "  ";
    cout << record->grade << "  ";
    cout << record->discipline << "  ";
    cout << '\n';
}

void printStudentsAndGrades(student_record* array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(array[i]->discipline, "History of Belarus") == 0)
        {
            printStudentRecord(array[i]);
        }
    }
}

void printStudentsWithHighGrades(student_record* array[], int size, int minGrade)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i]->grade > minGrade)
        {
            printStudentRecord(array[i]);
        }
    }
}

bool SortCase(student_record* a, student_record* b, int sort_id)
{
    switch (sort_id)
    {
    case 1:
        return strcmp(a->full_name.surname, b->full_name.surname) < 0;
    case 2:
        if (strcmp(a->discipline, b->discipline) != 0)
        {
            return strcmp(a->discipline, b->discipline) < 0;
        }
        return a->grade > b->grade;
    default:
        return false;
    }
}

void insertionSort(student_record* arr[], int size, int sort_id)
{
    for (int i = 1; i < size; i++)
    {
        student_record* current = arr[i];
        int j = i - 1;
        while (j >= 0 && !SortCase(arr[j], current, sort_id))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void merge(student_record* arr[], int l, int m, int r, int sort_id)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    student_record** L = new student_record * [n1];
    student_record** R = new student_record * [n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (SortCase(L[i], R[j], sort_id))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    delete[] L;
    delete[] R;
}

void mergeSortHelper(student_record* arr[], int l, int r, int sort_id)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, sort_id);
        mergeSortHelper(arr, m + 1, r, sort_id);
        merge(arr, l, m, r, sort_id);
    }
}

void mergeSort(student_record* arr[], int size, int sort_id)
{
    mergeSortHelper(arr, 0, size - 1, sort_id);
}