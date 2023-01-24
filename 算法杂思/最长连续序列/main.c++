// https://leetcode.cn/problems/longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 解法1 每次在数组中找下一个连续的元素 如果找到更新长度，找不到break
    // 解法没有问题，但是超时
    // 第一点，可以通过哈希表判断cur+1是否在数组中
    // 第二点，没有必要遍历整个数组，因为有些是无用功
    //      如果有比当前的数小1的数则不会进行+1遍历
    //      数组中可能存在重复的元素
    int longestConsecutive(vector<int>& nums) {
        int length = nums.size();
        int len = 0;
        int cur = 0;
        for(int i = 0; i < length; ++i){
            cur = nums[i];
            int flag = 1;
            while(flag){
                int find = 0;
                for(int j = 0; j < length; ++j){
                    if(nums[j] == cur+1){
                        find = 1;
                        break;
                    }
                }
                if(find){
                    cur++;
                }else {
                    flag = 0;
                }
            }
            len = max(len, cur-i+1);
        }
        return len;
    }

    // 哈希表优化
    int longestConsecutive2(vector<int>& nums) {
        unordered_set<int> set;
        if(nums.size() == 0) return 0; //如果是空集则返回长度0
        int len = 1;
        for(auto num : nums){
            set.insert(num);
        }
        for(auto num : set){
            if(set.count(num-1) == 0){
                int cur = num+1;
                while(set.count(cur)){
                    len = max(len, cur-num+1);
                    cur++;
                }
            }
        }
        return len;
    }   

    // 还有一种优化思路是，记录每一个元素能够到达的最远右边界 
    // 这样不需要每次遍历才能知道最远右边界
    int longestConsecutive3(vector<int>& nums) {
        // key: 遍历到的数字
        // value：数字能够达到的最远右边界的值
        unordered_map<int, int> map;
        int ans;
        for(int num : nums){
            // 初始化每个数字的右边界为自己
            // 重复的数字的value不会被insert覆盖掉
            // map中不会存放重复的key，此题中就算重复，value值也是相同的
            map.insert({num, num});
        }
        unordered_map<int, int>::iterator it = map.begin();
        vector<int> key;
        // 取出map中的所有key
        for(; it != map.end(); ++it){
            key.push_back(it->first);
        }
        for(int i = 0; i < key.size(); ++i){
            if(!map.count(key[i]-1)){
                int right = map.at(key[i]); //直接取出能够到达的右边界
                while(map.count(right+1)){
                    right = map.at(right+1); //更新right为最远的右边界
                }
                // 此时会覆盖掉原先的“最远”右边界
                map[key[i]] = right; //这里不能用insert，这样是不会覆盖掉相同key的值的
                // 更新答案
                ans = max(ans, right-key[i]+1);
            }
        }
        return ans;
    }
};


