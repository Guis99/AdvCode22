#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

void modify(deque<char> *x[9], int move, int from, int to) {
    vector<char> temp;
    for (int i = 0; i<move; i++) {
        x[to-1]->push_front(x[from-1]->front());
        x[from-1]->pop_front();
    }
    temp.clear();
}

void get_score(string filename) {
    string myText;
    ifstream MyReadFile(filename);

    deque<char> *x[9];
    for (int i=0;i<9;i++) {
        deque<char>* el = new deque<char>;
        x[i] = el;
    }

    while (getline (MyReadFile, myText) && myText[1] != '1') {
        for (int i=0; i<9; i++) {
            int index = 1+4*i;
            if (isupper(myText[index])) {
                x[i]->push_back(myText[index]); 
            }
        } 
    }
  
    getline (MyReadFile, myText);

    while (getline (MyReadFile, myText)) {
        int move,from,to;
        sscanf(myText.c_str(), "move %d from %d to %d", &move,&from,&to);
        modify(x,move,from,to);
    }   

    MyReadFile.close();

    for (deque<char>* el: x) {
        cout<<el->front();
    }  
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}