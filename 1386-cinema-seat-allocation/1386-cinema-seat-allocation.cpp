class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        int m = seats.size();
        sort(seats.begin(), seats.end());
        int ans = 2*n;
       
       int i =0;
       while(i<m ){
        int row = seats[i][0];
        bool left = true, right = true, mid = true;

        int j = i;
        while( j< m && seats[j][0]==row){
            if(seats[j][1] >=2 && seats[j][1]<=5) left =false;
            if ( seats[j][1] >=4 && seats[j][1] <=7) mid = false;
            if (seats[j][1]>=6 && seats[j][1]<=9) right = false;
            j++;
        }
        int f =0;
        if(left && right) f =2;
        else if ( right || left || mid) f =1;
        else f =0;
        cout << ans<< " ";
        ans -= 2 -f;
        i =j;
       }
       return ans;
    }
};