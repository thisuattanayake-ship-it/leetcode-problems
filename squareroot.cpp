#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        int sqrt(int x){
            if(x<2)return x;
            int left=1;
            int right=x/2;
            int ans=0;
            while(right>=left){
                long long mid=left+(right-left)/2;
                long long sq=mid*mid;
                if(sq==x){
                    return mid;
                }
                else if(sq<x){
                    ans=mid;
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            return ans;
        }
};

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    Solution sol;
    cout<<"The squareroot is: "<<sol.sqrt(num);
}