class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>num;
        for(int i=0;i<numbers.size();i++)
        {
          int complement=target-numbers[i];
           if(num.find(complement)!=num.end())
           {
            return {num[complement]+1,i+1};
           }
           else
           {
            num[numbers[i]]=i;
           }
        }
        return {};
    }
};