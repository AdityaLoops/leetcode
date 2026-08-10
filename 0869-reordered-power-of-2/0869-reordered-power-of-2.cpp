class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n == 1)
            return true;
        long long  x = 2;
        string s = to_string(n);
        vector<int> hash(10);
        for (auto& ch : s)
            hash[ch - '0']++;

        while (to_string(x).size() <= s.size()) {

            string str = to_string(x);
            vector<int> thash(10);
            for (auto& ch : str)
                thash[ch - '0']++;
            bool flag = true;
            for (int i = 0; i < 10; i++) {
                if (hash[i] != thash[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
            x *= 1LL* 2;
        }
        return false;
    }
};