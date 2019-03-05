class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int L = 0,R = n-1;
        int tmp[2] = {-1,-1};
        int tmp1[2] = {0,0};
        if(n<=0||(n==1 && nums[0]!=target)){
            ans.insert(ans.begin(),tmp,tmp+2);
            return ans;
        }else if(n==1&&nums[0]==target){
            ans.insert(ans.begin(),tmp1,tmp1+2);
            return ans;
        }
        if(target<nums[0]||target>nums[n-1]){
            ans.insert(ans.begin(),tmp,tmp+2);
            //cout<<"haha";
            return ans;
        }
        //the first element
        int fPos;
        fPos = firstPos(nums,L,R,target);
        ans.push_back(fPos);
        //the last element
        int lPos;
        lPos = lastPos(nums,L,R,target);
        ans.push_back(lPos);
        return ans;
    }
    
    int firstPos(vector<int>& nums,int L,int R,int target){
        while(L<R){
            int M = L+(R-L)/2;
            if(nums[M]>=target){
                R = M;
            }else{
                L = M+1;
            }
        }
        //cout<<"first "<<L<<" "<<R<<" ";
        if(nums[L]!=target)
            return -1;
        else
            return R;
    }
    
    int lastPos(vector<int>& nums,int L,int R,int target){
        while(L<R){
            int M = L+(R-L)/2;
            if(nums[M]>target){
                //cout<<nums[M]<<" ";
                R = M;
            }else{
                L = M+1;
            }
        }
        //cout<<"last "<<L<<" "<<R<<" ";
        if((nums[L-1]!=target)&&(nums[L]!=target))
            return -1;
        else if(nums[L]==target){
            return L;            
        }else{
            return L-1;
        }
    }

};