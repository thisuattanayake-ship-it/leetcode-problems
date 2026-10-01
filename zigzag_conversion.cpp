#include <iostream>
#include <vector> 
#include <string>


using namespace std;

class Solution{
    public:
        string converter(string s,int numRows){
            int m=0;
            int n=numRows-1;
            vector<string> rows(numRows);
            string converted="";
            int count=0;
            for(int i=0;i<s.size();i++){
                rows[m].push_back(s[i]);
                if(m==0){
                    count+=1;
                    m++;
                }
                else if(m==n){
                    count-=1;
                    m--;
                }
                else{
                    if(count==1){
                        m++;
                    }
                    else if(count==0){
                        m--;
                    }  
                }
            }
            for(int i=0;i<rows.size();i++){
                converted+=rows[i];
            }
        return converted;
    }
};

int main(){
    string input;
    cout<<"Enter your string: ";
    cin>>input;
    int nums;
    cout<<"Enter the number of rows: ";
    cin>>nums;
    Solution sol;
    cout<<"The zigzag pattern is: "<<sol.converter(input,nums);
    return 0;
}