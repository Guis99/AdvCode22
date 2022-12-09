#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Directory {
    int size = 0;
    string name;
    Directory *parent;
    map<string,Directory*> children;
    map<string,int> files;
    Directory(string b, Directory *par=NULL) {
        name = b;
        parent = par;
    }
};

void get_score(string filename) {
    string nl;
    ifstream MyReadFile(filename);

    Directory *curr = new Directory("/");
    Directory *root = curr;
    vector<Directory*> all{curr};
    int num_files = 0;
    getline (MyReadFile, nl);
    while (getline (MyReadFile, nl)) {
        if (nl.substr(0,3) == "dir") {
            char dir[30];
            sscanf(nl.c_str(), "dir %s", dir);
            if (curr->children.find(dir) == curr->children.end()) {
                Directory *newdir = new Directory(dir,curr);
                curr->children[dir] = newdir;
                all.push_back(newdir);
            }
        }

        else if (nl[0] == '$' & nl.substr(2,2) == "cd") {
            char dir[30];
            sscanf(nl.c_str(), "$ cd %s", dir);
            curr = (dir[0] != '.') ? curr->children[dir] : curr->parent;
        }

        else if (nl[0] != '$') {
            int a; char filename[30];
            sscanf(nl.c_str(), "%d %s", &a, filename);
            if (curr->files.find(filename) == curr->files.end()) {
                curr->files[filename] = a;
                Directory *par = curr;
                num_files ++;
                while (par != NULL) {
                    par->size += a;
                    par = par->parent;
                }
            }  
        }
    }

    int total = 0;
    int space = root->size-40000000;
    int total2 = 70000000;
    for (Directory *dir : all) {
        if (dir->size <= 100000) {
            total += dir->size;
        }
        if (dir->size >= space) {
            total2 = min(total2,dir->size);
        }
    }
    cout<<total<<endl;
    cout<<total2<<endl<<num_files<<endl<<all.size();
}
  
// Driver Code
int main() {
    get_score("input.txt");

    return 1;
}