#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

binaryTreeNode<int> *node_search(binaryTreeNode<int> *root, int s)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == s)
    {
        return root;
    }

    if (root->data < s)
    {
        return node_search(root->right, s);
    }

    return node_search(root->left, s);
}

//ul:upper limit; ll:lower limit
void printElementsInRange(binaryTreeNode<int> *root, int ll, int ul)
{

    if (root == nullptr)
    {
        return;
    }

    if (root->data >= ll && root->data <= ul)
    {
        cout << root->data << " ";
    }
    if (root->data < ll)
    {
        printElementsInRange(root->right, ll, ul);
    }
    if (root->data > ul)
    {
        printElementsInRange(root->left, ll, ul);
    }
}

int minimum(binaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(binaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(binaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool b = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);

    return b;
}

class isBST2return{ 
    public:
    int max;
    int min;
    bool isBST;
};

isBST2return isBST2help(binaryTreeNode<int>*root){
    isBST2return output;
    if(root==nullptr){
               output.max=INT_MIN;
               output.min=INT_MAX;
               output.isBST=true; 
               return output;
    }
    isBST2return left=isBST2help(root->left);
    isBST2return right=isBST2help(root->right);
    output.max=max(root->data,max(left.max,right.max));
    output.min=min(root->data,min(left.min,right.min));
    output.isBST= (root->data>left.max)&&(root->data<=right.min)&&left.isBST&&right.isBST;
    return output;
}

bool isBST2(binaryTreeNode<int>*root){
    return isBST2help(root).isBST;
}

bool BST3helper(binaryTreeNode<int>*root,int l,int r){
       if(root==nullptr){
        return true;
       }
       if(root->data<l || root->data>r){
        return false;
       }
       return BST3helper(root->left,l,root->data-1)&&BST3helper(root->right,root->data,r);
}

bool isBST3(binaryTreeNode<int>*root){
    return BST3helper(root,INT_MIN,INT_MAX);
}


binaryTreeNode<int>* bstFromSortedArray(int a[], int si, int ei)
{
    if (ei > si)
    {
        return nullptr;
    }
    int rootIndex = (ei - si) / 2;
    int rootData = a[rootIndex];
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    root->left = bstFromSortedArray(a, si, rootIndex - 1);
    root->right = bstFromSortedArray(a, rootIndex + 1, ei);
    return root;
}

class Node
{
    public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void Printll(Node *head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    Printll(head->next);
}

class Node1
{
public:
    Node *h;
    Node *t;
};

Node1 llFromBST(binaryTreeNode<int> *root)
{
    Node1 n;
    if (root == nullptr)
    {
        n.h = nullptr;
        n.t = nullptr;
        return n;
    }
    Node *r = new Node(root->data);
    Node1 l1 = llFromBST(root->left);
    Node1 r1 = llFromBST(root->right);
    if (l1.h == nullptr)
    {
        n.h=r;
        n.t=r;
        return n;
    }
    l1.t->next = r;
    r->next = r1.h;
    n.h=l1.h;
    n.t=r1.t;
    return n;
}

vector<int>* getNodeToRootPath(binaryTreeNode<int> *root,int key){
      if(root==nullptr){
        return nullptr;
      }
      if (root->data==key){
        vector<int>*v=new vector<int>();
        v->push_back(key);
        return v;
      }
      vector<int>*leftv=getNodeToRootPath(root->left,key);
      if (leftv!=nullptr)
      {
        leftv->push_back(root->data);
        return leftv;
      }
      vector<int>*rightv=getNodeToRootPath(root->right,key);
      if (rightv!=nullptr)
      {
        rightv->push_back(root->data);
        return rightv;
      }
      return nullptr;
}