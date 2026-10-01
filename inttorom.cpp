#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
    public:
        string intToRom(int num){
            vector<string> thousands={"","M","MM","MMM"};
            vector<string> hundreds={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
            vector<string> tens={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
            vector<string> ones={"","I","II","III","IV","V","VI","VII","VIII","IX"};
            string val="";
            string s=to_string(num);
            reverse(s.begin(),s.end());
            for(int i=0;i<s.size();i++){
                int vals=(s[i]-'0');
                if(i==0){
                    val=ones[vals]+val;
                }
                if(i==1){
                    val=tens[vals]+val;
                }
                if(i==2){
                    val=hundreds[vals]+val;
                }
                if(i==3){
                    val=thousands[vals]+val;
                }
            }
            return val;
        }
};

int main(){
    int input;
    cout<<"Enter the number: ";
    cin>>input;
    Solution sol;
    cout<<"The roman number is: "<<sol.intToRom(input);
}