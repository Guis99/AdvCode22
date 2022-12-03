#include <iostream>
#include <fstream>
#include <string>

using namespace std;
  
int max_cal(string filename) {
    int max_val = 0, curr_cal = 0, max_elf = 0, num_elves = 0;

    string myText;

    // Read from the text file
    ifstream MyReadFile(filename);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        if (myText == "") {
            num_elves++;
            if (max_val < curr_cal) {
                max_val = curr_cal;
                max_elf = num_elves;
            }
            curr_cal = 0;
        }

        else {
            curr_cal += stoi(myText);
        }
    }

    MyReadFile.close();
    cout << "Maximum calorie count found at position " << max_elf << "/" << num_elves << '\n';
    return max_val;
}
  
// Driver Code
int main()
{
    int ans = max_cal("input.txt");
    cout << ans;
    return 1;
}