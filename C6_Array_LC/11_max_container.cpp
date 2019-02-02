 #include<iostream>
 #include<vector>

using namespace std;
vector<int> h;
int find_max(int& a,int& b){
        if(a>b)
            return a;
        else
            return b;
    }
    
int find_min(int& a,int& b){
        if(a<b)
            return a;
        else
            return b;
    }
    
int maxArea(vector<int>& height) {
    int max_area=0;
    int left=0,right=height.size()-1;
    while(left<right){
        int hright = height[right];
        int hleft = height[left];
        int h = find_min(hright,hleft);
        int tmp_area = (right-left)*h;
        max_area = find_max(max_area,tmp_area);
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return max_area;
}

int main(){
    h={1,3,2,4};
    int area = maxArea(h);
    cout<<area;
}