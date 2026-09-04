class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd=0, even=0;
        int minodd=INT_MAX, mineven=INT_MAX;
        for(int i =0; i<n; i++) {
            if( nums1[i]%2==0) 
                {even++;
                mineven= min(mineven, nums1[i]);}
            
            else 
               { odd++;
                minodd = min(minodd, nums1[i]);}
            
        }
        if(even == n || odd ==n) return true;
        if(mineven>minodd) return true;
        return false;
        
    }
};