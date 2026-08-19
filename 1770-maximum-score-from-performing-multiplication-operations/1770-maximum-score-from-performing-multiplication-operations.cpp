class Solution {
    int solve(int i, int j, vector<int> &nums, vector<int> &mul, vector<vector<int>> & dp){
        int n = nums.size(), m = mul.size();
        if(i+j>=mul.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int curr = i+j;

        int no1= nums[i] * mul[curr] + solve(i+1, j, nums, mul, dp);
        int no2 = nums[n-1-j] * mul[curr] + solve(i, j+1, nums, mul,dp);

        return dp[i][j] = max(no1, no2);


    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n= nums.size(), m = multipliers.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0,0,nums, multipliers, dp);
    }
};