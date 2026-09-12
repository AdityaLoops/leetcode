class Solution {

    bool better(pair<long long, vector<int>> &a, pair<long long, vector<int>> &b){
        if(a.first!=b.first) return a.first>b.first;
        return a.second<b.second;

    }

    pair<long long, vector<int>> solve(int i, int cnt, vector<vector<pair<long long, vector<int>>>> &dp, vector<vector<int>>& intervals){
        if(i<0) return {0,{}};
        if(cnt == 4 ) return {0, {}};
        if(dp[i][cnt].first!=-1) return dp[i][cnt];

        pair<long long, vector<int>> skip = solve( i-1, cnt, dp, intervals);

        
        int low =0, high=i-1;
        while(low<=high){
            int mid = high - (high-low)/2;

            if(intervals[mid][1] < intervals[i][0]) low = mid+1;
            else high = mid-1;
            
        }
        pair<long long, vector<int>> take; 
        take = solve(high, cnt+1, dp, intervals);
        take.first += intervals[i][2];
        take.second.push_back(intervals[i][3]);
        sort(take.second.begin(), take.second.end());


        pair<long long, vector<int>> ans;
        if(better(take, skip)){
            ans = take;
        }
        else ans= skip;
        return dp[i][cnt] = ans;

    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i =0 ; i<n ;i++) intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1]<b[1];
        });

        vector<vector<pair<long long, vector<int>>>> dp(n, vector<pair<long long, vector<int>>>  (5, {-1, {}}));
        return solve(n-1, 0,dp, intervals).second;



    }
};