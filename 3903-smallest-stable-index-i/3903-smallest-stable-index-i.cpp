class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mini=INT_MAX, maxi=-1;
        for(int i= 0; i<n; i++){
            maxi=max(maxi, nums[i]);
            mini=nums[i];
            for(int j =i+1; j<n; j++){
                mini = min(nums[j], mini);
            }
            if(maxi - mini<=k) return i;
            
        }
        
        return -1;
    }
};