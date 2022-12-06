#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <set>
#include <cstring>
#include <vector>

using namespace std;

vector<int> get_intervals(string *line) {
    vector<int> a;
    int begin = 0;
    for (int i=0;i<line->size();i++) {
        if ((*line)[i] == ',' | (*line)[i] == '-') {
            a.push_back(stoi(line->substr(begin,i-begin)));
            begin = i+1;
        }
        else if (i == line->size()-1) {
            a.push_back(stoi(line->substr(begin,i-begin+1)));
        }
    }
    return a;
}

void get_score(string filename) {
    int total = 0;
    string myText;

    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
      vector<int> intervals = get_intervals(&myText);
      total += (max(intervals[0],intervals[2]) <= min(intervals[1],intervals[3]));
    }

    MyReadFile.close();

    cout << total;
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}