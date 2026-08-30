class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> hash(101);
        
        for(int i=0; i<n; i++) hash[nums[i]]++;
        int ans =0;
        
        
        for(int i=0; i<n; ){
           int x= nums[i];
           int len =0;
           while(i<n && nums[i]==x){
            len++;
            i++;
           }
           if(len == hash[x]) ans++;
        }
        

        return ans;
    }
};