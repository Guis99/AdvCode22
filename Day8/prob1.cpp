#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

vector<int> isVisible(int i, int j, int height, int limx, int limy, vector<vector<int>> x) {
    vector<int> res;
    bool v1 = true; bool v2 = true; bool v3 = true; bool v4 = true;
    int w1 = 0; int w2 = 0; int w3 = 0; int w4 = 0;
    for (int k=i-1;k>=0;k--) {
        w1++;
        if (x[k][j]>= height) {
            v1 = false;
            break;
        }
    }
    for (int k=i+1;k<limy;k++) {
        w2++;
        if (x[k][j]>= height) {
            v2 = false;
            break;
        }
    }
    for (int k=j-1;k>=0;k--) {
        w3++;
        if (x[i][k]>= height) {
            v3 = false;
            break;
        }
    }
    for (int k=j+1;k<limx;k++) {
        w4++;
        if (x[i][k]>= height) {
            v4 = false;
            break;
        }
    }
    res.push_back(v1|v2|v3|v4);
    res.push_back(w1*w2*w3*w4);
    return res;
}

void get_score(string filename) {
    string nl;
    ifstream MyReadFile(filename);
    vector<vector<int>> x;

    while (getline (MyReadFile, nl)) {
        vector<int> row;
        for (char num : nl) {
            row.push_back(num - '0');
        }
        x.push_back(row); row.clear();
    }

    MyReadFile.close();

    int Y = x.size(); int X = x[0].size(); 
    int total = 2*X+2*Y-4;
    int ans2 = 0;

    for (int i=1;i<Y-1;i++) {
        for (int j=1;j<X-1;j++) {
            vector<int> ans = isVisible(i,j,x[i][j],X,Y,x);
            total += ans[0];
            ans2 = max(ans2,ans[1]);
        }
    }
    cout<<total<<endl;
    cout<<ans2;
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}