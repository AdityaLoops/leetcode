class Solution {
    double solve(int i, int j, int daru, vector<vector<double>> &dp){
        if(i<0 || j<0) return 0;
        if( i==0 && j ==0) return  daru;
        
        if(dp[i][j]!=-1) return dp[i][j];

        double left = solve(i-1, j-1, daru, dp );
        double right = solve( i -1, j, daru, dp);

        double recieved = max(0.0 , (left-1)/2.0) + max(0.0, (right-1)/2.0);
        return dp[i][j] = recieved;
    }
public:
    double champagneTower(int poured, int row, int glass) {
        vector<vector<double>> dp(row+1, vector<double> (glass+1, -1));
        return min(1.0, solve(row, glass, poured, dp));
    }
};