// Diego Martinez
// Created: Nov 14, 2024

#include <iostream>
using namespace std;

class Course
{
public:
    Course(const string& courseName, int capacity);
    Course(const Course& copy);
    ~Course();
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;
    void clear();

private:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
};

Course::Course(const string& courseName, int capacity) {
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity];
}

Course::Course(const Course& copy) {
    numberOfStudents = copy.numberOfStudents;
    capacity = copy.capacity;
    courseName = copy.courseName;
    students = new string[capacity];
    for (int i = 0; i < numberOfStudents; i++) {
        students[i] = copy.students[i];
    }
}

Course::~Course() {
    delete[] students;
}

string Course::getCourseName() const {
    return courseName;
}

void Course::addStudent(const string& name) {
    // Work here
    // If at capacity
    if (numberOfStudents == capacity) {
        capacity++;                                  // Add one to the capacity
        // Make a new string with the new capacity
        string* temparr = new string[capacity];
        // Move all students into the new string
        for (int i = 0; i < numberOfStudents; i++) {
            temparr[i] = *(students + i);
        }
        // Update students
        delete[] students;
        students = temparr;
    }
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name) {
    // Looks for the given student name in the list of students
    for (int i = 0; i < numberOfStudents; i++) {
        if (name == students[i]) {
            // Once it is found, move all students accordingly
            for (int j = i; j < numberOfStudents-1; j++) {
                students[j] = students[j + 1];
            }
            --numberOfStudents;  // Update the number of students
            break;
        }
    }
}

string* Course::getStudents() const {
    return students;
}

int Course::getNumberOfStudents() const {
    return numberOfStudents;
}

void Course::clear() {
    // Work here
    delete[] students;                  // Deletes student array
    students = new string[capacity];    // creates empty string array of the same size
    numberOfStudents = 0;               // updates numberOfStudents
}

int main() {
    string const CNAME = "facts";
    string const S1 = "Ben";
    string const S2 = "Jose";
    string const S3 = "Bhav";
    Course idk = Course(CNAME, 2);
    idk.addStudent(S1);
    idk.addStudent(S2);
    idk.addStudent(S3);
    idk.dropStudent(S2);
    cout << idk.getNumberOfStudents() << endl;
    string* list = new string[idk.getNumberOfStudents()];
    list = idk.getStudents();
    for (int i = 0; i < idk.getNumberOfStudents(); i++) {
        cout << list[i] << endl;
    }

    return 0;
}

// Output
/*
    2
    Ben
    Bhav
*/