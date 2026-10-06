class Solution {
public:
    int minAddToMakeValid(string s) {
        int counter =0, n = s.size();
        stack<int> st;
        if ( n==0) return 0;
        for(int i=0; i< n ;i++){
            if( s[i]=='(') st.push(1);
            else {
                if(st.empty()) counter++;
                else st.pop();
            }
        }
        return st.size() + counter;
    }
};