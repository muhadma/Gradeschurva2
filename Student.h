#include <iostream>
#include <string>

using namespace std;

struct Subject {
    int prelim_score;
    int mid_score;
    int prefi_score;
    int final_score;
    float midterm_grade;
    float final_grade;
    float average;
};

struct Student {
    int id_number;
    int passed; 
    int num;
    string name;
    float average;
    Subject* subs;
};