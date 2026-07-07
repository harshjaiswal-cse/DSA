class Solution {
public:
    bool isValid(string s) {
        stack<char>k;
        unordered_map<char,char>mp{
            {')','('},
            {'}','{'},
            {']','['}
            };
            for(char c:s){
            if(mp.count(c))
            {
if(k.empty()|| k.top()!=mp[c])
{
    return false;
}
k.pop();
            }
            else
            {
                k.push(c);
            }

        
    }
    return k.empty();
}
};