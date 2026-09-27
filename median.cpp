#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            nums1.insert(nums1.end(),nums2.begin(),nums2.end());
            sort(nums1.begin(),nums1.end());
            int total=nums1.size();
            if(total==0)return 0.0;
            if(total%2!=0){
                return nums1[total/2];
            }
            else{
                return (nums1[(total/2)-1]+nums1[total/2])/2.0;
            }
        }
};

vector<int> parseInput(const string& input){
    vector<int> result;
    stringstream ss(input);
    char ch;
    int num;
    while(ss>>ch){
        if(isdigit(ch)||ch=='-'){
            ss.putback(ch);
            if(ss>>num){
                result.push_back(num);
            }
        }
    }
    return result;
}

string formatOutput(double val){
    ostringstream out;
    out<<fixed<<setprecision(5)<<val;
    return out.str();
}

int main(){
    string line1,line2;
    Solution solver;
    while(getline(cin,line1)&&getline(cin,line2)){
        vector<int> nums1=parseInput(line1);
        vector<int> nums2=parseInput(line2);
        double result=solver.findMedianSortedArrays(nums1,nums2);
        cout<<formatOutput(result)<<'\n';
    }
    return 0;
}