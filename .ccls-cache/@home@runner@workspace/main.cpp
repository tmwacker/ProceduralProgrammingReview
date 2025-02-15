#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAXSTUDENTS = 100;
const int MAXTESTS = 10;

int readfile(string names[], double scores[][MAXTESTS], int testCounts[]); // Reads file & tracks test count
void calcavg(double scores[][MAXTESTS], double averages[], int testCounts[], int numStudents); // Averages test scores
char convertLetter(double average); // Converts scores into letter grades
void printReport(string names[], double averages[], int numStudents); // Displays results

int main() {
    string names[MAXSTUDENTS];
    double scores[MAXSTUDENTS][MAXTESTS];
    double averages[MAXSTUDENTS];
    int testCounts[MAXSTUDENTS] = {0};

    int numStudents = readfile(names, scores, testCounts);
    calcavg(scores, averages, testCounts, numStudents);
    printReport(names, averages, numStudents);

    return 0;
}

int readfile(string names[], double scores[][MAXTESTS], int testCounts[]) {
    ifstream studentFile("StudentGrades.txt");
    if (!studentFile) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    int numStudents = 0;
    while (numStudents < MAXSTUDENTS && studentFile >> names[numStudents]) {
        int testCount = 0;
        while (testCount < MAXTESTS && studentFile >> scores[numStudents][testCount]) {
            testCount++;
        }
        testCounts[numStudents] = testCount; 
        numStudents++;
    }  
    studentFile.close();
    return numStudents;
}

void calcavg(double scores[][MAXTESTS], double averages[], int testCounts[], int numStudents) { 
    for (int i = 0; i < numStudents; i++) {
        double sum = 0;
        for (int j = 0; j < testCounts[i]; j++) { 
            sum += scores[i][j];
        }
        averages[i] = sum / testCounts[i]; 
    }
}

char convertLetter(double average) {
    if (average > 89) return 'A';
    else if (average > 79) return 'B';
    else if (average > 69) return 'C';
    else if (average > 59) return 'D';
    else return 'F';
}

void printReport(string names[], double averages[], int numStudents) {
    cout << "\nStudent Report\n";
    cout << "-----------------------------------------\n";
    cout << left << setw(20) << "Name" << setw(10) << "Average" << "Grade\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(20) << names[i]    // Name aligned to 20 spaces
             << fixed << setprecision(2) << setw(10) << averages[i]  // Average aligned to 10 spaces
             << convertLetter(averages[i]) << endl; // Grade printed normally
    }
}