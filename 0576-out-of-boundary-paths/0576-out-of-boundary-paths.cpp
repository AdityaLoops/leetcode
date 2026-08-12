typedef long long ll;
class Solution {
    int solve(int row, int col, int m, int n, int moves, int limit,  vector<vector<vector<ll>>> & dp){
        const int MOD = 1e9 +7;
        if(moves > limit) return 0;
        if(row < 0 || row>=m || col<0 || col >=n) return 1;
        if(dp[row][col][moves]!=-1) return dp[row][col][moves];

        ll choices = 
                        1ll*solve(row +1, col, m,n, moves+1, limit , dp)%MOD +
                        1ll*solve(row, col+1, m,n, moves+1, limit , dp)%MOD +
                        1ll*solve(row-1, col, m,n, moves+1, limit , dp)%MOD +
                        1ll*solve(row, col-1, m,n, moves+1, limit , dp)%MOD;
            cout<< row << " " << col << " " << moves << " "<< choices << "\n";
            return dp[row][col][moves]= choices%MOD;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>> (n+1, vector<ll> (maxMove +1, -1)));
        return solve(startRow, startColumn, m, n, 0, maxMove, dp);
    }
};