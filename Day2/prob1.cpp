#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int get_point(char pred, char action) {
    int score = 0, opp = 0;

    switch (action) {
        case 'X':
            score = 1;
            break;
        case 'Y':
            score = 2;
            cout << "yay" << score;
            break;
        case 'Z':
            score = 3;
            break;
    }

    switch (pred) {
        case 'A':
            opp = 1;
            break;
        case 'B':
            opp = 2;
            break;
        case 'C':
            opp = 3;
            break;
    }
    cout << opp << score << '\n';
    if (score == opp) {
        return score + 3;
    }
    else if (((score > opp) & ~(score == 3 & opp == 1)) | (score == 1 & opp == 3)) {
        return score + 6;
    }
    else {
        return score;
    }
}

void get_score(string filename) {
    int score = 0;
    string myText;

    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
        char char1 = myText[0];
        char char2 = myText[2];
        int points = get_point(char1, char2);
        score += points;
    }

    MyReadFile.close();

    cout << score;
}
  
// Driver Code
int main() {
    get_score("input.txt");
    return 1;
}