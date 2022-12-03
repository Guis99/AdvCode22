#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
#include <cstring>

using namespace std;

int priority(string *line) {
    set<char> seen;
    int itemcount = (*line).size();
    for (int i=0;i<itemcount/2;i++) {
        char item = (*line)[i];
        seen.insert(item);
    }

    for (int i=itemcount/2;i<itemcount;i++) {
        char item = (*line)[i];
        if (seen.find(item) != seen.end()) {
            int val_char = (isupper(item)) ? int(item)-38  : int(item)-96;
            return val_char;
        }
    }
}

void get_score(string filename) {
    int total = 0;
    string myText;

    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
        total += priority(&myText);
        char item = myText[0];
    }

    MyReadFile.close();

    cout << total;
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}