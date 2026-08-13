class Solution {
    int solve(int i, int del, vector<int> &arr, vector<vector<int>> & dp){
        if(i == arr.size()) return 0;
        if(dp[i][del]!=INT_MIN) return dp[i][del];

        
        int del0=INT_MIN, take0=INT_MIN, take1=INT_MIN, end1 = INT_MIN, end0=INT_MIN;
        if(!del){
            if( i+1<arr.size()) del0 = solve(i+1,1, arr, dp );
            take0 = arr[i] + solve(i+1, 0, arr,dp);
            end0=arr[i];
        }
        else {
            take1= arr[i]+solve(i+1, 1, arr,dp);
            end1 = arr[i];
        }
        return dp[i][del]= max(take1, max(take0,max(del0, max(end0, end1))));
    }
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (2, INT_MIN));
        int ans =INT_MIN;
        for(int i=0; i<n; i++) ans = max(ans, solve(i,0,arr,dp));
        return ans;
    }
};