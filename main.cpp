// Programmer: Timothy Wacker
// This program takes a file, reads it, and provides students' average grades from tests.

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

//global variables
const int MAXSTUDENTS = 100;
const int MAXTESTS = 10;

//function prototypes
int readfile(string names[], double scores[][MAXTESTS], int testCounts[]); 
void calcavg(double scores[][MAXTESTS], double averages[], int testCounts[], int numStudents);
char convertLetter(double average);
void printReport(string names[], double averages[], int numStudents);

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
        cout << "Error opening file" << endl;
        return 0;
    }
    
    string line; // File was only reading first line only, assistant added this and it worked. Not sure exactly why
    int numStudents = 0;
    
    while (getline(studentFile, line) && numStudents < MAXSTUDENTS) {
        istringstream iss(line);
        
        if (iss >> names[numStudents]) {
            int testCount = 0;
            double score;
            while (testCount < MAXTESTS && iss >> score) {
                scores[numStudents][testCount] = score;
                testCount++;
            }
            testCounts[numStudents] = testCount;
            numStudents++;
        }
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
    cout << left << setw(20) << "Name" << setw(10) << "Average" << "Grade\n";
    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(20) << names[i]
             << fixed << setprecision(2) << setw(10) << averages[i]
             << convertLetter(averages[i]) << endl; 
    }
}
