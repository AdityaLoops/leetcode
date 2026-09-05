class Solution {
    int solve(int i, int pstate, vector<int>& nums1, vector<int>& nums2,
              vector<vector<int>>& dp) {
        if (i == nums2.size())
            return 0;
        
        if(dp[i][pstate]!=-1) return dp[i][pstate];

        int swap = 1000001, dswap = INT_MAX;

        if (!pstate) {
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                swap = 1 + solve(i + 1, 1, nums1, nums2, dp);
            }

            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                dswap = solve(i + 1, 0, nums1, nums2, dp);

        } else {

            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
                swap = 1 + solve(i + 1, 1, nums1, nums2, dp);

            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
                dswap = solve(i + 1, 0, nums1, nums2, dp);
        }

        return dp[i][pstate] = min(swap, dswap);
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return min(solve(1, 0, nums1, nums2, dp),
                   1 + solve(1, 1, nums1, nums2, dp));
    }
};