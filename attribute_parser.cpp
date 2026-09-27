#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    vector<string> currentpath;
    vector<pair<string,string>> HRML_attributes;
    int n;int q;
    cin>>n>>q;
    cin.ignore();
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        if (line.substr(0,2)=="</"){
            currentpath.pop_back();
        }
        else{
            stringstream ss(line);
            string token;
            ss>>token;
            if(token.front()=='<')token=token.substr(1);
            if(!token.empty()&&token.back()=='>')token.pop_back();
            currentpath.push_back(token);
            string full_prefix="";
            for(size_t k=0;k<currentpath.size();k++){
                if(k>0)full_prefix+=".";
                full_prefix+=currentpath[k];
            }
            string attr,eq,val;
            while(ss>>attr>>eq>>val){
                if (val.front()=='"'){
                    val=val.substr(1);
                }
                while(!val.empty()&&val.back()=='>'||val.back()=='"'){
                    val.pop_back();
                }
                string key=full_prefix+"~"+attr;
                HRML_attributes.push_back({key,val});
            }
        }
        for(int j=0;j<q;j++){
            string query;
            getline(cin,query);
            bool found=false;
            for(size_t k=0;k<HRML_attributes.size();k++){
                if(HRML_attributes[k].first==query){
                    cout<<HRML_attributes[k].second<<'\n';
                    found=true;
                    break;
                }
            }
            if (!found){
                cout<<"Not Found!\n";
            }
        }
    
    }
    return 0;
}