#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class TreeNode{
    int val = 10;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto it = nums.begin(); it != nums.end(); ++it){
            set.insert(*it);
        }
        int longestlen = 0, streaklen = 0, cur = 0;
        for(auto num : set) {
            if(!set.count(num - 1)){
                int cur = num;
                int streaklen = 1;
                while(set.count(cur+1)){
                    cur += 1;
                    streaklen += 1;
                }
                longestlen = max(longestlen, streaklen);
            }
        }
        return longestlen;
    }
};
