#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_intervals(string line) {
    int p1,p2,p3,p4;
    sscanf(line.c_str(), "%d-%d,%d-%d", &p1,&p2,&p3,&p4);
    vector<int> a = {p1,p2,p3,p4};
}

void get_score(string filename) {
    string myText;
    ifstream MyReadFile(filename);
    int total = 0;

    while (getline (MyReadFile, myText)) {
      vector<int> intervals = get_intervals(myText);
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