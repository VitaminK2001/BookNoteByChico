#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	// 注意题目中的要求同一个元素不能再答案中重复出现
        unordered_map<int, int> map;
        unordered_set<int> set;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            map.insert({nums[i], i});
        }
        auto it = map.begin();

        for(int i = 0; i < nums.size(); ++i){
            if(map.count(target-nums[i])){
            	// 这样判断是一种冗余的做法
            	if(map[target-nums[i]] != i) {
            		set.insert(i);
                	set.insert(map[target-nums[i]]);	
            	}
            }
        }

        for(int s : set){
            res.push_back(s);
        }
        return res;
    }    

    // 简便的做法
    vector<int> twoSum(vector<int>& nums, int target){
    	unordered_map<int, int> map;
    	vector<int> res;
    	// 如果在遍历的过程中放入，就不需要用set去重，
    	// 而且在遇到同一个数的时候也不会把这个数用两次
    	for(int i = 0; i < nums.size(); ++i){
    		if(map.count(target-nums[i])){
    			res.push_back(map[target-nums[i]]);	
    			res.push_back(i);
    		}
    		map.insert({nums[i], i});
    	}
    	return res;
    }

    Solution(){};
};

int main(int argc, char const *argv[]){
    /* code */
    Solution s = Solution();
    vector<int> a = {3,2,4};
    int target = 6;
    vector<int> res;
    res = s.twoSum(a, target);
    for(int a : res){
    	cout << a << endl;
    }
    return 0;
}
