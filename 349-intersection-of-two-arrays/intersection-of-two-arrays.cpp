class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       
        unordered_set<int>s(nums1.begin(),nums1.end());
        vector<int>result;
        for(int c:nums2)
        {
            if(s.count(c))
            {
                result.push_back(c);
                s.erase(c);
            }
        }
        return result;
    }
};