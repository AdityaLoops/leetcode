class Solution {
    int solve(int i, int j, vector<vector<int>> &dp){
        if( i >=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans =INT_MAX;
        for(int k= i; k<=j; k++){
            int left =  solve(i, k-1, dp);
            int right = solve(k+1, j, dp);
            ans = min(ans, k+ max(left, right));
        }

        return dp[i][j]= ans;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(1,n, dp);
        
    }
};