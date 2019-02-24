class Solution {
public:
    bool judgeCircle(string s) {
        int n = s.size();
        int cnt1 = 0,cnt2 = 0,cnt3 = 0,cnt4 = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                cnt1++;
            }
            if(s[i]=='D'){
                cnt2++;
            }
            if(s[i]=='L'){
                cnt3++;
            }
            if(s[i]=='R'){
                cnt4++;
            }
        }
        if((cnt1==cnt2)&&(cnt3==cnt4))
            return true;
        else
            return false;
    }
};