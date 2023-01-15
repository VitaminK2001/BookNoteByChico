#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return res;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return res;
    }
    // 此题最关键的地方在于如何去重
    // 去重的关键在于不走回头路
    // 即不考虑已经考虑过的数字
    // 具体体现在 设置每轮深度搜索的起点，起点之前的数组不在这轮深度搜索路径中
    void  helper(vector<int>& candidates, int start, int target) {
        if(target == 0) {
            res.push_back(path); //不需要清空path 因为需要回溯
            return ;
        }
        // 如果大于0
        for(int i = start; i < candidates.size(); ++i){
            if(target - candidates[i] < 0) break ;
            path.emplace_back(candidates[i]);
            helper(candidates, start, target-candidates[i]);
            path.pop_back();
        }
    }
};
