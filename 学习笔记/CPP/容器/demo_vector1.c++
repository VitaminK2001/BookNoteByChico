#include <vector>
#include <iostream>
using namespace std;

int main(){
    const char *a[] = {"asd", "edf", "egh"};
    size_t len = sizeof(a) / sizeof(char*);
    vector<string> words(a, a+len);
    for(string word : words){
        cout << word << endl;
    }
    auto it = words.begin();
    for(; it != words.end(); ++it){
        cout << *it << " ";
    }
}