#include <stdio.h>

struct Student {
    const char* m_StudentName;
    int m_Age;
    char m_Grade;
};

// Function to initialize a Student struct in C
struct Student create_student(const char* name, int age, char grade) {
    struct Student student;
    student.m_StudentName = name;
    student.m_Age = age;
    student.m_Grade = grade;
    return student;
}

int main() {
    struct Student student = create_student("John Doe", 20, 'A');
    printf("Name: %s, Age: %d, Grade: %c\n", student.m_StudentName, student.m_Age, student.m_Grade);
    return 0;
}
