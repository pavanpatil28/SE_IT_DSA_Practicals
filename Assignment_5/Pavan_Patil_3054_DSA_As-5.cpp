#include <iostream>
using namespace std;

class Node
{
	public:
		int No;
		Node *left;
		Node *right;
		
		Node()
    	{
        	No = 0;
        	left = NULL;
        	right = NULL;
     	}
};

class Binary_Search_Tree
{
	string postfix, prefix;
			
	public:
        Node *root;

		Binary_Search_Tree()
		{
			root = NULL;
		}		

		void Create_Binary_Search_Tree(Node *root, int x);
		void Inorder_Recursive(Node *root);
		void Preorder_Recursive(Node *root);
		void Postorder_Recursive(Node *root);
        Node *Recursive_Search(Node *root, int x);
        Node *Min_Value_Node_1(Node *root);
        Node *Min_Value_Node_2(Node *root);
        int Height(Node *root);
        Node *Mirror_of_BST(Node *root);
        void Leaf(Node *root);
        Node *Delete_Node(Node *root, int x);
};
	
void Binary_Search_Tree :: Create_Binary_Search_Tree(Node *p, int x)
{	

	if (root == NULL)
    {
        root = p;
        cout << "\n --> Value "<<x<<" Inserted as Root Node " << endl;
    }
    else
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (p->No == temp->No)
            {
                cout << "\n --> Value "<<x<<" Already Exist, Please Insert Another Value " << endl;
                return;
            }
			
            else if ((p->No < temp->No) && (temp->left == NULL))
            {
                temp->left = p;
                cout << "\n --> Value "<<x<<" is Less than Corresponding Root Node , Inserted to the Left " << endl;
                break;
            }
			
            else if (p->No < temp->No)
            {
                temp = temp->left;
            }

            else if ((p->No > temp->No) && (temp->right == NULL))
            {
                temp->right = p;
                cout << "\n --> Value "<<x<<" is Greater than Corresponding Root Node, Inserted to the Right "<< endl;
                break;
            }
			
            else
            {
                temp = temp->right;
            }
        }
    }						
}	

void Binary_Search_Tree :: Preorder_Recursive(Node*p)
{
    if(p != NULL)
    {
    	cout<<p->No<<" ";
    	Preorder_Recursive(p->left);
    	Preorder_Recursive(p->right);
    }
}

void Binary_Search_Tree :: Inorder_Recursive(Node*p)
{
    if(p != NULL)
    {
    	Inorder_Recursive(p->left);
    	cout<<p->No<<" ";
    	Inorder_Recursive(p->right);
    }
}

void Binary_Search_Tree :: Postorder_Recursive(Node*p)
{
    if(p != NULL)
    {
    	Postorder_Recursive(p->left);
    	Postorder_Recursive(p->right);
    	cout<<p->No<<" ";
    }
}

Node *Binary_Search_Tree :: Recursive_Search(Node *p, int x)
{
    if (p == NULL || p->No == x)
    {
        return p;
    }

    else if (x < p->No)
    {
        return Recursive_Search(p->left, x);
    }

    else
    {
        return Recursive_Search(p->right, x);
    }
}

int Binary_Search_Tree :: Height(Node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return (1 + max(Height(p->left), Height(p->right)));
    }
}

Node *Binary_Search_Tree :: Min_Value_Node_1(Node *temp)
{
    Node *current = temp;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *Binary_Search_Tree :: Min_Value_Node_2(Node *temp)
{
    Node *current = temp;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    cout << current->No << endl;
    return NULL;
}

Node *Binary_Search_Tree :: Mirror_of_BST(Node *p)
{
    Node *temp = p;

    if (p != NULL)
    {
        temp = p->right;
        p->right = p->left;
        p->left = temp;
        Mirror_of_BST(p->left);
        Mirror_of_BST(p->right);
    }
    
    return NULL;
}

void Binary_Search_Tree :: Leaf(Node *root)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        cout << root->No << " ";
    }
    if (root == NULL)
    {
        return;
    }
    else
    {
        Leaf(root->left);
        Leaf(root->right);
    }
}

Node *Binary_Search_Tree :: Delete_Node(Node *p, int x)
{
    if (p == NULL)
    {
        return NULL;
    }

    else if (x < p->No)
    {
        p->left = Delete_Node(p->left, x);
    }
    else if (x > p->No)
    {
        p->right = Delete_Node(p->right, x);
    }
    else
    {
        // node with only one child or no child
        if (p->left == NULL)
        {
            Node *temp = p->right;
            delete p;
            return temp;
        }
        else if (p->right == NULL)
        {
            Node *temp = p->left;
            delete p;
            return temp;
        }
        else
        {
            Node *temp = Min_Value_Node_1(p->right);
            p->No = temp->No;
            p->right = Delete_Node(p->right, temp->No);
        }
    }
    return p;
}

int main()
{
    int choice,val;
    Binary_Search_Tree obj;

    cout<<"\n \t\t\t ============================ \n";
	cout<<" \t\t\t ||   BINARY SEARCH TREE   || \n";
	cout<<" \t\t\t ============================ \n\n";

    while(true)
    {    	
 		cout<<"\n=============================================================================================\n";
        cout<<" >>> Binary Search Tree Menu :- \n\n 1] Create Binary Search Tree \t\t 2] BST Traversal \n\n 3] Search Node \t\t\t 4] Delete Node \n\n 5] Height of BST \t\t\t 6] Smallest Node in BST \n\n 7] Display Mirror Image of BST \t 8] Display Leaf Nodes of BST \n\n 9] Exit Program  \n\n >> Enter your choice :: ";
        cin>>choice;
		cout<<"\n=============================================================================================\n";
        
        Node * p = new Node();
        switch(choice)
        {
            case 1:
		        cout<<"\n=============================================================================================\n";
            	cout<<" >>> Insert a Node :- \n"<<endl;
            	cout<<" >> Enter the Value to Insert in BST :: ";
            	cin>>val;
            	p->No = val;
                obj.Create_Binary_Search_Tree(p,val);
		        cout<<"\n=============================================================================================\n";
                break;
            case 2:
		        cout<<"\n=============================================================================================\n";
				cout<<" >>> Traversals of BST :- \n"<<endl;
	            cout<<" --> Preorder of BST   ::  ";
				obj.Preorder_Recursive(obj.root);
				cout<<endl;
				cout<<" --> Inorder of BST    ::  ";
				obj.Inorder_Recursive(obj.root);
				cout<<endl;
				cout<<" --> Postorder of BST  ::  ";
				obj.Postorder_Recursive(obj.root);
				cout<<endl;
		        cout<<"\n=============================================================================================\n";
                break;
            case 3:
		        cout<<"\n=============================================================================================\n";
                cout << " >>> Search Operation :- " << endl;
                cout << "\n >> Enter Value of Node to Search in BST :: ";
                cin >> val;
                p = obj.Recursive_Search(obj.root, val);
                if (p != NULL)
                {
                    cout << "\n --> Node Value " <<val<<" Found " << endl;
                }
                else
                {
                    cout << "\n --> Node Value " <<val<<" Not Found " << endl;
                }
		        cout<<"\n=============================================================================================\n";
                break;   
            case 4:
		        cout<<"\n=============================================================================================\n";
                cout << " >>> Delete Operation :- " << endl;
                cout << "\n >> Enter Value of Node to Delete in BST :: ";
                cin >> val;
                p = obj.Recursive_Search(obj.root, val);
                if (p != NULL)
                {
                    obj.Delete_Node(obj.root, val);
                    cout << "\n --> Node Value " <<val<<" Deleted " << endl;
                }
                else
                {
                    cout << "\n --> Node Value " <<val<<" Not Found" << endl;
                }
		        cout<<"\n=============================================================================================\n";
                break;    
            case 5:
		        cout<<"\n=============================================================================================\n";
                cout << " >>> BST Height :- " << endl;
                cout << "\n --> Height of the BST is :: " << obj.Height(obj.root) << endl;
		        cout<<"\n=============================================================================================\n";
                break;
            case 6:
		        cout<<"\n=============================================================================================\n";
                cout << "\n --> Smallest Value Node in BST is :: ";
                obj.Min_Value_Node_2(obj.root);
		        cout<<"\n=============================================================================================\n";
                break;    
            case 7:
		        cout<<"\n=============================================================================================\n";
                cout << " >>> Mirror of BST is :- \n\n";
                obj.Mirror_of_BST(obj.root);
                cout<<" --> Preorder of BST   ::  ";
				obj.Preorder_Recursive(obj.root);
				cout<<endl;
				cout<<" --> Inorder of BST    ::  ";
				obj.Inorder_Recursive(obj.root);
				cout<<endl;
				cout<<" --> Postorder of BST  ::  ";
				obj.Postorder_Recursive(obj.root);
				cout<<endl;
		        cout<<"\n=============================================================================================\n";
                break;
            case 8:
		        cout<<"\n=============================================================================================\n";
                cout << "\n --> Leaf Node Value of BST are :: ";
                obj.Leaf(obj.root);
		        cout<<"\n\n=============================================================================================\n";
                break;
        }

        if(choice == 9)
        {
			cout<<"\n \t -----> Program Exited Successfully --> "<<endl;
			cout<<"\n=============================================================================================\n\n\n";
            break;
        }
    }
    return 0;
}
		
		
		
