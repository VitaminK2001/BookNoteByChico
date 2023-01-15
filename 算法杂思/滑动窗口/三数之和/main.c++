// https://leetcode.cn/problems/3sum/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 将三数之和转换成两数之和

    vector<vector<int> > twoSum(vector<int> &nums, int i, int j, int target, int value){
        vector<vector<int> > res;
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                vector<int> path;
                path.push_back(value);
                path.push_back(nums[i]);
                path.push_back(nums[j]);
                res.push_back(path);
                while(i < j && nums[i] == nums[i+1]){
                    i++;
                }
                ++i;
                while(i < j && nums[j] == nums[j-1]){
                    --j;
                }
                --j;
            }else if(sum < target){
                ++i;
            }else {
                --j;
            }
        }
        return res;
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // 每一次传入的target都是不重复的，所以结果不会重复
            auto result = twoSum(nums, i+1, nums.size()-1, -nums[i], nums[i]);
            answer.insert(answer.end(), result.begin(), result.end());
        }
        return answer;
    }
};
