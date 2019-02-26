class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        if(n==0||n==1)
            return A;
        int left = 0;
        int right = n-1;
        while(left<right){
            while((left<right)&&(A[left]&0x1)==0){
                left++;
            }
            while((left<right)&&((A[right]&0x1)!=0)){
                right--;
            }
            if(left<right){
                //cout<<left<<" "<<right;
                swap(A[left],A[right]);
                left++;
                right--;
            }
            //cout<<left<<" "<<right<<endl;
        }
        return A;
    }
};