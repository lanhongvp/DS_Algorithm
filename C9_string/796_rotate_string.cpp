class Solution {
public:
    bool rotateString(string A, string B) {
        int n = A.size();
        if(n==0 && A==B) return true;
        while(n>0){
            string s = A.substr(1)+A[0];
            if(s==B) return true;
            A = s;
            n--;
        }
        return false;
    }
};