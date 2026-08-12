class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0; int r=0;
        unordered_map<int,int> map;
        int maxlen=0;
        int currlen =0;

        while(r<n){
            auto &x= nums[r];
            map[x]++;
            currlen++;
            r++;
            if(map[x]>k) {
                while(map[x]>k && l<=r){
                    map[nums[l]]--;
                    l++;
                    currlen--;
                }
            }
            maxlen = max(maxlen, currlen);
        }
        return maxlen;
    }
};