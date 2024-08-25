#include <iostream>
using namespace std;

int main() 
{
    int numSubjects;
    float grade, credit, totalCredits = 0, weightedSum = 0;

    cout << "\n Enter the number of subjects: ";
    cin >> numSubjects;

     cout << "\n Enter the grade point according to grade : "<<endl;
     cout << " Grade points: O = 10, A+ =9, A = 8, B+ = 7, B = 6, C = 5, P = 4"<<endl;

    for (int i = 0; i < numSubjects; i++) 
    {
        cout << " Enter the grade points for subject " << i + 1 << ": "; 
        cin >> grade;  

        cout << " Enter credit hours for subject " << i + 1 << ": ";
        cin >> credit;

        // Calculating weighted sum of grades and total credits
        weightedSum += grade * credit;
        totalCredits += credit;
    }

    float cgpa = weightedSum / totalCredits;

    cout << " Your CGPA is: " << cgpa << endl;

    return 0;
}