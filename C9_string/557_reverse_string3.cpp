class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        cout<<"n "<<n<<" ";
        if(n<=1){
            return s;
        }else{
            for(int i=0;i<n;){
                int startIdx = i;
                int cnt = 0;
                while((s[i]!=' ')&&(i<n)){
                    cnt++;
                    i++;
                }
                cout<<"i "<<i<<" ";
                if(i<n){
                    reverse(s.begin()+startIdx,s.begin()+startIdx+cnt);                    
                }else{
                    reverse(s.begin()+startIdx,s.end());
                }
                i++;
            }
        }
        return s;
    }
};