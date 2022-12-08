#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

bool unique(string *sub) {
    set<char> contain(begin(*sub) , end(*sub));
    return sub->size() == contain.size();
}

void get_score(string filename) {
    string myText;
    ifstream MyReadFile(filename);
    getline(MyReadFile, myText);

   // myText = "mjqjpqmgbljsphdztnvjfqwrcgsmlb";

    for (int i=0;i<myText.size()-14;i++) {
        string sub = myText.substr(i,14);
        if (unique(&sub)) {
            cout<<i+14;
            break;
        }
    }
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}