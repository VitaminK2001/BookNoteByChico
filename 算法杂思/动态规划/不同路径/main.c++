#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; ++i){
            // 对每一行第一列
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            // 对每一列第一行
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};