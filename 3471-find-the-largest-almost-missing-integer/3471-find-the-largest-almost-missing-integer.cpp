class Solution {

public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> hash(51,0);
        for(int i =0;i<n;  i++) hash[nums[i]]++;
        if(k == 1) {
            int ans =-1;
            for(int i=0; i<n; i++){

                if(hash[nums[i]]==1) ans= max(ans, nums[i]);
            }
            
            return ans;
        }
        if(k==n){
            int ans =-1;
            for(int i =0; i<n; i++){
                ans = max(ans, nums[i]);
            }
            return ans;

        }

        if(hash[nums[0]]==1  && hash[nums[n-1]]==1) return max(nums[0], nums[n-1]);
   
        else if (hash[nums[0]]==1) return nums[0];
        else if (hash[nums[n-1]]==1) return nums[n-1];
        return -1;
    }
};