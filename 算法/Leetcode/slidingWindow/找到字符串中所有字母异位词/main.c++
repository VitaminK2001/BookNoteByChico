#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;

class Solution{
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> map;
        vector<int> res;
        int count[26];
        // 统计单词出现的次数
        for(char c : p){
            if(map.count(c)){
                map.at(c) += 1;
            }else {
                map.insert(make_pair(c, 1));
            }
        }
        for(int i = 0; i < s.length(); ++i){
            if(map.count(s[i])){
                count[s[i]-'a']++;
                if(count[s[i]-'a'] > map.at(s[i])) {
                    memset(count, 0, sizeof(int) * 26);
                    continue;
                }
                int j = i + 1;
                for(; j < i + p.length(); ++j){
                    // 如果接着的字符在p中
                    if(map.count(s[j])) {
                        count[s[i]-'a']++;
                    }
                    // 如果接着的字符不在p中
                    if(!map.count(s[j])){
                        i = j+1;
                        memset(count, 0, sizeof(int)*26);
                        break;
                    }
                    // 如果字符的数量超过
                    if(count[s[i]-'a'] > map.at(s[i])){
                        memset(count, 0, sizeof(int)*26);
                        break;
                    }
                }
                if(j == (i+p.length())){
                    vector<char> vc;
                    for(unordered_map<char, int>::iterator it = map.begin(); it != map.end(); ++it){
                        vc.push_back(it->first);
                    }
                    // 如果count中的
                    int flag = true;
                    for(const char &ch : vc) {
                        if(map.at(ch) != count[ch-'a']) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) res.push_back(i);
                }
            }
        } 
        return res;
    }

    // 滑动窗口
    vector<int> findAnagrams(string s, string p){
        int slen = s.size();
        int plen = p.size();
        if(slen < plen){
            return vector<int>();
        }
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for(int i = 0; i < plen; ++i){
            ++sCount[s[i]-'a'];
            ++pCount[p[i]-'a'];
        }
        if(sCount == pCount){
            ans.emplace_back(0);
        }
        for(int i = 0; i < slen - plen; ++i){
            --sCount[s[i]-'a'];
            ++sCount[s[i+plen]-'a'];

            if(sCount == pCount){
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
    int a[3];
    memset(a, -1, sizeof(int)*3);
    for(int i = 0; i < 3; ++i) {
        cout << a[i] << endl;
    }
}