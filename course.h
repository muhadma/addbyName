#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Course {
    Student** students;
    string topic;
    int size;
    int capacity;
    int yearlvl;
    string program;
    
    public: 
        Course(string topic) : topic(topic), size(0), yearlvl(0), program("") {
            capacity = 5;
            students = (Student**)malloc(capacity * sizeof(Student*));  // Allocate memory using new[]
        }

        void addStudent(Student* s) {
            if (size == capacity) {
                int newCapacity = capacity + (capacity / 2);
                students = (Student**)realloc(students, newCapacity * sizeof(Student*));
                capacity = newCapacity;
            }
            int index = size;
            for (int i = 0; i < size; i++) {
                if (s->name.compare(students[i]->name) < 0) {
                    index = i;
                    break;
                }
            }

            for (int j = size; j > index; j--) {
                students[j] = students[j-1];
            }

            students[index] = s;
            size++;
        }
        
        void print() {
            cout << "Student size: " << size << "/" << capacity << endl;
            for (int i = 0; i < capacity; i++) {
                if (i >= size) {
                    cout << i + 1 << " (none) " << endl;
                } else {
                    cout << i + 1 << ": " << students[i]->name << " " 
                         << students[i]->program << " " 
                         << students[i]->year_level << endl;
                }
            }
        }
};
