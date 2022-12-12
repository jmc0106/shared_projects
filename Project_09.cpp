// ****************************************
// Program Title: Project 9
// Project File: Project_09.cpp
// Name: Jacob Cross
// Course Section: CPE-211-01
// Lab Section: 3
// Due Date: 11/13/2022
// program descroption: Gets two input arrays and finds the OR, AND, and XORs between them
// ****************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <climits> // for INT_MAX
using namespace std;

//Prototypes
void OpenInputFile(ifstream&);
void ReadData(ifstream&, int, int, int main_array[]);
void FindRowAndColumn(ifstream&, int&, int&);
void SplitArray(int, int, int main_array[], int array1[], int array2[]);
void PrintInputArrays(int, int, int array1[], int array2[]);
void PrintOutputArrays(int, int, int arra1[], int array2[], int array_or[], int array_and[], int array_xor[]);
int CalculateIntRowValue(int, int temp_array[]);
void PrintDecimalValue(int, int, int array_or[], int array_and[], int array_xor[]);

int main(){
    cout << endl;
    int row_number, col_number;
    ifstream iFile;
    OpenInputFile(iFile);
    FindRowAndColumn(iFile, row_number, col_number);
    int main_array[row_number*col_number*2];
    int array1[row_number*col_number];
    int array2[row_number*col_number];
    ReadData(iFile, row_number, col_number, main_array);
    //Now we have the main_array with all the input ints in order
    SplitArray(row_number, col_number, main_array, array1, array2);
    //Now arrays are in seperate array1 and array2
    PrintInputArrays(row_number, col_number, array1, array2);
    int array_or[row_number*col_number];
    int array_and[row_number*col_number];
    int array_xor[row_number*col_number];
    PrintOutputArrays(row_number, col_number, array1, array2, array_or, array_and, array_xor);
    PrintDecimalValue(col_number, row_number, array_or, array_and, array_xor);
    return 0;
}

void OpenInputFile(ifstream& iFile){
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
        cout << "==> Please try again..." << endl;
        cout << string(47, '*') << endl;
        cout << endl;
        cout << "Enter the name of the input file: ";
        cin >> ifile_name;
        cout << endl;
        cin.ignore(1000, '\n');
        iFile.open(ifile_name.c_str());
    }
}

void FindRowAndColumn(ifstream& iFile, int& row_num, int& col_num){
    string rows, columns;
    getline(iFile, rows, '\n');
    row_num = int(rows[0]-'0');
    if(rows[1] == '0'){
        row_num = 10;
    }
    getline(iFile, columns, '\n');
    col_num = int(columns[0]-'0');
    if(columns[1] == '0'){
        col_num = 10;
    }
    //Finds the amount of rows and columns in each array given
}

void ReadData(ifstream& iFile, int row_num, int col_num, int main_array[]){
    string none;
    getline(iFile, none, '\n');
    //Skips line and now we are at the start of the first array 

    int array1[row_num*col_num];
    int iter = 0;
    for(int loop = 0; loop<row_num; loop++){
        for(int col = 1; col<col_num; col++){
            string get_str;
            getline(iFile, get_str, ' ');
            char c = get_str[0];
            main_array[iter] = int(c - '0');
            //cout << main_array[iter] << '-';
            iter++;
        }
        string get_str2;
        getline(iFile, get_str2, '\n');
        char c2 = get_str2[0];
        main_array[iter] = int(c2 - '0');
        //cout << main_array[iter];
        //cout << endl;
        iter++;
    }
    //Reads the data given in the first array and adds it to the main array

    getline(iFile, none, '\n');
    //cout << endl;
    //Skips line and now we are at the start of the second array

    int array2[row_num*col_num];
    iter = 0;
    for(int loop = 0; loop<row_num; loop++){
        for(int col = 1; col<col_num; col++){
            string get_str;
            getline(iFile, get_str, ' ');
            char c = get_str[0];
            main_array[iter+col_num*row_num] = int(c - '0');
            //cout << main_array[iter+col_num*row_num] << '-';
            iter++;
        }
        string get_str2;
        getline(iFile, get_str2, '\n');
        char c2 = get_str2[0];
        main_array[iter+col_num*row_num] = int(c2 - '0');
        //cout << main_array[iter+col_num*row_num];
        //cout << endl;
        iter++;
    }
    //Reads the data given in the second array and adds it to the main array 
}

void SplitArray(int row_num, int col_num, int main_array[], int array1[], int array2[]){
    int area = row_num * col_num;
    for(int i=0; i<area; i++){
        array1[i] = main_array[i];
    }
    for(int x=0; x<area; x++){
        array2[x] = main_array[x+area];
    }
}

void PrintInputArrays(int row_number, int col_number, int array1[], int array2[]){
    //Prints header
    cout << "Initial values of the arrays processed" << endl;
    cout << "--------------------------------------" << endl;
    cout << setw(2*col_number) << left << "Array 1" << "    " << setw(2*col_number) << "Array 2" << endl;
    cout << setw(2*col_number) << left << "-------" << "    " << setw(2*col_number) << "-------" << endl;
    for(int r = 0; r<row_number; r++){
        for(int c = 0; c<col_number; c++){
            cout << array1[c+(r*col_number)] << " ";
        } cout << "    ";
        for(int c2 = 0; c2<col_number; c2++){
            cout << array2[c2+(r*col_number)] << " ";
        } cout << endl;
    }
    cout << endl;
}

void PrintOutputArrays(int row_num, int col_num, int array1[], int array2[], int array_or[], int array_and[], int array_xor[]){
    //Prints header
    cout << "OR, AND and XOR results" << endl;
    cout << "-----------------------" << endl;
    cout << setw(2*col_num) << left << "OR" << "    " << setw(2*col_num) << "AND" << "    " << setw(2*col_num) << "XOR" << endl;
    cout << setw(2*col_num) << left << "--" << "    " << setw(2*col_num) << "---" << "    "<< setw(2*col_num) << "---" << endl;
    //Calc for OR, AND and XOR
    for(int i = 0; i<col_num*row_num; i++){
        //Calc for OR
        if(array1[i] == 1 || array2[i] == 1){
            array_or[i] = 1;
        }else{
            array_or[i] = 0;
        }
        //Calc for AND
        if(array1[i] == 1 && array2[i] == 1){
            array_and[i] = 1;
        }else{
            array_and[i] = 0;
        }
        //Calc for XOR
        if(array1[i] != array2[i]){
            array_xor[i] = 1;
        }else{
            array_xor[i] = 0;
        }
    }
    //Prints output of calcs
    for(int r = 0; r<row_num; r++){
        for(int c = 0; c<col_num; c++){
            cout << array_or[c+(r*col_num)] << " ";
        } cout << "    ";
        for(int c = 0; c<col_num; c++){
            cout << array_and[c+(r*col_num)] << " ";
        } cout << "    ";
        for(int c = 0; c<col_num; c++){
            cout << array_xor[c+(r*col_num)] << " ";
        } cout << endl;
    }
}

int CalculateIntRowValue(int col_num, int temp_array[]){
    int ans = 0;
    for(int i=0; i<col_num; i++){
        ans += pow(2,i)*temp_array[col_num-i-1];
    }
    return ans;
}

void PrintDecimalValue(int col_num, int row_num, int array_or[], int array_and[], int array_xor[]){
    //Header
    cout << endl;
    cout << endl;
    cout << "Integer Equivalents for the rows" << endl;
    cout << "of the OR, AND and XOR arrays" << endl;
    cout << "--------------------------------" << endl;
    cout << "OR      AND     XOR" << endl;
    cout << "--      ---     ---" << endl;
    //Printing results
    int temp_array[col_num];
    for(int r = 0; r<row_num; r++){
        for(int c = 0; c<col_num; c++){
            temp_array[c] = array_or[c+(r*col_num)];
        }
        cout << setw(8) << left << CalculateIntRowValue(col_num, temp_array);
        for(int c = 0; c<col_num; c++){
            temp_array[c] = array_and[c+(r*col_num)];
        }
        cout << setw(8) << left << CalculateIntRowValue(col_num, temp_array);
        for(int c = 0; c<col_num; c++){
            temp_array[c] = array_xor[c+(r*col_num)];
        }
        cout << setw(8) << left << CalculateIntRowValue(col_num, temp_array);
        cout << endl;
    }

}
