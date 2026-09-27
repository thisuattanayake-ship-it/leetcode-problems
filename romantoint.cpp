#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int romToInt(string s){
        unordered_map<char,int> romanVal{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int tot=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int val=romanVal.at(s[i]);
            if(i+1<n&&val<romanVal.at(s[i+1])){
                tot-=val;
            } 
            else{
                tot+=val;
            }      
        }
        return tot;
    }
};

int main(){
    Solution sol;
    string input;
    cout<<"Enter the roman value: ";
    if(getline(cin,input)){
        cout<<"The value is: "<<sol.romToInt(input);
    }
}