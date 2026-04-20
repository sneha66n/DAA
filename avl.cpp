#include <iostream>
using namespace std;

class avl_node
{
public:
    string value;
    avl_node* left;
    avl_node* right;

    friend class avlTree;
};

class avlTree
{
public:
    avl_node* root;

    int height(avl_node*);
    int diff(avl_node*);
    avl_node* rr_rotation(avl_node*);
    avl_node* ll_rotation(avl_node*);
    avl_node* lr_rotation(avl_node*);
    avl_node* rl_rotation(avl_node*);
    avl_node* balance(avl_node*);

    void insert();
    avl_node* insert(avl_node*, avl_node*);

    void display(avl_node*, int);
    void inorder(avl_node*);
    void preorder(avl_node*);
    void postorder(avl_node*);

    avlTree()
    {
        root = NULL;
    }
};

int avlTree::height(avl_node* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);

        int max_height;
        if (l_height > r_height)
            max_height = l_height;
        else
            max_height = r_height;

        h = max_height + 1;
    }
    return h;
}

int avlTree::diff(avl_node* temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    return (l_height - r_height);
}

avl_node* avlTree::balance(avl_node* temp)
{
    int bal_factor = diff(temp);

    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

void avlTree::insert()
{
    int ch;
    do
    {
        avl_node* temp = new avl_node;
        cout << "Enter a string: ";
        cin >> temp->value;
        temp->left = temp->right = NULL;

        root = insert(root, temp);

        cout << "Enter 1 to continue, 0 to stop: ";
        cin >> ch;
    } while (ch == 1);
}

avl_node* avlTree::insert(avl_node* root, avl_node* temp)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->value = temp->value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (temp->value < root->value)   // string compare
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

void avlTree::display(avl_node* ptr, int level)
{
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout << "\n";

        if (ptr == root)
            cout << "root-> ";

        for (int i = 0; i < level && ptr != root; i++)
            cout << "  ";

        cout << ptr->value;

        display(ptr->left, level + 1);
    }
}

// LL
avl_node* avlTree::ll_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// RR
avl_node* avlTree::rr_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// LR
avl_node* avlTree::lr_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// RL
avl_node* avlTree::rl_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

void avlTree::inorder(avl_node* temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->value << " ";
        inorder(temp->right);
    }
}

void avlTree::preorder(avl_node* temp)
{
    if (temp != NULL)
    {
        cout << temp->value << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void avlTree::postorder(avl_node* temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->value << " ";
    }
}

int main()
{
    avlTree t;
    int choice;

    do
    {
        cout << "\n--- AVL TREE MENU (STRING) ---\n";
        cout << "1. Insert\n";
        cout << "2. Display Tree\n";
        cout << "3. Inorder\n";
        cout << "4. Preorder\n";
        cout << "5. Postorder\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.insert();
            break;

        case 2:
            cout << "\nTree Structure:\n";
            t.display(t.root, 1);
            break;

        case 3:
            cout << "Inorder: ";
            t.inorder(t.root);
            break;

        case 4:
            cout << "Preorder: ";
            t.preorder(t.root);
            break;

        case 5:
            cout << "Postorder: ";
            t.postorder(t.root);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}