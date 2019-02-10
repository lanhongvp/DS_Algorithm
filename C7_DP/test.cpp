#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
   int n;
   cin>>n;
   
   double res = fmod(log(n),log(3));
   cout<<res;
   
}