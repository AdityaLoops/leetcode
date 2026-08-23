class Solution {
    bool solve(int i, vector<int>& dp){
        if(i ==1 ) return false;
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        for(int j =1; j<i; j++){
            
            if(i%j==0) {
                bool temp = solve(i-j,dp);
                ans = !temp||ans;
            }
        }
        return dp[i] = ans;
    }
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};