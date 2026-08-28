class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int n = s1.size();
        for(int i =0; i<n; i++){
            hash1[s1[i]-'a']++;
        }

        int l =0, r=0;
        while(r<s2.size()){
            hash2[s2[r]-'a']++;
            r++;
            if(r-l>n){
                hash2[s2[l]-'a']--;
                l++;
            }
            if(hash1 == hash2) return true;

        }
        return false;
    }
};