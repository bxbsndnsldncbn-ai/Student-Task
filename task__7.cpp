
#include <iostream>
#include <string>

using namespace std;

int main() {
    string names[4] = {
        "omar Hassan",
        "Salma Khaled",
        "Tarek Adel",
        "Nourhan sami"
    };

    int n = 4;

    cout << "Names before sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    cout << "\nNames after sorting (ascending):" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << endl;
    }

    return 0;
}

