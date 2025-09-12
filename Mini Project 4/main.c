#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uni.h"

int main() {
    int choice;

    do {
        draw_box();
        gotoxy(28,7);  printf("1. Add Student");
        gotoxy(28,9);  printf("2. Display Students");
        gotoxy(28,11); printf("3. Add Course");
        gotoxy(28,13); printf("4. Display Courses");
        gotoxy(28,15); printf("5. Search Student By ID");
        gotoxy(28,17); printf("6. Modify Course Grade");
        gotoxy(28,19); printf("0. Exit");
        gotoxy(3,22);   printf("Choose an option : ");
        gotoxy(22,22);  scanf("%d", &choice);

        switch(choice) {
            case 1: draw_box(); addStudent(); break;
            case 2: draw_box(); displayStudents(); break;
            case 3: draw_box(); addCourse(); break;
            case 4: draw_box(); displayCourses(); break;
            case 5: draw_box(); searchStudentByID(); break;
            case 6: draw_box(); modifyCourseGrade(); break;
            case 0: draw_box(); gotoxy(3,22); printf("GOOD BYE!"); break;
            default: printf("Invalid choice.");
        }

    } while (choice != 0);

    gotoxy(3,25); return 0;
}
