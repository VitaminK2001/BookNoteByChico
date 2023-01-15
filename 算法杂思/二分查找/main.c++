#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 采用两次二分查找
    // lower: 找等于target的第一个位置
    // upper: 找大于target的第一个位置
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int l = 0, r = nums.size()-1;
        // 为什么不能随便取值，因为当ans没有改变的是否表示一边没有找到
        // 一边没有找到只有可能是右边没有找到，则左边找到了，一定小于右边 最终答案仍存在 从左边一直到末尾
        // 但是如果随便赋值，则左边不一定小于右边，判断的时候可能判断这不是正确的答案
        int ans = nums.size(); 
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > target || nums[mid] == target && lower) {
                // 对于 lower 情况 : mid可能是最靠左的等于target的位置 所以需要保留进ans
                // 对于 upper 情况 : mid可能是最靠左的大于target的位置 所以需要保留进ans
                r = mid-1;
                ans = mid; 
            }else {
                // 对于 lower 情况 : mid一定是小于target的位置 不用保留
                // 对于 upper 情况 : mid一定是小于等于target的位置 不用保留
                l = mid+1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false)-1;
        vector<int> res;
        if(leftIndex <= rightIndex && nums[leftIndex]==target && nums[rightIndex]==target && rightIndex < nums.size()) {
            res.push_back(leftIndex);
            res.push_back(rightIndex);
        }else {
            res = {-1, -1};
        }
        return res;
    }
};

int main(){
    Solution s;
    int a[1] = {1};
    vector<int> b(a, a+1);
    s.searchRange(b, 1);
}