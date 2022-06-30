
#include <queue>
using namespace std;
template <typename T>

class binaryTreeNode
{

public:
  T data;
  binaryTreeNode<T> *right, *left;
  binaryTreeNode(T data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
  ~binaryTreeNode()
  {
    delete left;
    delete right;
  }
};

binaryTreeNode<int> *takeInputLevelWise()
{
  cout << "Enter data" << endl;
  int rootdata;
  cin >> rootdata;
  binaryTreeNode<int> *root = new binaryTreeNode<int>(rootdata);
  queue<binaryTreeNode<int> *> q;
  q.push(root);
  while (!q.empty())
  {
    binaryTreeNode<int> *front = q.front();
    q.pop();
    cout << "Enter left node data of: " << front->data << " :" << endl;
    int leftdata;
    cin >> leftdata;
    if (leftdata != -1)
    {
      binaryTreeNode<int> *left = new binaryTreeNode<int>(leftdata);
      front->left = left;
      q.push(left);
    }
    cout << "Enter right node data of: " << front->data << " :" << endl;
    int rightdata;
    cin >> rightdata;
    if (rightdata != -1)
    {
      binaryTreeNode<int> *right = new binaryTreeNode<int>(rightdata);
      front->right = right;
      q.push(right);
    }
  }
  return root;
}

void printTree(binaryTreeNode<int> *root)
{

  if (root == nullptr)
  {
    return;
  }

  queue<binaryTreeNode<int> *> q;
  q.push(root);
  while (!q.empty())
  {

    binaryTreeNode<int> *front = q.front();
    cout << front->data << " : ";
    q.pop();

    if (front->left != nullptr)
    {
      cout << "L" << front->left->data << " ";
      q.push(front->left);
    }
    if (front->right != nullptr)
    {
      cout << "R" << front->right->data << " ";
      q.push(front->right);
    }
    cout << endl;
  }
}

int totalNodes(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  return totalNodes(root->left) + totalNodes(root->right) + 1;
}

void inorder(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

binaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
  if (inE < inS)
  {
    return nullptr;
  }
  int rootData = pre[preS];

  int rootIndex = -1;
  for (int i = inS; i <= inE; i++)
  {
    if (in[i] == rootData)
    {
      rootIndex = i;
      break;
    }
  }
  int inLS = inS;
  int inLE = rootIndex - 1;
  int inRS = rootIndex + 1;
  int inRE = inE;
  int preLS = preS + 1;
  int preLE = inLE - inLS + preLS;
  int preRS = preLE + 1;
  int preRE = preE;

  binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
  root->left = buildTreeHelper(in, pre, inLS, inLE, preLS, preLE);
  root->right = buildTreeHelper(in, pre, inRS, inRE, preRS, preRE);

  return root;
}

int height(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  
  return max(height(root->left), height(root->right)) + 1;
}

int diameter(binaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr)
  {
    return 1;
  }
  return max(max(diameter(root->left),diameter(root->right)),height(root->left)+height(root->right));
}
//better way:

pair<int,int> diameter_height(binaryTreeNode<int>*root){
  
  pair<int,int>p;

  if(root==nullptr){
  
    p.first=0;
    p.second=0;
    return p;
  }

  pair<int,int>l=diameter_height(root->left);
  pair<int,int>r=diameter_height(root->right);

  int lh=l.first;
  int ld=l.second;
  int rh=r.first;
  int rd=r.second;
  
  p.first=max(lh,rh)+1;
  p.second=max(lh+rh,max(ld,rd));
  return p;

}