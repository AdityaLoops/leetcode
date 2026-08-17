class Solution {
    int solve(int i, int state, int fee, vector<int> &p, vector<vector<int>> &dp){
        if(i==p.size()) return 0;
        if(dp[i][state]!=-1) return dp[i][state];

        int next = solve(i+1, state, fee, p,dp);
        int sell = INT_MIN, purchase = INT_MIN;
        if(state){
            sell = p[i] + solve(i+1, 0, fee, p ,dp) ;
        }
        else {
            purchase = solve(i+1, 1, fee, p,dp) - p[i]-fee;
        }
        return dp[i][state] = max(sell, max(next, purchase));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0,0,fee, prices, dp);
    }
};