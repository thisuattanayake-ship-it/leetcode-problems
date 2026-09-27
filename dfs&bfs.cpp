#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

bool searchDFS(TreeNode* root,int target,vector<int>& visitOrder){
    if(root==nullptr)return false;
    visitOrder.push_back(root->val);
    if(root->val==target)return true;
    if(searchDFS(root->left,target,visitOrder))return true;
    return searchDFS(root->right,target,visitOrder);
}

bool searchBFS(TreeNode* root,int target,vector<int>& visitOrder){
    if (root==nullptr) return false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        visitOrder.push_back(curr->val);

        if(curr->val==target) return true;
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr) q.push(curr->right);
    }
    return false;
}

int main(){
    TreeNode* root=new TreeNode(1,new TreeNode(2,new TreeNode(4,new TreeNode(8),new TreeNode(9)),new TreeNode(5,new TreeNode(10),new TreeNode(11))),new TreeNode(3,new TreeNode(6,new TreeNode(12),new TreeNode(13)),new TreeNode(7,new TreeNode(14),new TreeNode(15))));
    int target=14;
    vector<int> dfsOrder;
    searchDFS(root,target,dfsOrder);
    vector<int> bfsOrder;
    searchBFS(root,target,bfsOrder);
    cout<<"Target node to find: "<<target<<'\n';
    cout<<"DFS Visit Order: ";
    for(size_t i=0;i<dfsOrder.size();i++){
        cout<<dfsOrder[i]<<(i+1<dfsOrder.size()?"->":"");
    }
    cout<<"(Visited "<<dfsOrder.size()<<" nodes)\n";
    cout<<"BFS Visit Order: ";
    for(size_t i=0;i<bfsOrder.size();i++){
        cout<<bfsOrder[i]<<(i+1<bfsOrder.size()?"->":"");
    }
    cout<<"(Visited "<<bfsOrder.size()<<" nodes)\n";
    return 0;
}