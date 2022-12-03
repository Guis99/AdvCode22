#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
  
void max_cal_rank(string filename, int top_cals) {
    int curr_cal = 0;
    vector<int> cals;
    string myText;

    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
        if (myText == "") {
            cals.push_back(curr_cal);
            curr_cal = 0;
        }
        else {
            curr_cal += stoi(myText);
        }
    }

    MyReadFile.close();
    sort(cals.begin(), cals.end(), greater<int>());

    int total = 0;
    for (int i = 0; i<top_cals; i++) {
        total += cals[i];
    }

    cout << total;
}
  
// Driver Code
int main() {
    max_cal_rank("input.txt",3);
    return 1;
}