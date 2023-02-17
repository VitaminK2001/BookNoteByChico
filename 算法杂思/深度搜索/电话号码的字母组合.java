package 深度搜索;

import java.util.ArrayList;
import java.util.List;

class Solution {
    String[] letterMap = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    List<String> res = new ArrayList<>();
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return new ArrayList<>();
        StringBuffer combination = new StringBuffer();
        findCombination(digits, 0, combination);
        return res;
    }
    public void findCombination(String digits, int idx, StringBuffer combination){
        if(idx == digits.length()){
            res.add(new String(combination));
            return ; //注意需要直接返回
        }
        String s = letterMap[digits.charAt(idx)-'0']; //预先取idx对应的字符串
        for(int i = 0; i < s.length(); ++i) {
            combination.append(s.charAt(i));
            findCombination(digits, idx+1, combination);
            combination.deleteCharAt(combination.length()-1);
        }
    }
}
