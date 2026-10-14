#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
    public:
        bool isAnagram(string s,string t){
            int m=s.size();
            int n=t.size();
            if(m!=n)return false;
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            return s==t;
        }
};

int main(){
    string s;
    cout<<"Enter the first string:";
    cin>>s;
    string t;
    cout<<"Enter the second string:";
    cin>>t;
    Solution sol;
    cout<<sol.isAnagram(s,t);
}