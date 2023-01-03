#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> L(length, 0), R(length, 0);
        vector<int> answer(length);
        // 左边没有元素
        L[0] = 1;
        for(int i = 1; i < length; ++i){
            L[i] = nums[i-1] * L[i-1];
        }
        // 右边没有元素
        R[length-1] = 1;
        for(int i = length-2; i >= 0; --i){
            R[i] = R[i+1] * nums[i+1];
        }
        for(int i = 0; i < length; ++i){
            answer[i] = L[i] * R[i];
        }
        return answer;
    }
};
