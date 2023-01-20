#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 简单的想法
        // 设置一个数组存放所有元素出现的次数
        // 找出只存放了一次的数字
        
        // 对于二进制运算来说，异或看的是二进制的位数，相同为0不同为1，只要是相同的两个数异或最后的结果都是0
        // 然后0和唯一的一个数异或结果是那个数
        int ans = nums[0];
        if (nums.size() > 1) {
            for (int i = 1; i < nums.size(); i++) {
                ans = ans ^ nums[i];
            }
        }
        return ans;
    }
};