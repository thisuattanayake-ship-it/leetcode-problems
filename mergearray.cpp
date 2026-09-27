#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    public:
        void merge(vector<int>& nums1,vector<int>& nums2,int m,int n){
            vector<int> mergedList(m+n);
            std::merge(nums1.begin(),nums1.begin()+m,nums2.begin(),nums2.begin()+n,mergedList.begin());
            nums1=mergedList;
        }
};

int main(){
    int m;
    cout<<"Enter number of elements for list1: ";
    cin>>m;
    vector<int> nums1(m);
    cout<<"Enter "<<m<<" numbers separated by spaces: ";
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    int n;
    cout<<"Enter number of elements for list2: ";
    cin>>n;
    vector<int> nums2(n);
    cout<<"Enter "<<n<<" numbers separated by spaces: ";
    for(int j=0;j<n;j++){
        cin>>nums2[j];
    }
    Solution sol;
    sol.merge(nums1,nums2,m,n);
    cout<<"The merged list is: ";
    for(int val:nums1){
        cout<<val<<" ";
    }
    cout<<'\n';
    return 0;
}