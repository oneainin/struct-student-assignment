#include <iostream>
#include <string>
using namespace std;

struct Subject {
    string name;
    int credit;
    int mark;
    char grade;
};

struct Student {
    string name;
    int age;
    Subject subjects[10];
    int subjectCount;
    float cpa;
};

char getGrade(int mark) {
    if (mark >= 80) return 'A';
    else if (mark >= 60) return 'B';
    else if (mark >= 40) return 'C';
    else return 'D';
}

int main() {
    Student students[10];
    int studentCount;

    cout << "Number of students (max 10): ";
    cin >> studentCount;

    if (cin.fail() || studentCount < 1 || studentCount > 10) {
        cout << "INVALID: maximum students is 10." << endl;
        return 0;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "\n--- Student " << i + 1 << " ---" << endl;
        cout << "Name: ";
        cin >> ws;
        getline(cin, students[i].name);

        cout << "Age: ";
        cin >> students[i].age;
        if (cin.fail() || students[i].age <= 0) {
            cout << "INVALID: age must be a positive number." << endl;
            return 0;
        }

        cout << "Number of subjects (max 5): ";
        cin >> students[i].subjectCount;
        if (cin.fail() || students[i].subjectCount < 1 || students[i].subjectCount > 10) {
            cout << "INVALID: maximum subject is 5." << endl;
            return 0;
        }

        int totalCredit = 0;
        float totalPoint = 0;

        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << "\nSubject " << j + 1 << " name: ";
            cin >> ws;
            getline(cin, students[i].subjects[j].name);

            cout << "Credit hour (1-5): ";
            cin >> students[i].subjects[j].credit;
            if (cin.fail() || students[i].subjects[j].credit < 1 || students[i].subjects[j].credit > 5) {
                cout << "INVALID: credit must be between 1 and 5." << endl;
                return 0;
            }

            cout << "Mark (0-100): ";
            cin >> students[i].subjects[j].mark;
            if (cin.fail() || students[i].subjects[j].mark < 0 || students[i].subjects[j].mark > 100) {
                cout << "INVALID: mark must be between 0 and 100." << endl;
                return 0;
            }

            students[i].subjects[j].grade = getGrade(students[i].subjects[j].mark);

            totalCredit += students[i].subjects[j].credit;

            if (students[i].subjects[j].grade == 'A')
                totalPoint += 4.0 * students[i].subjects[j].credit;
            else if (students[i].subjects[j].grade == 'B')
                totalPoint += 3.0 * students[i].subjects[j].credit;
            else if (students[i].subjects[j].grade == 'C')
                totalPoint += 2.0 * students[i].subjects[j].credit;
            else
                totalPoint += 1.0 * students[i].subjects[j].credit;
        }

        students[i].cpa = totalPoint / totalCredit;
    }

    
    cout << "\n===============================" << endl;
    cout << "      STUDENT DETAILS" << endl;
    cout << "===============================" << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent " << i + 1 << ": " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Subjects taken: " << students[i].subjectCount << endl;

        cout << "---------------------------------------------" << endl;
        cout << "Subject Name\tCredit\tMark\tGrade" << endl;
        cout << "---------------------------------------------" << endl;
        for (int j = 0; j < students[i].subjectCount; j++) {
            cout << students[i].subjects[j].name << "\t\t"
                 << students[i].subjects[j].credit << "\t"
                 << students[i].subjects[j].mark << "\t"
                 << students[i].subjects[j].grade << endl;
        }
        cout << "---------------------------------------------" << endl;
        cout << "CPA: " << students[i].cpa << endl;
    }

    return 0;
}
