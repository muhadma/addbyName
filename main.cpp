#include <iostream>
#include "course.h"

using namespace std;

int main() {
    char op;
    int count;
    Course* ab = new Course("DSA");
    string name;
    Student* s;
    do {
        cout << "Op: ";
        cin >> op;
        
        switch(op) {
            case 'a':
                s = new Student();
                cout << "Enter name: ";
                cin >> s->name;
                cout << "Program: ";
                cin >> s->program;
                cout << "Year Level: ";
                cin >> s->year_level;
                
                ab->addStudent(s);
                break;
            case 'p':
                ab->print();
                break;
            case 'x':
                return 0;
        }
        
    }while (op != 'x');
}