#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    vector<int> temp(n+2);
    temp[0] = 1;
    temp[n+1] = 1;
    for(int i = 1; i <= n; ++i) {
        temp[i] = nums[i-1];
    }
    for(int len = 3; len <= n + 2; len++) {
        for(int l = 0; l <= n + 2 - len; ++l) {
            for(int k = l + 1; k < l + len - 1; ++k) {
                int left = dp[l][k];
                int right = dp[k][l + len - 1];
                int sum = left + right + temp[k] * temp[l] * temp[l + len - 1];
                dp[l][l + len - 1] = max(dp[l][l + len - 1], sum);
            }
        }
    }
    return dp[0][n+1];
}