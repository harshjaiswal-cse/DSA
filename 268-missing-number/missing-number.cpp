class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size();
       int  realsum=s*(s+1)/2;
      int  actualsum=0;
        for(int num:nums){
        actualsum+=num;
        }
        return realsum-actualsum;
    }
};