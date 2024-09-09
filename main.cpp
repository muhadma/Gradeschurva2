#include <iostream>
#include <cstdlib>
#include "Grade.h"

using namespace std;

int main() {
    int num;
    cout << "Enter how many students in your class: ";
    cin >> num;
    string name;
    cout << "Enter class name: ";
    cin >> name;

    Grade* n1 = new Grade(name, num);

    n1->addStudents();
    n1->addSub();
    n1->calculateMidtermGrade();
    n1->calculateFinalGrade();
    n1->calculateAverage();
    n1->calculateOverallAvg();
    n1->isPassed();
    n1->print();
}