#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int);
    void insert(int);
    void preorder();
    void postorder();
    bool search(int);
    int get_max();
    bool del_node(int, Node *);
    void level_order();
    int height();
    void inorder();
    int get_min();
    void leaf_node();
    void internal_node();
};

Node ::Node(int val)
{
    this->value = val;
    this->left = NULL;
    this->right = NULL;
}
int Node ::height()
{
    if (this == NULL)
        return 0;
    int L = this->left->height();
    int R = this->right->height();
    if (L > R)
        return 1 + this->left->height();
    else
        return 1 + this->right->height();
}
void Node ::level_order()
{
    queue<Node *> Q;
    Q.push(this);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        cout << temp->value << " ";
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
}
bool Node ::del_node(int val, Node *p)
{
    if (val > this->value)
    {
        if (this->right)
            return this->right->del_node(val, this);
        else
            return false;
    }
    else if (val < this->value)
    {
        if (this->left)
            return this->left->del_node(val, this);
        else
            return false;
    }
    else
    {
        if (this->left == NULL && this->right == NULL)
        {
            if (this == p->left)
                p->left = NULL;
            else
                p->right = NULL;
        }
        else if (this->left == NULL && this->right)
        {
            if (this == p->left)
                p->left = this->right;
            else
                p->right = this->right;
        }
        else if (this->left && this->right == NULL)
        {
            if (this == p->left)
                p->left = this->left;
            else
                p->right = this->left;
        }
        else
        {
            this->value = this->left->get_max();
            return this->left->del_node(this->value, this);
        }
    }
    delete this;
    return true;
}
int Node ::get_max()
{
    if (this->right)
        return this->right->get_max();
    return this->value;
}
void Node ::postorder()
{
    if (this->left)
        this->left->postorder();
    if (this->right)
        this->right->postorder();
    cout << this->value << " ";
}
void Node ::inorder()
{
    if (this->left)
        this->left->inorder();
    cout << this->value << " ";
    if (this->right)
        this->right->inorder();
}

void Node ::preorder()
{
    cout << this->value << " ";
    if (this->left)
        this->left->preorder();
    if (this->right)
        this->right->preorder();
}
void Node ::insert(int val)
{
    if (val > this->value)
    {
        if (this->right)
            return this->right->insert(val);
        else
            this->right = new Node(val);
    }
    else if (val < this->value)
    {
        if (this->left)
            return this->left->insert(val);
        else
            this->left = new Node(val);
    }
    else
        cout << val << " already exists in a Tree\n";
}
bool Node ::search(int val)
{
    if (val > this->value)
    {
        if (this->right)
            return this->right->search(val);
        else
            return false;
    }
    else if (val < this->value)
    {
        if (this->left)
            return this->left->search(val);
        else
            return false;
    }
    else
        return true;
}

int Node::get_min()
{
    if (this->left)
        return this->left->get_min();
    return this->value;
}
void Node ::leaf_node()
{
    if (this->right == NULL && this->left == NULL)
    {
        cout << value << " ";
        return;
    }

    if (this->left)
        this->left->leaf_node();
    if (this->right)
        this->right->leaf_node();
}
void Node::internal_node()
{
    if (this->left || this->right)
        cout << this->value << " ";

    if (this->left)
        this->left->internal_node();
    if (this->right)
        this->right->internal_node();
}

int main()
{
    int A[] = {72, 26, 82, 3, 46, 80, 1, 99, 44, 28, 46, 55, 79, 39, 77, 32, 72, 1};
    int n = sizeof(A) / sizeof(int);
    Node *Tree = new Node(*A);
    int searched, deleted;

    for (int i = 1; i < n; i++)
        Tree->insert(A[i]);
    cout << "Preorder traversals:\n";
    Tree->preorder();
    cout << endl;
    cout << "Postorder traversals:\n";
    Tree->postorder();
    cout << endl;
    cout << "Enter searched value :";
    cin >> searched;
    if (Tree->search(searched))
        cout << searched << " exists in a tree\n";
    else
        cout << searched << " does not exist in a tree\n";
    cout << "Maximum of tree is : " << Tree->get_max() << endl;

    cout << "Level order :\n";
    Tree->level_order();
    cout << endl;

    cout << "Enter deleted value :";
    cin >> deleted;
    if (Tree->del_node(deleted, NULL))
    {
        cout << deleted << " deleted from a tree\n";
        Tree->preorder();
        cout << endl;
    }
    else
        cout << deleted << " doesn't exist in a tree\n";
    cout << "Height of tree is : " << Tree->height() - 1 << endl;
    return 0;
}
