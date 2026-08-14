class Solution {
    int solve(int i , int j, int n, vector<vector<int>> & dp){
        if( i == n) return 0;
        if( i >n || i+j>n) return 10000;
        if(dp[i][j]!=-1) return dp[i][j];
        int copy = INT_MAX;

        if( i !=j) copy = 1+ solve(i, i, n, dp);
        int paste = 1+solve(i+j,j,n,dp);

        return dp[i][j] = min(copy, paste);
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        if( n==1) return 0;
        return 1+ solve(1,1,n,dp);
    }
};