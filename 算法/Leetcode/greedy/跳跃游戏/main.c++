#include <iostream>
#include <vector>
using namespace std;

class Solutin{
public:
    bool canJump(vector<int>& nums) {
        // 只需要判断是否能够到达数组的最后一个下标
        int len = nums.size();
        int right = nums[0];
        int i = 0;
        // 完整的遍历一遍nums
        for(; i <= right; ++i){ 
            right = max(i + nums[i], right);
            if(right >= len-1) return true;
        }
        return false;
    }
};
