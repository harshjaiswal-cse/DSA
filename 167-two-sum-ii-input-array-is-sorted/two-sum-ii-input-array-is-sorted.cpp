class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        int sum=0;
        while(left<right)
        {
            int complement=numbers[left]+numbers[right];
            if(complement==target)
            {
              return {left+1,right+1};}
              else if(complement<target)
              {
                left++;
              }  
              else
              {
                right--;
              }
        }
            return{};
        }
};