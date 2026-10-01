#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution{
    public:
        void traverse(TreeNode* root,vector<int>& order){
            if(!root)return;
            order.push_back(root->val);
            traverse(root->left,order);
            traverse(root->right,order);
        }
        vector<int> preOrder(TreeNode* root){
            if(root==nullptr)return {};
            vector<int> results;
            traverse(root,results);
            return results;
        }
};

TreeNode* buildTree(const string& input){
    if(input.empty()||input=="[]"||input=="null")return nullptr;
    string clean=input;
    if(clean.front()=='[')clean.erase(0,1);
    if(!clean.empty()&&clean.back()==']')clean.pop_back();
    stringstream ss(clean);
    string item;
    vector<string> tokens;
    while(getline(ss,item,',')){
        size_t start=item.find_first_not_of(" \t\n\r");
        size_t end=item.find_last_not_of(" \t\r\n");
        if(start!=string::npos&&end!=string::npos){
            tokens.push_back(item.substr(start,end-start+1));
        }
    }
    if(tokens.empty()||tokens[0]=="null")return nullptr;
    TreeNode* root=new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i=1;
    while(i<tokens.size()&!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(i<tokens.size()){
            if(tokens[i]!="null"){
                curr->left=new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }
        if(i<tokens.size()){
            if(tokens[i]!="null"){
                curr->right=new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

void freeTree(TreeNode *root){
    if(!root)return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main(){
    string input;
    cout<<"Enter the tree:";
    getline(cin,input);
    TreeNode* root=buildTree(input);
    Solution sol;
    vector<int> results=sol.preOrder(root);
    cout<<"Preorder Traversal: "<<'[';
    for(size_t i=0;i<results.size();i++){
        cout<<results[i]<<(i<results.size() - 1 ? "," : "");
    }
    cout<<']';
}