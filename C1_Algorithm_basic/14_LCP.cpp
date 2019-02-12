class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string e = "";
        if(n==0) return e;
        string pre = strs[0];
        for(int i=1;i<n;i++){
            while(strs[i].find(pre)!=0){
                pre = pre.substr(0,pre.size()-1);
                if(pre.size()==0)
                    return e;
            }
        }
        return pre;
        
    }
};