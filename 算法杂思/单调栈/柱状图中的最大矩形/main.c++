#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 遍历宽度
        int res;
        int mianji;
        for(int left = 0; left < heights.size(); ++left) {
            int minHeight = INT_MAX;
            for(int right = left; right < heights.size(); ++right) {
                minHeight = min(minHeight, heights[right]);
                mianji = minHeight * (right-left+1);
                res = max(mianji, res);
            }
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        // 遍历高度
        int res;
        int mianji;
        for(int left = 0; left < heights.size(); ++left) {
            int minHeight = INT_MAX;
            for(int right = left; right < heights.size(); ++right) {
                minHeight = min(minHeight, heights[right]);
                mianji = minHeight * (right-left+1);
                res = max(mianji, res);
            }
        }
        return res;
    }
    // 单调栈
    int largestRectangleArea(vector<int>& heights) {
        stack<int> pos;
        int n = heights.size();
        vector<int> left(n), right(n);
        for(int i = 0; i < n; ++i) {
            while(!pos.empty() && heights[pos.top()] >= heights[i]){
                pos.pop();
            }
            left[i] = (pos.empty() ? -1 : pos.top());
            pos.push(i);
        }
        // 注意栈要清空之后才能用
        pos = stack<int>();
        for(int i = n-1; i >= 0; --i) {
            while(!pos.empty() && heights[pos.top()] >= heights[i]) {
                pos.pop();
            }
            right[i] = (pos.empty() ? n : pos.top());
            pos.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};

