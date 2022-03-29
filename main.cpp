/**
 * This program is a coding challenge completed by Jacob Thomsen
 * for the position of BYU OIT Student Developer.
 *
 * This challenge has a four hour limit and I am beginning my work on
 * Tuesday March 29th at 10:10AM
 * Coding completed at 1:55pm (3.75 hours)
**/

#include <iostream>
#include <map>
#include <string>
#include <locale>
#include <algorithm>
#include <vector>
using namespace std;

void programInit();
void returnDecimal();
void returnNumeral();

int main() {
    cout << "Welcome to Jacob's Roman Numeral and Decimal converter!" << endl << "Let's begin" << endl;
    programInit();
    return 0;
}

void programInit(){
    int input;
    cout << "Will you be entering a Roman Numeral (1) or Decimal (2)? (or enter 0 to exit)" << endl;
    cout << "Enter the corresponding digit: ";
    cin >> input;
    if (input == 1){
        cout << endl << "Converting Roman Numeral to Decimal" << endl;
        returnDecimal();
    } else if (input == 2) {
        cout << endl << "Converting Decimal to Roman Numeral" << endl;
        returnNumeral();
    } else if (input == 0){
        return;
    } else {
        cout << endl << "There seems to be an issue with your input, please restart this program and try again" << endl;
    }
}

void returnDecimal(){
    map<char, int> convMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };
    int outputDec = 0;
    int i = 0;                                                                      // Iterator, inputRN left to right
    string inputRN;

    cout << "Please enter Roman Numeral:" << endl;                                  // Take user RN input
    cin >> inputRN;
    cout << endl;
    transform(inputRN.begin(), inputRN.end(), inputRN.begin(), ::toupper);          // Convert input to uppercase
    cout << "Roman Numeral:\t" << inputRN << endl;

    if (inputRN.length() <= 1) {                                                    // If inputRN is one character
        outputDec = convMap[inputRN.at(0)];
    } else {
        while (i < inputRN.size()) {                                                // While input is not empty
            if (convMap[inputRN[i]] < convMap[inputRN[i + 1]]) {                    // Check for rule subtraction rules
                /* Does not check rule 4. Tried to work with pointers
                  and distance() to do this but could not get it functional*/
                outputDec += convMap[inputRN[i + 1]] - convMap[inputRN[i]];         // Output decimal has RN value added
                i += 2;                                                             // Iterate two spots further
            } else {
                outputDec += convMap[inputRN[i]];                                   // Output decimal has RN value added
                i++;                                                                // Iterate one spot further
            }
        }
    }
    cout << "Decimal:  \t" << outputDec << endl;
    programInit();
}

void returnNumeral(){
    string listRN[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int listDec[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string outputRN = "";
    int inputDec;

    cout << "Please enter whole number between 0 and 3999:" << endl;
    cin >> inputDec;
    cout << endl;
    cout << "Decimal:  \t" << inputDec << endl;

    for (int i = 0; i < 13; i++){                       // For each possible RN
        while (inputDec - listDec[i] >= 0){             // While input decimal is not negative
            outputRN += listRN[i];                      // Add RN character to output
            inputDec -= listDec[i];                     // Subject RN value from input decimal
        }
    }
    cout << "Roman Numeral:\t" << outputRN << endl;
    programInit();
}

