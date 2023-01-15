#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
    int a[] = {1,2,3,4,5};
    vector<int> v(a, a+3); // {1,2,3}
    
    vector<int> v2 = {1,2,3}; // {1,2,3}
    
    vector<int> v3(begin(a), end(a)); // {1,2,3,4,5}
    
    bool isequal = v == v2; // true
    
    for(auto& elem : v) { // 真实改变v中元素的值
        elem++;
    }

    return 0;
}