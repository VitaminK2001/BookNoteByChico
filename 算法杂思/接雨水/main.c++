#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 一层一层看
	// 从左到右遍历，temp初始值为0
	// 对于当前的柱子，如果height[i]大于等于层数 则开始更新
	// 如果height[i]小于层数 而且已经开始更新 则 temp++
	// 如果height[i]大于等于层数 则ans += temp temp = 0;
	// 两层for 循环超时
	// https://leetcode.cn/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
    int trap(vector<int>& height) {
    	int sum = 0;
    	int top = getMax(height);
    	for(int h = 1; h <= top; ++h){
    		bool start = false;
    		int ans = 0;
    		int temp = 0;
    		for(int i = 0; i < height.size(); ++i){
    			if(height[i] >= h && !start) {
    				start = true;	
    			}
    			if(height[i] >= h && start){
    				ans += temp;
    				temp = 0;
    			}
    			if(height[i] < h && start) {
    				temp++;
    			}
    		}
    		sum += ans;
    	}
    	return sum;
    }
    int getMax(vector<int>& height){
    	int res = 0;
    	for(auto h : height){
    		res = max(h, res);
    	}
    	return res;
    }

    // 按照列来求
    // 分别求出左边和右边最高的墙
    // 和上面的做法一样复杂度是O(n^2)所以仍然超时
    int trap(vector<int>& height) {
    	int sum = 0;
    	for(int i = 0; i < height.size(); ++i){
    		int max_l = 0, max_r = 0;
    		for(int j = i-1; j >= 0; --j){
    			if(height[j] > max_l){
    				max_l = height[j];
    			}
    		}
    		for(int j = i+1; j < height.size(); ++j){
    			if(height[j] > max_r){
    				max_r = height[j];
    			}
    		}
    		int minist = min(max_l, max_r);
    		if(minist > height[i]){
    			// 只有较小的一段大于当前列的高度才会有水
    			sum = sum + (minist - height[i]);
    		}
    	}
    	return sum;
    }


    // 在求左边和右边最高的墙的时候，都是重新遍历一遍数组
    // 可以预先求每个柱子左边和右边最高的墙
    int trap(vector<int>& height){
    	int size = height.size();
    	int max_left[size];
    	int max_right[size];
		memset(max_left, 0, size);
		memset(max_right, 0, size);
    	int sum;
		for(int i = 1; i < size-1; ++i){
			max_left[i] = max(max_left[i-1], height[i-1]);
		}   
		for(int i = size-2; i >= 0; --i){
			max_right[i] = max(max_right[i+1], height[i+1]);
		} 	
		for(int i = 1; i < size-1; ++i){
			int minh = min(max_left[i], max_right[i]);
			if(minh > height[i]){
				sum += minh - height[i];
			}	
		}
		return sum;
    }
};






