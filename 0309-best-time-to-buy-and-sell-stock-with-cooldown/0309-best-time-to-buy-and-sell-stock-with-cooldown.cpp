class Solution {
    int solve(int i, int state, vector<int>& prices, vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][state]!=-1) return dp[i][state];

        int skip = solve(i+1, state, prices, dp);
        // 0 == sold , 1 == Buyed
        int p=INT_MIN;
        if(state){
            p = prices[i] + solve(i+2, 0, prices,dp);
        }
        else {
            p = solve(i+1, 1, prices, dp) - prices[i];
        }

        return dp[i][state] = max(skip, p);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 0, prices, dp);
       
    }
};