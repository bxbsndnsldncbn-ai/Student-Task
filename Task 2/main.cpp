#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;

    ofstream initFile("fruit.txt");
    if (initFile.is_open()) {
        initFile << "Apple" << endl;
        initFile << "Orange" << endl;
        initFile << "Banana" << endl;
        initFile.close();
    }

    ifstream readFile("fruit.txt");
    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
        return 1;
    }

    ofstream appendFile("fruit.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "Fresh Fruits" << endl;
        appendFile.close();
    } else {
        cout << "Unable to open file for writing!" << endl;
        return 1;
    }

    return 0;
}
