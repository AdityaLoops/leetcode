class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        if( n ==1) return 1;
        vector<int> dp(n, 0);
        vector<int> lastseen(26,-1);
        lastseen[s[0]-'a'] = 1;
        dp[0] = 2;
        const int MOD = 1e9 +7;
        
        for(int i =1; i<n ; i++){
            if(lastseen[s[i]-'a']==-1){
                dp[i] = ((dp[i-1]%MOD)*2)%MOD;
                
            }
            else {
                dp[i] = ((dp[i-1]*2)%MOD - lastseen[s[i]-'a'] + MOD)%MOD;

            }
            lastseen[s[i]-'a'] =dp[i-1];
        }
        return (dp[n-1]-1 + MOD)%MOD;
    }
};