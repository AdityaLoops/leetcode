class Solution {
public:
    using vb = vector<int>;
    using vvb = vector<vb>;
    using vvvb = vector<vvb>;
    using vvvvb = vector<vvvb>;
    vvb pos = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    struct state {
        int row;
        int col;
        int e;
        int collectedmask;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startr = -1, startc = -1;
        int litterbit[20][20];
        int littercount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterbit[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    startr = i;
                    startc = j;
                } else if (classroom[i][j] == 'L') {
                    litterbit[i][j] = littercount;
                    littercount++;
                }
            }
        }
        int allcollected =
            (1 << littercount) - 1; // this is equivalent to 2^littercount -1

        if (allcollected == 0)
            return 0;

        vvvvb vis(m, vvvb(n, vvb(energy + 1, vb(1 << littercount, 0))));
        queue<state> q;
        q.push({startr, startc, energy, 0});
        vis[startr][startc][energy][0] = 1;

        int moves = 0;
        while (!q.empty()) {

            int currsize = q.size();

            while (currsize--) {
                state curr = q.front();
                q.pop();

                if (curr.collectedmask == allcollected) {
                    return moves;
                }
                if (curr.e == 0)
                    continue;

                for (auto& posi : pos) {
                    int crow = posi[0] + curr.row;
                    int ccol = posi[1] + curr.col;

                    if (crow < 0 || crow >= m || ccol < 0 || ccol >= n) {
                        continue;
                    }

                    char cell = classroom[crow][ccol];

                    if (cell == 'X')
                        continue;

                    int cenergy = curr.e - 1;
                    int ccollectedmask = curr.collectedmask;

                    if (cell == 'R')
                        cenergy = energy;
                    if (cell == 'L')
                        ccollectedmask |= (1 << litterbit[crow][ccol]);

                    if (vis[crow][ccol][cenergy][ccollectedmask] != 1) {
                        vis[crow][ccol][cenergy][ccollectedmask] = 1;
                        q.push({crow, ccol, cenergy, ccollectedmask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};