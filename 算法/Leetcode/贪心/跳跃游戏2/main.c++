#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // 需要返回跳到最后一个位置的最小的跳跃次数
    int jump(vector<int>& nums) {
        // 贪心的思想在于，从后向前找到跳跃点，
        // 每一次找距离最远的点
        int position = nums.size() - 1;
        int step = 0;
        while(position > 0){ //当position = 0时就到了起点
            for(int i = 0; i < position; ++i){
                if(i + nums[i] >= position){ //选择能够到达position的最远的一个点的方法就是从头开始遍历
                    position = i;
                    step++;
                    break;
                }
            }
        }
        return step;
    }

    int jump(vector<int>& nums){
        int end = 0, i = 0, maxPos = 0, step = 0;
        int len = nums.size();
        for(; i < len-1; ++i) { //从前往后遍历，通过i控制当前的位置
            // 重点是将step++的步骤和更新end的步骤放在一起，
            // 和更新maxPos的步骤分开

            // 如果maxPos能够超过当前i的位置
            if(maxPos >= i){
                maxPos = max(maxPos, i + nums[i]);
            }
            if(i == end){ //到了需要跳的时候
                end = maxPos; //更新end的位置
                ++step; //更新步数
            }
        }
        return step;
    }
};