#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
#include <cstring>

using namespace std;

void get_score(string filename) {
    int num_lines = 0;
    int total = 0;
    int j = 1;

    string line;

    ifstream MyReadFile(filename);

    set<char> seen1;
    set<char> seen2;

    while (getline (MyReadFile, line)) {
        num_lines++;
        cout << line << endl;
        if (j%3 == 1) {
            for (int i=0;i<line.size();i++) {
                seen1.insert(line[i]);
            }
        }
        else if ((j%3 == 2)) {
            for (int i=0;i<line.size();i++) {
                if (seen1.find(line[i]) != seen1.end()) {
                    seen2.insert(line[i]);
                }
            }
        }
        else {
            for (int i=0;i<line.size();i++) {
                char item = line[i];
                if (seen2.find(item) != seen2.end()) {
                    total += (isupper(item)) ? int(item)-38  : int(item)-96;
                    break;
                }
            }
            seen1.clear();
            seen2.clear();
        }
    j++;
    }
    MyReadFile.close();
    cout << num_lines << endl;
    cout << total;
}

// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}