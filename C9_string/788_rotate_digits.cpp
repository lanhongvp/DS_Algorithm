class Solution {
public:
    int rotatedDigits(int N) {
        if(N<1)
            return N;
        string s;
        int cnt = 0;
        for(int i=1;i<=N;i++){
            s = to_string(i);
            bool flag = 0;
            if((s.find('3')==-1)&&(s.find('4')==-1)&&(s.find('7')==-1)){
                for(int j=0;j<s.size();j++){
                    if((s[j]=='2')||s[j]=='6'||s[j]=='9'||s[j]=='5'){
                        flag = 1;
                    }
                }
                if(flag){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};