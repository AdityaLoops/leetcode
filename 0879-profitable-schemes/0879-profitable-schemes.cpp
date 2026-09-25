class Solution {
    const int MOD = 1e9 +7;
    int solve(int i , int n, int p, int minp, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>> &dp){
        if(i>=group.size()) {
            if(p>=minp && n>=0) return 1;
            else return 0;
        }
        if(n<0) return 0;
        int x = min(p, minp);
        if(dp[i][n][x]!=-1) return dp[i][n][x]%MOD;

        int take = solve(i+1, n-group[i], p+ profit[i], minp, group, profit, dp);
        int dtake = solve(i+1, n, p, minp,group, profit, dp);
        
        return dp[i][n][x] = (take%MOD + dtake%MOD)%MOD;



    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n+1, vector<int> (minProfit+1,-1)));
        return solve(0,n,0,minProfit,group,profit,dp);
    }
};