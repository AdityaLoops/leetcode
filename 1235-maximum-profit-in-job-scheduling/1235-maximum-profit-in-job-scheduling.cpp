class Solution {
    int solve(int i, vector<int> &dp, vector<tuple<int,int,int>> &jobs){
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i]; 
        int prev;
        int low = 0, high =i-1;
        int ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            // end of mid is lessthanequal to start
            if( get<1>(jobs[mid]) <= get<0>(jobs[i])){
                low = mid+1;
                
            }
            else{
                high = mid-1;

            }
            
        }
        int take = get<2>(jobs[i]) + solve(high, dp,jobs);
        int dk = solve(i-1, dp,jobs);


return dp[i] = max(take,dk);

    }
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector<tuple<int,int,int>> jobs;
        for(int i=0 ;i <n;i ++) jobs.push_back({s[i],e[i],p[i]});

        sort(jobs.begin(), jobs.end(), []
        (auto &a, auto &b){
            return get<1>(a) < get<1>(b);
        });

        vector<int> dp(n,-1);
        return solve(n-1, dp, jobs);

    }
};