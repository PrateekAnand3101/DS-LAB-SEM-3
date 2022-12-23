// /* C++ program to construct tree using
// inorder and preorder traversals */
// #include <bits/stdc++.h>
// using namespace std;

// /* A binary tree node has data, pointer to left child
// and a pointer to right child */
// class node
// {
// 	public:
// 	char data;
// 	node* left;
// 	node* right;
// };

// /* Prototypes for utility functions */
// int search(char arr[], int strt, int end, char value);
// node* newNode(char data);

// /* Recursive function to construct binary
// of size len from Inorder traversal in[]
// and Preorder traversal pre[]. Initial values
// of inStrt and inEnd should be 0 and len -1.
// The function doesn't do any error checking
// for cases where inorder and preorder do not
// form a tree */
// node* buildTree(char in[], char pre[], int inStrt, int inEnd)
// {
// 	static int preIndex = 0;

// 	if (inStrt > inEnd)
// 		return NULL;

// 	/* Pick current node from Preorder
// 	traversal using preIndex
// 	and increment preIndex */
// 	node* tNode = newNode(pre[preIndex++]);

// 	/* If this node has no children then return */
// 	if (inStrt == inEnd)
// 		return tNode;

// 	/* Else find the index of this node in Inorder traversal */
// 	int inIndex = search(in, inStrt, inEnd, tNode->data);

// 	/* Using index in Inorder traversal, construct left and
// 	right subtress */
// 	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
// 	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

// 	return tNode;
// }

// /* UTILITY FUNCTIONS */
// /* Function to find index of value in arr[start...end]
// The function assumes that value is present in in[] */
// int search(char arr[], int strt, int end, char value)
// {
// 	int i;
// 	for (i = strt; i <= end; i++)
// 	{
// 		if (arr[i] == value)
// 			return i;
// 	}
// }

// /* Helper function that allocates a new node with the
// given data and NULL left and right pointers. */
// node* newNode(char data)
// {
// 	node* Node = new node();
// 	Node->data = data;
// 	Node->left = NULL;
// 	Node->right = NULL;

// 	return (Node);
// }

// /* This function is here just to test buildTree() */
// void printInorder(node* node)
// {
// 	if (node == NULL)
// 		return;

// 	/* first recur on left child */
// 	printInorder(node->left);

// 	/* then print the data of node */
// 	cout<<node->data<<" ";

// 	/* now recur on right child */
// 	printInorder(node->right);
// }

// /* Driver code */
// int main()
// {
// 	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
// 	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
// 	int len = sizeof(in) / sizeof(in[0]);
// 	node* root = buildTree(in, pre, 0, len - 1);

// 	/* Let us test the built tree by
// 	printing Inorder traversal */
// 	cout << "Inorder traversal of the constructed tree is \n";
// 	printInorder(root);
// }


#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
};

class stack
{
private:
    node *s[100];
    int top;
    int size;

public:

    stack(int size)
    {
        this->size = size;
        top = -1;
    }

    void push(node *x)
    {
        if (top == size - 1)
            cout << "Stack Overflow" << endl;
        else
            s[++top] = x;
    }

    node *pop()
    {
        node *x = NULL;
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
            x = s[top--];
        return x;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class tree
{
private:

    node *root;
    stack *stk;

public: 

    tree(int size)
    {
        root = NULL;
        stk = new stack(size);
    }

    void createTree(char *postfix)
    {
        node *t, *t1, *t2;
        int i = 0;

        while (postfix[i] != '\0')
        {
            if (isOperand(postfix[i]))
            {
                t = new node;
                t->data = postfix[i];
                t->left = t->right = NULL;
                // cout << t -> data << " ";
                stk->push(t);
            }
            else
            {
                t = new node;
                t->data = postfix[i];
                // cout << t -> data << " ";
                t2 = stk->pop();
                t1 = stk->pop();
                t->right = t2;
                t->left = t1;
                stk->push(t);
            }
            i++;
        }
        root = stk->pop();
    }

    void preorder(node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void inorder(node *p)
    {
        if (p)
        {
            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
        }
    }

    void postorder(node *p)
    {
        if (p)
        {
            postorder(p->left);
            postorder(p->right);
            cout << p->data << " ";
        }
    }

    void display()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }
};

int main()
{
    tree t(100);
    char postfix[] = "ABC*+D/";
    t.createTree(postfix);
    t.display();
    return 0;
}