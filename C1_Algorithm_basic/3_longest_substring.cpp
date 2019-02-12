class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int freq[256] = {0};
        int L = 0;
        int R = 0;
        int cnt = 0;
        if(n==0) return 0;
        if(n==1) return 1;
        while(L<n){
            if((R<n) && freq[s[R]]==0){
                freq[s[R]]++;
                R++;
            }else{
                freq[s[L]]--;
                L++;
            }
            cnt = max(cnt,R-L);
        }
        return cnt;
    }
};