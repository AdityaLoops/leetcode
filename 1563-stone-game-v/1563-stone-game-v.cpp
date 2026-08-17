class Solution {
    int solve(int i, int j,vector<int> &pref,  vector<int> &arr, vector<vector<int>>&dp){
        if (i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxst=0;
        int stones =0;
        for(int k =i; k<j; k++){
            int temp=INT_MIN;
            stones += arr[k];
            int after = pref[j] - pref[k];
            if(stones>after)  temp = after + solve( k+1, j, pref, arr, dp);
            else if (stones<after) temp = stones + solve(i, k, pref, arr,dp);
            else {
                temp = stones + max(solve(i,k, pref,arr,dp), solve(k+1, j,pref, arr,dp));
            } 
            maxst = max(maxst , temp);
        }
        return dp[i][j] = maxst;

    }
public:
    int stoneGameV(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n+1);
        pref[0] = arr[0];
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + arr[i];
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n-1, pref, arr,dp);
    }
};