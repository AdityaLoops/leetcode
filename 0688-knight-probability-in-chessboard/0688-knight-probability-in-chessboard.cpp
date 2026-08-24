class Solution {
    double solve( int r, int c, int k, int n, vector<vector<vector<double>>> &dp){
        if(r<0 || c < 0 || r>=n || c>=n) return 0;
        if( k == 0 ) return 1;
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        int drow[] = {2,2,-2,-2,1,-1,-1,1};
        int dcol[] = {1,-1,1,-1,2,-2,2,-2};
        double currprob = 0;
        for(int i =0; i<8; i++){
            currprob += solve(r + drow[i], c + dcol[i], k-1, n, dp);
        }
        return dp[r][c][k] = (1/8.0)*currprob;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k+1, -1)));
        return solve(row, column, k, n, dp);
    }
};