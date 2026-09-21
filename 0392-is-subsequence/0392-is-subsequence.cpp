class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), c=0;
        vector<int> hash(26);
        for(int i=0; i<n; i++) hash[s[i]-'a']++;
        for(int i=0; i<m ; i++){
            if(s[c] == t[i] ){
                hash[s[c]-'a']--;
                c++;
            }
        }
        for(int i=0; i<26; i++) if(hash[i]>0) return false;
        return true;
    }
};