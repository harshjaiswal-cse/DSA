class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
       if(n==0) return 0;
       if(n==1) return nums[0];
       int piche=0,piche2=0;
       for(int i=0;i<n;i++)
       {
        sum=max(piche,(piche2+nums[i]));
        piche2=piche;
        piche=sum;
       }
       return piche;
    }
};