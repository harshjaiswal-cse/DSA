class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int current_sum = 0;
        int count = 0;
        
        for (int x : nums) {
            current_sum += x;
            if (mp.find(current_sum - k) != mp.end()) {
                count += mp[current_sum - k];
            }
            mp[current_sum]++;
        }
        
        return count;
    }
};