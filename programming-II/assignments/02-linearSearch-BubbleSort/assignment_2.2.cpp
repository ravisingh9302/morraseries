#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void readNames(ifstream &inputFile, string names[], int numNames);
void displayNames(const string names[], int numNames);
int searchNames(const string names[], int numNames, const string &name);
void displaySearchNames(const string names[], int numNames, const string &name);
void swapValues(string &a, string &b);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);

//****************************************************************************************************

int main() {
    ifstream inputFile("StudentNames.txt");

    const int NUM_NAMES = 10;

    string names[NUM_NAMES], name;

    readNames(inputFile, names, NUM_NAMES);
    cout << "---------------------------------" << endl;
    cout << "\t"
         << "Student Names" << endl;
    cout << "---------------------------------" << endl;
    displayNames(names, NUM_NAMES);

    cout << "\nFind a Students place in the list." << endl;
    cout << "Enter Student name (e.g., first name, last name): " << endl;
    getline(cin, name);
    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------" << endl;
    cout << setw(32) << "Student Names ~ Ascending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------" << endl;
    cout << "Student Names ~ Descending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    inputFile.close();

    return 0;
}

//****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames) {
    if (inputFile.is_open()) {
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber) {
            getline(inputFile, names[nameNumber]);
        }
    } else {
        cout << "ERROR: Could not open file" << endl;
    }
}

//****************************************************************************************************

void displayNames(const string names[], int numNames) {
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber) {
        cout << "\t" << nameNumber + 1 << "  " << names[nameNumber] << endl;
    }
}

//****************************************************************************************************

int searchNames(const string names[], int numNames, const string &name) {
    int index = 0;
    int position = -1;
    bool found = false;
    while ((index < numNames) && !found) {
        if (names[index] == name) {
            found = true;
            position = index + 1;
        }
        index++;
    }
    return position;
}

//****************************************************************************************************

void displaySearchNames(const string names[], int numNames, const string &name) {
    if (searchNames(names, numNames, name) == -1) {
        cout << searchNames(names, numNames, name) << " \nName Not Found" << endl;
    } else {
        cout << "\nName Found: " << searchNames(names, numNames, name) << endl;
    }
}

//****************************************************************************************************

void swapValues(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

//****************************************************************************************************

void bubbleSort(string names[], int numNames) {
    bool swap;
    string temp;
    do {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count) {
            if (names[count] > names[count + 1]) {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

//****************************************************************************************************

void bubbleSortDescending(string names[], int numNames) {
    bool swap;
    string temp;
    do {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count) {
            if (names[count] < names[count + 1]) {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

/*

---------------------------------
        Student Names
---------------------------------
        1  Smith, John
        2  Song, Mona
        3  Jones, Trevor
        4  Li, Na
        5  Zhang, Xiu Ying
        6  Saleem, Mohammad
        7  Lloyd, Arthur
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Find a Students place in the list.
Enter Student name (e.g., first name, last name):
Smith, John

Name Found: 1

---------------------------------
 Student Names ~ Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying

Name Found: 8

---------------------------------
Student Names ~ Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Name Found: 3

//****************************************************************************************************

---------------------------------
        Student Names
---------------------------------
        1  Smith, John
        2  Song, Mona
        3  Jones, Trevor
        4  Li, Na
        5  Zhang, Xiu Ying
        6  Saleem, Mohammad
        7  Lloyd, Arthur
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Find a Students place in the list.
Enter Student name (e.g., first name, last name):
Nicholas, Ragland
-1
Name Not Found

---------------------------------
 Student Names ~ Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying
-1
Name Not Found

---------------------------------
Student Names ~ Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily
-1
Name Not Found

*/