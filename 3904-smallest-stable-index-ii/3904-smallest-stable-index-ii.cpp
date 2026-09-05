class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suf(n,INT_MAX);
        pref[0]= nums[0]; 
        suf[n-1] = nums[n-1];
        for(int i =1; i<n ;i++) pref[i] = max(pref[i-1], nums[i]);
        for(int i =n-2; i>=0; i--) suf[i] = min(suf[i+1], nums[i] );
        
        for(int i =0; i< n;i++){
            int score = pref[i] - suf[i];
            if( score<=k) return i;
        }
        return -1;
    }
};