#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution{
    public:
        void traverse(TreeNode* root,vector<int>& order){
            if(!root)return;
            traverse(root->left,order);
            traverse(root->right,order);
            order.push_back(root->val);
        }
        vector<int> postorder(TreeNode* root){
            if(root==nullptr)return {};
            vector<int> result;
            traverse(root,result);
            return result;
        }
};

TreeNode* buildTree(const string& input){
    if(input.empty()||input=="null"||input=="[]")return nullptr;
    string clean=input;
    if(clean.front()=='[')clean.erase(0,1);
    if(clean.back()==']'&&!clean.empty())clean.pop_back();
    stringstream ss(clean);
    string item;
    vector<string> tokens;
    while(getline(ss,item,',')){
        int start=item.find_first_not_of(" \t\r\n");
        int end=item.find_last_not_of(" \t\r\n");
        if(start!=string::npos&&end!=string::npos){
            tokens.push_back(item.substr(start,end-start+1));
        }
    }
    if(tokens.empty()||tokens[0]=="null")return nullptr;
    TreeNode *root=new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    while(!q.empty()&&i<i<tokens.size()){
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
    delete(root);
}

int main(){
    string input;
    cout<<"Enter the tree: ";
    getline(cin,input);
    TreeNode *root=buildTree(input);
    Solution sol;
    vector<int> result=sol.postorder(root);
    cout<<"Postorder Traversal: [";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<(i<result.size()-1?",":"");
    }
    cout<<']';
    freeTree(root);
}