class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>rep;
       
        for(int x:nums)
        {
            rep[x]++;
            if(rep[x]>1)
            {
                return x;
            }
        }
        return -1;
    }
};