// https://leetcode.cn/problems/maximum-subarray/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 从哪里开始连续，连续多少个? 
        // 如果我们定义dp[i]表示以nums[i]结尾的子数组和
        // 则对于dp[i+1]
        // 如果dp[i]为负数，则dp[i+1] = nums[i+1]
        // 如果dp[i]为正数，则dp[i+1] = nums[i+1] + dp[i]

        int len = nums.size();
        int dp[len];
        dp[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            if(dp[i-1] > 0) dp[i] = dp[i-1] + nums[i];
            else dp[i] = nums[i];
        }
        int res = dp[0];
        for(int i = 1; i < len; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};