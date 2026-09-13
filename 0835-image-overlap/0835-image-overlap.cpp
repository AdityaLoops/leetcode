class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans= 0;

        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                int count =0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        if (img1[i][j] == 0)
                            continue;
                        int row = i+dx, col = j + dy;
                        if(row>=0 && row< n && col >=0 && col<n && img2[row][col]==1){
                            count++;
                        }
                    }
                }ans = max(ans, count);

            }
        }
        return ans;
    }
};