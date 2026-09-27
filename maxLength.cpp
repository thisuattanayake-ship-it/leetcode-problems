#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            vector<int> lastSeen(256,-1);
            int maxLength=0;
            int left=0;
            for(int right=0;right<s.size();right++){
                char currentChar=s[right];
                if (lastSeen[currentChar]>=left){
                    left=lastSeen[currentChar]+1;
                }
                lastSeen[currentChar]=right;
                maxLength=max(maxLength,right-left+1);
            }
            return maxLength;
        }
};

int main(){
    Solution solver;
    string test1="abcabcbb";
    string test2="bbbb";
    string test3="pwwkew";
    cout<<"Test 1: "<<solver.lengthOfLongestSubstring(test1)<<'\n';
    cout<<"Test 2: "<<solver.lengthOfLongestSubstring(test2)<<'\n';
    cout<<"Test 3: "<<solver.lengthOfLongestSubstring(test3)<<'\n';
    return 0;
}