#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
    public:
        int lengthOfLastWord(string s){
            stringstream ss(s);
            string word,last_word;
            while(ss>>word){
                last_word=word;
            }
            return last_word.size();
        }
};

int main(){
    Solution myText;
    string input;
    cout<<"Enter a string: ";
    if(getline(cin,input)){
        cout<<"Length of last word: "<<myText.lengthOfLastWord(input)<<'\n';
    }
    return 0;
}
