class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int ans =0;
        int d =1;

        for(int i =1; i<n ; i++){
            if(s[i] == '(') d ++;
            else {
                if(s[i-1]=='('){
                    ans += pow(2, d-1);
                }
                d--;
            }
            

        }
        return ans;
    }
};