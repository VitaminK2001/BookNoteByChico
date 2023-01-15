#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 最终的长度和起始位置
        int resLen = INT_MAX, resStart = 0;
        // need存放t中字符和相应数量
        // count存放s中实际的数量
        // valid表示已经达到要求的字符数量
        int left = 0, right = 0, valid = 0;
        unordered_map<char, int> need, count;
        for(char ch : t){
            count[ch]++;
        }
        int size = count.size();
        while(right < s.length()){
            char rch = s[right];
            right++;
            if(count.count(rch)){
                need[rch]++;
                if(need[rch] == count[rch]) {
                    valid++;
                }
            }
            // 右指针指向的永远是还没有加入的 所以长度是right-left
            while(valid == size){
                if(right-left < resLen){
                    resLen = right-left;
                    resStart = left;
                }
                char lch = s[left];
                left++;
                if(count.count(lch)){
                    if(need[lch] == count[lch]){
                        valid--;
                    }
                    need[lch]--;
                }
            }
        }
        return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
    }    
};