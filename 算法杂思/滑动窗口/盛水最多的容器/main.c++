#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height) {
        // 左边右边柱子的编号
        int l = 0, r = height.size()-1;
        int res = 0;
        while(l < r){
            if((r-l) * min(height[l], height[r]) > res){
                res = (r-l) * min(height[l], height[r]);
            }
            // 每次选择移动式左右两边中最短的柱子，原因是
            // 最短的柱子的高度会影响水的体积
            // 而如果挪动的较长的一边，并不会改变最短的柱子的高度，而且减少了两个柱子间的距离
            // 所以要改变柱子，只能改变较矮的一边
            if(height[l] < height[r]){
                l++;
            }else {
                r--;
            }
        }
        return res;
    }    
};