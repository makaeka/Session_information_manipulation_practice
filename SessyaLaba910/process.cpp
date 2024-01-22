#include <iostream>
#include "structures.h" // Assuming the definition of student_record is in new_data.h

// Function to calculate the number of days from a given date
int calculateDaysInDate(const new_date& date) {
    // Logic to convert date to days (You may need to adjust this based on your specific requirements)
    // For simplicity, let's assume each month has 30 days for the calculation
    return date.year * 360 + date.month * 30 + date.day;
}

// Function to compare two dates
bool compareDates(const new_date& date1, const new_date& date2) {
    if (date1.year != date2.year) {
        return date1.year < date2.year;
    }
    if (date1.month != date2.month) {
        return date1.month < date2.month;
    }
    return date1.day < date2.day;
}

// Function to calculate the session duration
int calculateSessionDuration(student_record* stdrec[], int size) {
    new_date earliestStart = stdrec[0]->exam_date;
    new_date latestEnd = stdrec[0]->exam_date;

    for (int i = 1; i < size; ++i) {
        if (compareDates(stdrec[i]->exam_date, earliestStart)) {
            earliestStart = stdrec[i]->exam_date;
        }
        if (compareDates(latestEnd, stdrec[i]->exam_date)) {
            latestEnd = stdrec[i]->exam_date;
        }
    }

    int session_duration = calculateDaysInDate(latestEnd) - calculateDaysInDate(earliestStart) + 1;

    return session_duration;
}