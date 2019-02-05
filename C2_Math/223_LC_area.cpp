#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)     {
        int area_1 = abs(C-A)*abs(D-B);
        int area_2 = abs(G-E)*abs(H-F);
        if(D<=E||B>=H)
            return area_1+area_2;
        vector<int> w;
        vector<int> h;
        w = {A,C,E,G};
        h = {B,D,F,H};
        sort(w.begin(),w.end());        
        sort(h.begin(),h.end());
        int width_ov = w[2]-w[1];
        int height_ov = h[2]-h[1];
        int over_area = width_ov*height_ov;
        int area = area_1+area_2-over_area;
        return area;
    }
};

int main(){
    int num;
    int a=-3, b=0, c=3, d=4, e=0, f=-1, g=9, h=2;
    int area = Solution().computeArea(a,b,c,d,e,f,g,h);
    cout<<area;
}