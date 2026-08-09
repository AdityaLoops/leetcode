class Solution {
    int solve(int i , int j, vector<int> & arr, vector<vector<int>> &dp){
        if(i == j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int leftmax =0;
        int ans =INT_MAX;
        for(int k = i; k<j; k++){
            leftmax=max(leftmax, arr[k]);
            int rightmax = *max_element(arr.begin()+k+1, arr.begin()+j+1);
            ans = min(ans,solve(i, k, arr,dp) + solve(k+1,j, arr,dp) + (leftmax*rightmax) );
        }
        return dp[i][j]= ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), -1));
        return solve(0, arr.size()-1, arr, dp);
    }
};