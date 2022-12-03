#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int get_point(char *pred, char *action) {
    int score, opp;

    switch (*action) {
        case 'X':
            score = 0;
            break;
        case 'Y':
            score = 3;
            break;
        case 'Z':
            score = 6;
            break;
    }

    switch (*pred) {
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

    if ((opp == 1 & score == 6) | (opp == 2 & score == 3) | (opp == 3 & score == 0)) {
        return score + 2;
    }
    
    else if ((opp == 3 & score == 6) | (opp == 1 & score == 3) | (opp == 2 & score == 0)) {
        return score + 1;
    }

    else if ((opp == 2 & score == 6) | (opp == 3 & score == 3) | (opp == 1 & score == 0)) {
        return score + 3;
    }
}

void get_score(string filename) {
    int score = 0;
    string myText;

    ifstream MyReadFile(filename);

    while (getline (MyReadFile, myText)) {
        char char1 = myText[0];
        char char2 = myText[2];
        int points = get_point(&char1, &char2);
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