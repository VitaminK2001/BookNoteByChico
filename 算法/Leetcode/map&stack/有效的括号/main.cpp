#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        int len = s.length();
        if(len % 2 != 0) return false;
        map<char, char> open;
        open.insert({'(', ')'});
        open.insert({'{', '}'});
        open.insert({'[', ']'});
        int idx = 0;
        stack<char> st;
        for(char ch : s){
            if(open.count(ch)){
                // 如果找到
                st.push(ch);
            }
            else{
                // 如果没找到
                if(st.empty() || ch != open[st.top()]) {
                    return false;
                }
                //如果匹配
                st.pop(); //无返回值
            }
        }
        return st.empty();
    }
};