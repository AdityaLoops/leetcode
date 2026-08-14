class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int> hash(26);

        int l = 0, r = 0, maxlen = 0;
        while (r < n) {
            auto& c = s[r];
            hash[c - 'a']++;
            r++;

            while (hash[c - 'a'] > 2) {
                hash[s[l] - 'a']--;
                l++;
            }

            maxlen = max(maxlen, r - l);
        }
        return maxlen;
    }
};