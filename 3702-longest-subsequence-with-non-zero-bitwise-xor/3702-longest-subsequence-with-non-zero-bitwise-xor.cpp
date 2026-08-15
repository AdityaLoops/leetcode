class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool flag= false;
        int xorr =nums[0];
        for(int i =1; i<n; i++){
            xorr ^= nums[i];
            if(nums[i]!=0) flag =true;
        }
        if(xorr!=0) return n;
        else if (flag) return n-1;
        else return 0;
    }
};