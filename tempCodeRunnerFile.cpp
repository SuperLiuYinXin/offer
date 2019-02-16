class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() <= 1)
            return str;
            
        n = n % str.size();
        return str.substr(n) + str.substr(0, n);
        
    }
};