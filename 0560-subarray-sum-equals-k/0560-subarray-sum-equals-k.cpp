class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        
        
        int pref=0;
        int ans=0;
        mp[0]=1;
        for(int i =0; i < n ; i++){
            pref+= nums[i];
            int req = pref - k;
            ans+= mp[req];

            mp[pref]++;
        }
    return ans;
    }
};