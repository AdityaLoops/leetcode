class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int rem0=0, rem1=0, rem2=0;
        int n = stones.size();
        if(n==1) return false;
        for(int i =0; i<n; i++){
            int r = stones[i]%3;
            if( r ==2) rem2++;
            else if( r==1) rem1++;
            else rem0++;
        }
        
        if(rem1==rem2 && rem1!=0){
            if(rem0%2==0) return true;
            return false;
        }
        else if ( rem1==rem2) return false;

       if (rem0 % 2 == 0)
    return rem1 > 0 && rem2 > 0;

return abs(rem1 - rem2) > 2;
    }
};