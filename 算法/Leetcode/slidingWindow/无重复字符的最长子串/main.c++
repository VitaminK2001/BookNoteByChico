#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 滑动窗口
    // 右指针负责添加字符
    // 左指针负责删除字符
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0;
        // 子串的最大长度
        int res = 0;
        while(right < s.length()) {
            // 将要加入的字符
            char c = s[right];
            right++;
            map[c]++;
            // 进行窗口内数据的更新
            while(map[c] > 1){
                char d = s[left];
                left++;
                // 进行窗口内数据的更新
                map[d]--;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
