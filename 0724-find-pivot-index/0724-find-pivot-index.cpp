class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> pref(n);
        vector<int> suf(n);

        pref[0]=nums[0]; suf[n-1] = nums[n-1];

        for(int i=1; i<n; i++) pref[i]= pref[i-1] + nums[i];
        for(int i=n-2; i>=0; i--) suf[i] = suf[i+1] +nums[i];
        if(suf[1]==0) return 0;

        for(int i =1; i<n-1 ; i++){
            if(pref[i-1] == suf[i+1]) return i;
        }
        if(pref[n-2]==0) return n-1;
        return -1;
    }
};