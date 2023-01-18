// 算法设计的思想
// ab --> ba ?
// (a^-1 b^-1)^-1 --> ba reverse函数

#include <iostream>

using namespace std;

void reverse(int r[], int from, int to) {
    // 从from到to逆置
    int temp;
    for(int i = 0; i < (from-to+1)/2; ++i) { 
        temp = r[from+i];
        r[from+i] = r[to-i];
        r[to-i] = temp;
    }
}
void converse(int r[], int len, int p) {
    reverse(r, 0, p-1);
    reverse(r, p, len-1);
    reverse(r, 0, len-1);
}

int main() {
    int r[] = {1,2,3,4,5};
    converse(r, 5, 3);
    for(auto n : r) {
        cout << n << " ";
    }
}