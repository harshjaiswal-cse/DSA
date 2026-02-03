class Solution {
public:
    int smallestEvenMultiple(int n) {
        
    int temp=n;
    if(temp%2==0){
        return temp;
    }
    else
    {
        return {(2*temp)};
    }
     return{};
    }
   
};