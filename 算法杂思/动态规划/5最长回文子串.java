package 算法.Leetcode.dynamic;

class Solution {
    public String longestPalindrome(String s){
        int n = s.length();
        int maxlen = 1;
        int pos = 0;
        boolean[][] dp = new boolean[n][n];
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         dp[i][j] = false;
        //     }
        // }
        //dp[i][j]表示字符串s[i~j]是否是回文串
        //初始化
        for(int i = 0; i < n; ++i){
            dp[i][i] = true; //自己一个字符永远是回文串
        }
        if(n == 1) return s;
        //枚举起点位置和长度
        for(int l = 2; l <= n; ++l){
            for(int i = 0; i < n; ++i){
                int j = i+l-1;
                if(j >= n) break;
                char a = s.charAt(i);
                char b = s.charAt(j);
                if(a == b) {
                    if(j-i<3) dp[i][j] = true;
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }else {
                    dp[i][j] = false;
                }
                if(dp[i][j] && j-i+1 > maxlen){
                    maxlen = j-i+1;
                    pos = i;
                }
            }
        }
        return s.substring(pos, pos+maxlen);
    }
}

