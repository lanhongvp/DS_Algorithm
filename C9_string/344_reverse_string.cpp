#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0;
        if(n==0 || n=a=1) return;
        while(i<=(n/2-1)){
            swap(s[i],s[n-1-i]);
            i++;
        }
    }
};

int main(){
    vector<char> s = {'h','e','l','l','o'};
    vector<char> s1 = {'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a'};
    int n = s1.size();
    cout<<"size "<<n<<endl;
    Solution().reverseString(s1);
    for(int i = 0;i < n;i++)
        cout<<s1[i]<<" ";
}