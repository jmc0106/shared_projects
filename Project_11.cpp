// ****************************************
// Program Title: Project 11
// Project File: Project_11.cpp
// Name: Jacob Cross
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 12/4/2022
// program description: Gets an organized input file, then returns and organized output of grades, averages, and names that details class data
// ****************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Student{
    string firstName;
    string lastName;
    float average;
    char grade; 
};

//Prototypes
void OpenInputFile(ifstream&);
int GetTestNumber(ifstream&);
void SortData(ifstream&, int, Student&, int letter_count[]);
void PrintDataHeader();
void PrintStructData(Student&, int);
void PrintComparativeData(float, float, float);
void PrintGradeHistogram(int letter_count[]);
void PrintEmptyError();

int main(){
    ifstream iFile;
    //Checks to see if input file is empty, if so displays an error and stops the program
    OpenInputFile(iFile);
    int number_of_tests = GetTestNumber(iFile);
    if(number_of_tests < 0){
        PrintEmptyError();
        return 0;
    }
    PrintDataHeader(); //Find a way to loop the process of Sorting and looping data
    int counter = 1;
    float highest_average = 0;
    float lowest_average = 100;
    float class_average = 0;
    int letter_count[5] = {0,0,0,0,0};
    while(iFile){
        Student loop_student;
        SortData(iFile, number_of_tests, loop_student, letter_count);
        //SortData goes through one extra time, this if statement corrects that error and does not display the extra line read
        if(loop_student.average > 0){
            PrintStructData(loop_student, counter);
            //If statements that track the lowest and highest averages for later
            if(loop_student.average > highest_average){
                highest_average = loop_student.average;
            }
            if(loop_student.average < lowest_average){
                lowest_average = loop_student.average;
            }
            class_average += loop_student.average;
        }
        counter++;
    }
    //The counter is always two higher than the number of students
    counter -= 2;
    class_average = class_average/counter;
    PrintComparativeData(class_average, highest_average, lowest_average);
    PrintGradeHistogram(letter_count);
    return 0;
}

void OpenInputFile(ifstream& iFile){
    cout << endl;
    //Opening and naming input file
    cout << "Enter the name of the input file: "; //Asking user for input file name
    string ifile_name; //Declaring input file name 
    cin >> ifile_name; //User gives input file name
    cout << ifile_name << endl << endl; //Prints out the input file name given by the user
    iFile.open(ifile_name.c_str()); //Opens input file 
    //Loop that activates if input file doesn't open
    while(iFile.fail()){
        iFile.clear();
        cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
        cout << "==> Input file failed to open properly!!" << endl;
        cout << "==> Attempted to open file: " << ifile_name << endl;
        cout << string(47, '*') << endl;
        cout << endl;
        cout << "Try Again..." << endl;
        cout << endl;
        cout << "Enter the name of the input file: ";
        cin >> ifile_name;
        cout << ifile_name << endl << endl;
        cin.ignore(1000, '\n');
        iFile.open(ifile_name.c_str());
    }
}

//This function find the amount of tests each student has taken
int GetTestNumber(ifstream& iFile){
    int test_num;
    string test_string;
    getline(iFile, test_string, '\n');
    test_num = int(test_string[0]-'0');
    return test_num;
}

//This funciton puts data from one line into a Student struc
void SortData(ifstream& iFile, int number_of_tests, Student& stud, int letter_count[]){
    string temp_last, temp_first;
    int scores_array[number_of_tests];
    getline(iFile, temp_last, ' ');
    getline(iFile, temp_first, ' ');
    for(int i=1; i<number_of_tests; i++){
        string temp_score;
        getline(iFile, temp_score, ' ');
        int score = int(temp_score[1]-'0') + int(temp_score[0]-'0')*10;
        if(temp_score == "100"){ //Error check if number is 100
            score = 100;
        }
        scores_array[i-1] = score;
    }
    string temp_score;
    getline(iFile, temp_score, '\n');
    int score = int(temp_score[1]-'0') + int(temp_score[0]-'0')*10;
    if(temp_score == "100"){ //Error check if number is 100
        score = 100;
    }
    scores_array[number_of_tests-1] = score;
    float average = 0;
    for(int x = 0; x<number_of_tests; x++){
        average += scores_array[x];
    }
    average = average / number_of_tests;
    //Puts data into student struct
    stud.firstName = temp_first.substr(0,7);
    stud.lastName = temp_last.substr(0,12);
    stud.average = average;
    //Calcs grade and puts it into student struct
    if(average >= 90){
        stud.grade = 'A';
        letter_count[0]++;
    }else if(average >= 80 && average < 90){
        stud.grade = 'B';
        letter_count[1]++;
    }else if(average >= 70 && average < 80){
        stud.grade = 'C';
        letter_count[2]++;
    }else if(average >= 60 && average < 70){
        stud.grade = 'D';
        letter_count[3]++;
    }else{
        stud.grade = 'F';
        letter_count[4]++;
    }
}

//This function prints the header for the output data
void PrintDataHeader(){
    cout << setw(4) << left << "#" << setw(15) << "Last" << setw(10) << "First" << setw(9) << "Average" << "Grade" << endl;
    cout << setw(4) << left << "-" << setw(15) << "----" << setw(10) << "-----" << setw(9) << "-------" << "-----" << endl;
}

//This function prints the sorted data for one Student struct
void PrintStructData(Student& stud, int num){
    cout << setw(4) << left << num << setw(15) << stud.lastName << setw(10) << stud.firstName << setw(9) << fixed << setprecision(2) << stud.average << stud.grade << endl;
}

//This funciton calcs and prints the class average, highest average, and lowest average
void PrintComparativeData(float class_avrg, float high_avrg, float low_avrg){
    cout << endl;
    cout << "Class Average............" << fixed << setprecision(2) << class_avrg << endl;
    cout << "Highest Average.........." << setprecision(2) << high_avrg << endl;
    cout << "Lowest Average..........." << setprecision(2) << low_avrg << endl;
}

//This funciton gets a list of numbers [a,b,c,d,f] that correspond with how many letter grades were given
void PrintGradeHistogram(int letter_count[]){
    cout << endl;
    cout << right << setw(18) << "Grade Histogram" << endl;
    cout << "           1         2" << endl;
    cout << "  12345678901234567890" << endl;
    cout << "A:";
    for(int i=0; i<letter_count[0]; i++){
        cout << '*';
    } cout << endl;
    cout << "B:";
    for(int i=0; i<letter_count[1]; i++){
        cout << '*';
    } cout << endl;
    cout << "C:";
    for(int i=0; i<letter_count[2]; i++){
        cout << '*';
    } cout << endl;
    cout << "D:";
    for(int i=0; i<letter_count[3]; i++){
        cout << '*';
    } cout << endl;
    cout << "F:"; //F always has one extra, so we start at i=0
    for(int i=1; i<letter_count[4]; i++){
        cout << '*';
    } cout << endl << endl;
}

//This function returns an Error message that the file is empty
void PrintEmptyError(){
    cout << string(16, '*') << " File Is Empty " << string(16, '*') << endl;
    cout << "==> Input file is empty" << endl;
    cout << "==> No information to process" << endl;
    cout << string(32+5+3+7, '*') << endl << endl;
}
