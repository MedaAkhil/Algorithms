/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class StringEditor {
    private:
        string originalString;
        string editedString;
        vector<string> longestSequences;

    public:
        // Constructor
        StringEditor(string s) {
            originalString = s;
        }

        // Overloaded input operator
        friend istream& operator>>(istream& in, StringEditor& se) {
            in >> se.originalString;
            return in;
        }

        // Overloaded output operator
        friend ostream& operator<<(ostream& out, StringEditor& se) {
            out << se.editedString << endl;
            out << "Longest repeating sequences: ";
            for (string sequence : se.longestSequences) {
                out << sequence << " ";
            }
            return out;
        }

        // Function to edit the original string
        void editString() {
            char currentChar = originalString[0];
            int currentCount = 1;
            int maxCount = 0;
            editedString = "";
            longestSequences.clear();

            for (int i = 1; i < originalString.length(); i++) {
                if (originalString[i] == currentChar) {
                    currentCount++;
                } else {
                    if (currentCount > maxCount) {
                        maxCount = currentCount;
                        longestSequences.clear();
                        longestSequences.push_back(string(currentCount, currentChar));
                    } else if (currentCount == maxCount) {
                        longestSequences.push_back(string(currentCount, currentChar));
                    }
                    currentChar = originalString[i];
                    currentCount = 1;
                    editedString += currentChar;
                }
            }

            // Check for last sequence
            if (currentCount > maxCount) {
                maxCount = currentCount;
                longestSequences.clear();
                longestSequences.push_back(string(currentCount, currentChar));
            } else if (currentCount == maxCount) {
                longestSequences.push_back(string(currentCount, currentChar));
            }
        }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    while (!inputFile.eof()) {
        StringEditor se;
        inputFile >> se;
        se.editString();
        outputFile << se;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream inputFile("input.txt");

    if (inputFile.is_open()) {
        getline(inputFile, line);
        cout << "Read Line: " << line << endl;
        inputFile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}