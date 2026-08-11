class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]+1;
        vector<int> hash(2501);
        vector<int> len(n);
        len[0] = 1;
        for (auto& x : nums)
            hash[x]++;
        
        int id;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                len[i] = len[i - 1] + 1;
                id = i;
            } else
                break;
        }

        int sum = 0;
        while (id >= 0) {
            sum += nums[id--];
        }

        for (int i = sum; i < 2501; i++) {
            if (hash[i] == 0)
                return i;
        }
        return 0;
    }
};