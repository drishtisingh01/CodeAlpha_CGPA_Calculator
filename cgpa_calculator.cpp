#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "===== CGPA Calculator =====" << endl;

    cout << "Enter number of courses: ";
    cin >> n;

    string courseName[n];
    float grade[n], credit[n];

    float totalCredits = 0;
    float totalGradePoints = 0;

    for(int i = 0; i < n; i++) {
        cin.ignore();

        cout << "\nEnter Course " << i + 1 << " Name: ";
        getline(cin, courseName[i]);

        cout << "Enter Grade (0-10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n========== RESULT ==========" << endl;
    cout << left << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(10) << "Credit" << endl;

    for(int i = 0; i < n; i++) {
        cout << left << setw(20) << courseName[i]
             << setw(10) << grade[i]
             << setw(10) << credit[i] << endl;
    }

    cout << "\nTotal Credits : " << totalCredits << endl;
    cout << "CGPA : " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}