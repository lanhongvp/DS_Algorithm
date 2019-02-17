class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0;
        if(n==0 || n=a=1) return;
        while(i<=(n/2-1)){
            swap(s[i],s[n-1-i]);
            i++;
        }
    }
};