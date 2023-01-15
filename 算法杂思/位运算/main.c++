#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // 用mask遍历所有组合的二进制可能 0 ~ 2^n-1
        int mask = 0;
        vector<int> path;
        vector<vector<int> > res;
        for(; mask < (1 << n); ++mask) {
            path.clear();
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)) { //此处不一定等于1 大于0就行 结果和i的位数相关 1000
                    path.push_back(nums[i]);
                }
            }
            res.push_back(path);
        }
        return res;
    }
};