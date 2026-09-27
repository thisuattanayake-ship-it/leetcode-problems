#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        string addBinary(string a,string b){
            string result="";
            int i=a.length()-1;
            int j=b.length()-1;
            int carry=0;
            while(i>=0||j>=0||carry){
                int sum=carry;
                if(i>=0){
                    sum+=a[i--]-'0';
                }
                if(j>=0){
                    sum+=b[j--]-'0';
                }
                result+=(sum%2)+'0';
                carry=sum/2;
            }
            reverse(result.begin(),result.end());
            return result;
        }
};

int main(){
    string a;
    cout<<"Enter the 1st binary value: ";
    cin>>a;
    string b;
    cout<<"Enter the 2nd binary value: ";
    cin>>b;
    Solution sol;
    cout<<"The addition value is: "<<sol.addBinary(a,b);
}