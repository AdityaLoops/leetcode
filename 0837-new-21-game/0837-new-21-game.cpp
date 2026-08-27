class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + maxPts +1, 0);
        if(k ==0) return 1.0;
        for(int i =k ;i<=n; i++){
            dp[i] =1;
        }
        double winsum =0;
        for(int i =k; i< k+ maxPts; i++){
                winsum += dp[i];
        }

        for(int i = k-1; i>=0; i-- ){
            dp[i] = winsum/maxPts;
            winsum += dp[i];
            winsum -= dp[i+maxPts]; 
        }
        return dp[0];
    }
};