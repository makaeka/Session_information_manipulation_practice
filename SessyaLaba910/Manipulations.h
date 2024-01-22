#pragma once
#include "structures.h"

void printStudentRecord(student_record* record);
void printStudentsAndGrades(student_record* array[], int size);
void printStudentsWithHighGrades(student_record* array[], int size, int minGrade);
bool SortCase(student_record* a, student_record* b, int sort_id);
void insertionSort(student_record* arr[], int size, int sort_id);
void mergeSortHelper(student_record* arr[], int l, int r, int sort_id);
void mergeSort(student_record* arr[], int size, int sort_id);