class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> hash(10);
        for(int i =0; i<n; i++) hash[digits[i]]++;
        int ans =0;
        for(int i=100; i<999; i+=2){
            vector<int> temp = hash;
           
            bool flag = true;
            int x =i;
            for(int j = 0; j<3; j++){
                int l = x%10;
                x/=10;
                if(temp[l]<=0) {
                    flag = false; break;
                }
                else temp[l]--;
            }
            if(flag) ans++;
        }
        return ans;

    }
};