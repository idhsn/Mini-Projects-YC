#ifndef UNI_H
#define UNI_H

void gotoxy(int x, int y);
void addStudent();
void displayStudents();
void addCourse();
void displayCourses();
void searchStudentByID();
void modifyCourseGrade();
void draw_box();

#define MAX_STUDENTS 2
#define MAX_COURSES 2

struct Student {
    int id, age;
    char lastName[30], firstName[30] ;
    float average;
};

struct Course {
    char code[10], name[50];
    int credits;
    float grade;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

struct Course courses[MAX_COURSES];
int courseCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        gotoxy(23,4); printf("Max number of students reached");
        gotoxy(3,22);printf("Press Enter to continue ...");
        getchar();
        return;
    }else{
    struct Student s;

    gotoxy(3,22); printf("Enter The Values :                                                        ");

    gotoxy(20,7);  printf("Enter student ID : ");
    gotoxy(22,22); scanf("%d", &s.id);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,7);  printf("%d", s.id);

    gotoxy(20,9);  printf("Enter last name : ");
    gotoxy(22,22); scanf("%s", s.lastName);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,9);  printf("%s", s.lastName);

    gotoxy(20,11); printf("Enter first name : ");
    gotoxy(22,22); scanf("%s", s.firstName);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,11); printf("%s", s.firstName);

    gotoxy(20,13); printf("Enter age : ");
    gotoxy(22,22); scanf("%d", &s.age);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,13); printf("%d", s.age);

    gotoxy(20,15); printf("Enter average grade : ");
    gotoxy(22,22); scanf("%f", &s.average);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,15); printf("%.2f", s.average);

    students[studentCount] = s;
    studentCount++;
    gotoxy(25,4);  printf("Student added successfully");
    gotoxy(3,22);  printf("Press Enter to continue ...");
    getchar();
    getchar();

    }
}

void displayStudents() {
    int i;
    if (studentCount == 0) {
    gotoxy(26,4);  printf("No students registered.");
    gotoxy(3,22);  printf("Press Enter to continue ...");
        getchar();
        return;
    }else{
    for (i = 0; i < studentCount; i++) {
    gotoxy(10,i+6); printf("ID: %d | Name: %s %s | Age: %d | Average: %.2f",
               students[i].id, students[i].firstName, students[i].lastName,
               students[i].age, students[i].average);
        }
    gotoxy(3,22);printf("Press Enter to continue ...");
    getchar();
    }
}

void addCourse() {
    if (courseCount >= MAX_COURSES) {
        gotoxy(23,4); printf("Max number of courses reached");
        gotoxy(3,22);printf("Press Enter to continue ...");
        getchar();
        return;
    }else{
    struct Course c;

    gotoxy(3,22);printf("Enter The Values :                                                        ");

    gotoxy(20,7);printf("Enter course code : ");
    gotoxy(22,22);scanf("%s", c.code);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,7);printf("%s",c.code );

    gotoxy(20,9);printf("Enter course name : ");
    gotoxy(22,22);scanf(" %s", c.name);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,9);printf("%s",c.name);

    gotoxy(20,11);printf("Enter credits : ");
    gotoxy(22,22);scanf("%d", &c.credits);
    gotoxy(22,22); printf("                                                       ");
    gotoxy(40,11);printf("%d",c.credits);

    gotoxy(20,13);printf("Enter grade : ");
    gotoxy(22,22);scanf("%f", &c.grade);
    gotoxy(22,22);printf("                                                       ");
    gotoxy(40,13);printf("%.2f",c.grade);

    courses[courseCount] = c;
    courseCount++;
    gotoxy(25,4);printf("Course added successfully!");
    gotoxy(3,22);printf("Press Enter to continue ...");
    getchar();
    getchar();
    }
}

void displayCourses() {
    int i;
    if (courseCount == 0) {
        gotoxy(26,4);  printf("No courses available.");
        gotoxy(3,22);  printf("Press Enter to continue ...");
        getchar();
        return;
    } else {
        for (i = 0; i < courseCount; i++) {
            gotoxy(10, i + 6);
            printf("Code: %s | Name: %s | Credits: %d | Grade: %.2f",
                   courses[i].code, courses[i].name,
                   courses[i].credits, courses[i].grade);
        }
        gotoxy(3,22);printf("Press Enter to continue ...");
        getchar();
    }
}

void searchStudentByID() {
    int id, i, found = 0;
    gotoxy(3,22);printf("Student ID : ");
    gotoxy(16,22);scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            gotoxy(10,6);
            printf("ID: %d | Name: %s %s | Age: %d | Average: %.2f",
                   students[i].id, students[i].firstName, students[i].lastName,
                   students[i].age, students[i].average);
            break;
        }
    }
    if (found == 0) {
        gotoxy(10,6);printf("Student with ID %d not found.", id);
    }
    gotoxy(3,22); printf("Press Enter to continue ...");
    getchar(); getchar();
}

void modifyCourseGrade() {
    int id, i, found = 0;
    float newGrade;

    gotoxy(3,22);
    printf("Enter student ID to modify grade:                                                    ");
    gotoxy(39,22);
    scanf("%d", &id);

    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;

            gotoxy(10,6);
            printf("Current average for %s %s: %.2f",
                   students[i].firstName, students[i].lastName, students[i].average);

            gotoxy(3,22);
            printf("Enter new average grade:                                                             ");
            gotoxy(28,22);
            scanf("%f", &newGrade);

            students[i].average = newGrade;

            gotoxy(10,7);
            printf("Average updated successfully!");
            break;
        }
    }

    if (found == 0) {
        gotoxy(10,6);
        printf("Student with ID %d not found.", id);
    }

    gotoxy(3,22);
    printf("Press Enter to continue...              ");
    getchar(); getchar();

}



void draw_box()
{
    int i;
    system("cls");
    for (i = 2; i <= 75; i++)
    {
        gotoxy(i, 1);   printf("%c", 205);  // top
        gotoxy(i, 3);   printf("%c", 205);  // middle top
        gotoxy(i, 21);  printf("%c", 205);  // middle bottom
        gotoxy(i, 23);  printf("%c", 205);  // bottom
    }

    for (i = 2; i <= 22; i++)  // updated from 18 -> 22
    {
        gotoxy(1, i);   printf("%c", 186);   // left
        gotoxy(75, i);  printf("%c", 186);   // right
    }

    for (i = 21; i <= 54; i++)
    {
        gotoxy(i, 5);   printf("%c", 205);   // search thingy
    }

    // Corners and joints
    gotoxy(1, 1);    printf("%c", 201);     // top left
    gotoxy(75, 1);   printf("%c", 187);     // top right
    gotoxy(1, 3);    printf("%c", 204);     // middle top left
    gotoxy(75, 3);   printf("%c", 185);     // middle top right
    gotoxy(1, 21);   printf("%c", 204);     // middle bottom left
    gotoxy(75, 21);  printf("%c", 185);     // middle bottom right
    gotoxy(1, 23);   printf("%c", 200);     // bottom left
    gotoxy(75, 23);  printf("%c", 188);     // bottom right

    gotoxy(1,2);     printf("%c", 32);      // space
    gotoxy(75,2);    printf("%c", 32);      // space
    gotoxy(20,3);    printf("%c", 203);     // thingy left down
    gotoxy(55,3);    printf("%c", 203);     // thingy right down
    gotoxy(20,4);    printf("%c", 186);     // thingy left down
    gotoxy(55,4);    printf("%c", 186);     // thingy right down
    gotoxy(20,5);    printf("%c", 200);     // thingy left left
    gotoxy(55,5);    printf("%c", 188);     // thingy right right
    gotoxy(23,2);    printf(" University Management System ");
}


#endif

