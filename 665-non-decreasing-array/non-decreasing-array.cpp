class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n - 1; i++) {
            // Sirf jab bada number chote ke pehle aaye
            if(nums[i] > nums[i+1]) { 
                count++;
                if(count > 1) return false;

                if(i == 0 || nums[i-1] <= nums[i+1]) {
                    nums[i] = nums[i+1];
                } else {
                    nums[i+1] = nums[i];
                }
            }
        }
        return true;
    }
};