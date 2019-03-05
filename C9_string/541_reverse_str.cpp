class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        //cout<<"n "<<n<<" ";
        if(n<=1||k==1){
            return s;
        }
        if(k>n){
            reverse(s.begin(),s.end());
            return s;
        }
        int reverseTimes;
        int div = n/(2*k);
        int mod = n%(2*k);
        if(mod<=1){
            reverseTimes = div;
        }else{
            reverseTimes = div+1;
        }
        //cout<<"times "<<reverseTimes<<" ";
        for(int i=0;i<reverseTimes;i++){
            if((i*2*k+k)<n){
                reverse(s.begin()+(i*2*k),s.begin()+(i*2*k+k));                
            }else{
                reverse(s.begin()+(i*2*k),s.end());                
            }
        }
        return s;
        
    }
};