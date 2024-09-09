#include <iostream>
#include <cstdlib>
#include "Student.h"

using namespace std;

class Grade {
    Student** a;
    int num;
    float grade;
    string classname;

    public:
        Grade (string name, int num) {
            this->classname = name;
            this->num = num;

            a = (Student**)malloc(num * sizeof(Student*));
            for (int i = 0; i < num; i++) {
                a[i] = new Student();
            }
        }

        void addStudents() {
            for (int i = 0; i < num; i++) {
                cout << "Student " << i+1 << endl;
                cout << "Name: ";
                cin >> a[i]->name;
                cout << "ID Number: ";
                cin >> a[i]->id_number;
                cout << "Enter how many subjects you have: ";
                cin >> a[i]->num;

                a[i]->subs = new Subject[a[i]->num];
            }
        }

        void addSub() {
            for (int i = 0; i < num; i++) {
                system("cls");
                cout << "Student " << a[i]->name << endl;
                for (int j = 0; j < a[i]->num; j++) {
                    cout << "Please enter your scores in Subject " << j+1 << endl;
                    cout << "Prelim Score: ";
                    cin >> a[i]->subs[j].prelim_score;
                    cout << "Midterm Score: ";
                    cin >> a[i]->subs[j].mid_score;
                    cout << "PreFinal Score: ";
                    cin >> a[i]->subs[j].prefi_score;
                    cout << "Final Score: ";
                    cin >> a[i]->subs[j].final_score;
                }
            }
        }

        void calculateMidtermGrade() {
            for (int i = 0; i < num; i++) {
                float sum = 0;
                for (int j = 0; j < a[i]->num; j++) {
                    sum = a[i]->subs[j].prelim_score + a[i]->subs[j].mid_score;
                    a[i]->subs[j].midterm_grade = sum / 2.0;
                }
            }
        }

        void calculateFinalGrade() {
            for (int i = 0; i < num; i++) {
                float sum = 0;
                for (int j = 0; j < a[i]->num; j++) {
                    sum = a[i]->subs[j].prefi_score + a[i]->subs[j].final_score;
                    a[i]->subs[j].final_grade = sum / 2.0;
                }   
            }
        }

        void calculateAverage() {
            for (int i = 0; i < num; i++) {
                float plus = 0;
                for (int j = 0; j < a[i]->num; j++) {
                    plus = a[i]->subs[j].midterm_grade + a[i]->subs[j].final_grade;
                    a[i]->subs[j].average = plus / 2.0;
                }  
            }
        }

        void calculateOverallAvg() {  
            for (int i = 0; i < num; i++) {
                float sum = 0;
                for (int j= 0; j < a[i]->num; j++) {
                    sum += a[i]->subs[j].average;
                    a[i]->average = sum / a[i]->num;
                }
            }
        }

        void isPassed() {
            for (int i = 0; i < num; i++) {
                if (a[i]->average >= 75) {
                    a[i]->passed = 1;
                } else {
                    a[i]->passed = 0;
                }
            }
        }

        void print() {
            for (int i = 0; i < num; i++) {
                cout << i+1 << ". " <<  a[i]->name << endl;
                cout << "Average Grade: " << a[i]->average << endl;
                if (a[i]->passed == 1) {
                    cout << "PASSED" << endl;
                } else {
                    cout << "FAILED" << endl;
                }
            }
        }

        void ranking() {
            cout << "Top " << num << endl;
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < num; j++) {
                    if (a[i]->average > a[j]->average) {
                        Student *temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                    }
                }
            }
        }
};
