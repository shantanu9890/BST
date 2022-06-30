
class BST
{

    binaryTreeNode<int> *root;

    bool hasDataHelper(binaryTreeNode<int> *root, int key)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == key)
        {
            return true;
        }
        if (root->data > key)
        {
            return hasDataHelper(root->left, key);
        }
        return hasDataHelper(root->right, key);
    }

    binaryTreeNode<int> *insertHelper(binaryTreeNode<int> *root, int key)
    {
        if (root == nullptr)
        {
            binaryTreeNode<int> *node = new binaryTreeNode<int>(key);
            return node;
        }
        if (key < root->data)
        {
            root->left = insertHelper(root->left, key);
            return root;
        }
        root->right = insertHelper(root->right, key);
        return root;
    }

    binaryTreeNode<int> *deleteHelper(binaryTreeNode<int> *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        else if (root->data < key)
        {
            root->right = deleteHelper(root->right, key);
            return root;
        }
        else if (root->data > key)
        {
            root->left = deleteHelper(root->left, key);
            return root;
        }
        else if (root->right == nullptr && root->left == nullptr)
        {
            return nullptr;
        }
        else if (root->right == nullptr)
        {
            binaryTreeNode<int> *temp = root->left;
            root->left = nullptr;
            delete root;
            return temp;
        }
        else if (root->left == nullptr)
        {
            binaryTreeNode<int> *temp = root->right;
            root->right == nullptr;
            delete root;
            return temp;
        }
        else
        {
            binaryTreeNode<int> *minNode = root->right;
            while (minNode->left != nullptr)
            {
                minNode = minNode->left;
            }
            root->data = minNode->data;
            root->right = deleteHelper(root->right, minNode->data);

            return root;
        }
    }

    void printTreehelp(binaryTreeNode<int>*root)
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


public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
    }
    void insert(int data)
    {
        root = insertHelper(root, data);
    }
    void deleteData(int data)
    {
        root = deleteHelper(root, data);
    }
    bool hasData(int data)
    {
        return hasDataHelper(root, data);
    }
    void printBST(){
        printTreehelp(root);
    }

};