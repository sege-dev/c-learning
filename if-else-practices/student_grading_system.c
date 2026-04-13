#include <stdio.h>

int main() {
    int attendence;
    float midterm_grade, final_grade, average;
    char letter_grade;

    printf("Please enter the midterm exam grade: ");
    scanf("%f", &midterm_grade);

    printf("Please enter the final exam grade: ");
    scanf("%f", &final_grade);

    printf("Please enter the attendance: ");
    scanf("%d", &attendence);

    average = (midterm_grade * 0.4) + (final_grade * 0.6);

    if (attendence > 10) {
        printf("FAILED due to absence! (Days: %d)\n", attendence);
        return 0;
    }

    if (average >= 90 && average <= 100) {
        letter_grade = 'a';
    } 
    else if (average >= 80) {
        letter_grade = 'b';
    } 
    else if (average >= 70) {
        letter_grade = 'c';
    } 
    else if (average >= 0) {
        letter_grade = 'd';
    } 
    else {
        printf("Invalid grades\n");
    }

    if (letter_grade == 'a' && attendence == 0) {
        printf("Congratulations! You won a Full Scholarship!\n");
    } 
    else if ((letter_grade == 'a' || letter_grade == 'b') && attendence < 3) {
        printf("Half Scholarship awarded!\n");
    } 
    else if (letter_grade == 'b') {
        printf("Your letter grade is: %c\n", letter_grade);
    } 
    else if (letter_grade == 'c') {
        printf("Your letter grade is: %c\n", letter_grade);
    } 
    else if (letter_grade == 'd') {
        printf("Your letter grade is: %c\n", letter_grade);
    }

    return 0;
}