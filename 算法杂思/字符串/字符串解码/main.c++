#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string res;
    string decodeString(string s) {
        stack<pair<int, string>> sta;
        int num = 0; string res = "";
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += (s[i] - '0');
            }else if(s[i] == '[') {
                sta.push(make_pair(num, res));
                num = 0;
                res = "";
            }else if(s[i] == ']') {
                int n = sta.top().first;
                string a = sta.top().second;
                sta.pop();
                for(int i = 0; i < n; ++i) {
                    a = a + res;
                }
                res = a;
            }else {
                res += s[i];
            }
        }
        return res;
    }
};