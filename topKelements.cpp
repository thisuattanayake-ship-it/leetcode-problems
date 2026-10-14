#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
       vector<int> topKFrequent(vector<int>& nums,int k){
            int n=nums.size();
            unordered_map<int,int> frequencies;
            for(int i=0;i<n;i++){
                frequencies[nums[i]]++;
            }
            vector<vector<int>> nums_frq(nums.size() + 1);
            for (auto const& pair:frequencies) {
                int num = pair.first;
                int frequency = pair.second;
                nums_frq[frequency].push_back(num);
            }
            vector<int> res;
            for (int i = nums_frq.size() - 1; i > 0; --i) {
                for (int num : nums_frq[i]) {
                    res.push_back(num); 
                    if (res.size() == k) {
                        return res;
                    }
                }
            }
            return res;
        }
};

int main(){
    vector<int> nums={1,1,2,2,2,3,4,5,5,5,5};
    int k=2;
    Solution sol;
    vector<int> values=sol.topKFrequent(nums,k);
    for(int i=0;i<values.size();i++){
        cout<<values[i]<<" ";
    }
}