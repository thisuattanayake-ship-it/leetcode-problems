#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

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
        int minDepth(TreeNode *root){
            if(root==nullptr)return 0;
            if(root->left==nullptr&&root->right==nullptr)return 1;
            if(root->left==nullptr)return 1+minDepth(root->right);
            if(root->right==nullptr)return 1+minDepth(root->left);
            return 1+min(minDepth(root->right),minDepth(root->left));
        }
};

TreeNode* buildTree(const string& input){
    if(input.empty()||input=="null"||input=="[]")return nullptr;
    string clean=input;
    if(clean.front()=='[')clean.erase(0,1);
    if(!clean.empty()&&clean.back()==']')clean.pop_back();
    stringstream ss(clean);
    string item;
    vector<string> tokens;
    while(getline(ss,item,',')){
        size_t start=item.find_first_not_of(" \t\r\n");
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
    while(!q.empty()&&i<tokens.size()){
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

void freeTree(TreeNode* root){
    if(!root)return;
    freeTree(root->right);
    freeTree(root->left);
    delete root;
}


int main(){
    string input;
    cout<<"Enter the tree:";
    getline(cin,input);
    TreeNode* root=buildTree(input);
    Solution sol;
    int depth=sol.minDepth(root);
    cout<<"Minimum depth is: "<<depth;
    freeTree(root);
    return 0;
}








