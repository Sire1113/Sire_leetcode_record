class Solution {
public:
    int climbStairs(int n) {
        array<int, 2> dp{1,2};
        if (n<3)
            return dp[n-1];
        for (int i=2; i<n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};