#include <iostream>
#include <fstream>
#include <cstdio> // for remove() and rename()

using namespace std;

int main() {
    const string filename = "grades.txt";
    const string tempFilename = "temp.txt";

    // 1. Create the file and write five integer grades
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not create " << filename << " for writing.\n";
        return 1;
    }

    int gradesToWrite[5] = {85, 92, 78, 95, 88};
    for (int i = 0; i < 5; ++i) {
        outFile << gradesToWrite[i] << "\n";
    }
    outFile.close();
    cout << "Step 1: Wrote five integer grades to " << filename << ".\n\n";

    // 2. Read and print the grades using a correct reading loop
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open " << filename << " for reading.\n";
        return 1;
    }

    cout << "Step 2: Current grades in " << filename << ":\n";
    int grade;
    while (inFile >> grade) {
        cout << "- " << grade << "\n";
    }
    inFile.close();
    cout << "\n";

    // 3. Ask the user for a grade to delete, then create a temporary file without it
    int gradeToDelete;
    cout << "Step 3: Enter a grade to delete: ";
    if (!(cin >> gradeToDelete)) {
        cerr << "Error: Invalid input.\n";
        return 1;
    }

    ifstream readForDelete(filename);
    ofstream tempFile(tempFilename);

    if (!readForDelete || !tempFile) {
        cerr << "Error: Failed to open files during deletion process.\n";
        return 1;
    }

    bool found = false;
    int currentGrade;
    while (readForDelete >> currentGrade) {
        if (currentGrade == gradeToDelete && !found) {
            found = true; // Skip writing this grade (deletes first matching occurrence)
            continue;
        }
        tempFile << currentGrade << "\n";
    }

    readForDelete.close();
    tempFile.close();

    // 4. Replace the original file and show a success or error message
    if (!found) {
        remove(tempFilename.c_str());
        cout << "Error: Grade " << gradeToDelete << " was not found in " << filename << ".\n";
        return 1;
    }

    if (remove(filename.c_str()) != 0) {
        cerr << "Error: Could not remove the original file " << filename << ".\n";
        remove(tempFilename.c_str());
        return 1;
    }

    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        cerr << "Error: Could not rename temporary file to " << filename << ".\n";
        return 1;
    }

    cout << "Success: Grade " << gradeToDelete << " was deleted and " << filename << " has been updated.\n\n";

    // Optional verification print of the updated file
    ifstream verifyFile(filename);
    if (verifyFile) {
        cout << "Updated grades in " << filename << ":\n";
        while (verifyFile >> grade) {
            cout << "- " << grade << "\n";
        }
        verifyFile.close();
    }

    return 0;
}
