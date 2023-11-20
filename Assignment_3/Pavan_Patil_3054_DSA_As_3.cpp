#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;
};

template <class T>
class Stack
{
    Node<T> *top;      //Stack top

    public:
        Stack()
        {
            top = NULL;
        }
        T Get_Top();
        T Empty();
        void Push(T val);
        T Pop();
};

template <class T>
T Stack<T>::Get_Top()
{
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return 0;
    }
}

template <class T>
T Stack<T>::Empty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T>
void Stack<T>::Push(T val)
{
    Node<T> *temp;
    if (top == NULL)
    {
        top = new Node<T>;
        top->data = val;
        top->next = NULL;
    }
    else
    {
        temp = new Node<T>;
        temp->next = top;
        temp->data = val;
        top = temp;
    }
}

template <class T>
T Stack<T>::Pop()
{
    T a;
    if (Empty()!=1)
    {
        a = top->data;
        top = top->next;
    }
    return a;
}

template <class T>
class Expression
{
    Stack <float>S;
    char infix[50], postfix[50],prefix[50];

    public:
        T Priority(char op);
        void Postfix();
        void Prefix();
        void Eval_Postfix();
        void Eval_Prefix();

};

template <class T>
T Expression<T>::Priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

template <class T>
void Expression<T>::Postfix()
{
    int j = 0, var = 0;

	cout<<"\n=====================================================================";
    cout << " \n >> Enter the Infix Expression :: ";
    cin >> infix;

    // Validation to check Infix Expression
    int k = 0;
	if((infix[k]=='-' or infix[k]=='+' or infix[k]=='/' or infix[k]=='*' or infix[k]=='%') or (infix[strlen(infix) - 1]=='-' or infix[strlen(infix) - 1]=='+' or infix[strlen(infix) - 1]=='/' or infix[strlen(infix) - 1]=='*' or infix[strlen(infix) - 1]=='%'))
	{
		cout<<"\n --> The Infix Expression is not Valid "<<endl;
        cout<<"====================================================================="<<endl;
	}

    else
    {
        int flag = 0;
        
        for (int i = 0; i<strlen(infix); i++)
        {
	        if(((infix[i]=='-' or infix[i]=='+' or infix[i]=='/' or infix[i]=='*' or infix[i]=='%') && (infix[i++]=='-' or infix[i++]=='+' or infix[i++]=='/' or infix[i++]=='*' or infix[i++]=='%')) || ((infix[i] <= 'z' && infix[i] >= 'a') || (infix[i] <= 'Z' && infix[i] >= 'A')) && ((infix[i++] <= 'z' && infix[i++] >= 'a') || (infix[i++] <= 'Z' && infix[i++] >= 'A')) )
            {
                cout<<"\n --> The Infix Expression is not Valid "<<endl;
                cout<<"====================================================================="<<endl;
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            k = 1;
        }      
    }
    
	if(k==1)	
	{
		cout<<"\n --> The Infix Expression is Valid "<<endl;
        var=1;

        for (int i = 0; i < strlen(infix) ; i++)
        {
            if ((infix[i] <= 'z' && infix[i] >= 'a') || (infix[i] <= 'Z' && infix[i] >= 'A'))
            {
                postfix[j] = infix[i];
                j++;
            }

            else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
            {
                if (S.Empty() == 1 || (Priority(S.Get_Top()) < Priority(infix[i])))
                {
                    S.Push(infix[i]);
                }
                else
                {
                    while (Priority(S.Get_Top()) >= Priority(infix[i]))
                    {
                        postfix[j++] = S.Pop();
                    }
                    S.Push(infix[i]);
                }
            }
            
            else if(infix[i]=='(')
            {
                S.Push(infix[i]);
            }

            else if (infix[i] == ')')
            {
                while (S.Get_Top() != '(')
                {
                    postfix[j++] = S.Pop();
                }
                S.Pop();
            }
        }
        while (S.Empty() != 1)
        {
            postfix[j++] = S.Pop();
        }
        postfix[j] = '\0';
        cout << "\n --> Postfix Expression is :: " << postfix <<endl;
	}
    if(var == 1)
    {
        Eval_Postfix();
    }
}

template <class T>
void Expression<T>::Prefix()
{
    int j = 0;
    char temp;
    int var = 0;

	cout<<"\n=====================================================================";
    cout << " \n >> Enter the Infix Expression :: ";
    cin >> infix;

    // Validation to check Infix Expression
    int k = 0;
	if((infix[k]=='-' or infix[k]=='+' or infix[k]=='/' or infix[k]=='*' or infix[k]=='%') or (infix[strlen(infix)-1]=='-' or infix[strlen(infix)-1]=='+' or infix[strlen(infix)-1]=='/' or infix[strlen(infix)-1]=='*' or infix[strlen(infix)-1]=='%'))
	{
        cout<<strlen(infix)<<endl;
        cout<<infix[strlen(infix)-1]<<endl;
		cout<<"\n --> The Infix Expression is not Valid "<<endl;
        cout<<"====================================================================="<<endl;
	}

    else
    {
        int flag = 0;
        for (int i = 0; i<strlen(infix); i++)
        {
	        if(((infix[i]=='-' or infix[i]=='+' or infix[i]=='/' or infix[i]=='*' or infix[i]=='%') && (infix[i++]=='-' or infix[i++]=='+' or infix[i++]=='/' or infix[i++]=='*' or infix[i++]=='%')) || ((infix[i] <= 'z' && infix[i] >= 'a') || (infix[i] <= 'Z' && infix[i] >= 'A')) && ((infix[i++] <= 'z' && infix[i++] >= 'a') || (infix[i++] <= 'Z' && infix[i++] >= 'A')) )
            {
                cout<<"\n --> The Infix Expression is not Valid "<<endl;
                cout<<"====================================================================="<<endl;
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            k = 1;
        }   
    }
    
	if(k==1)	
	{
		cout<<"\n --> The Infix Expression is Valid "<<endl;
        var = 1;

        //	strrev(infix);
	    for (int i = 0, j = strlen(infix) - 1; i < strlen(infix)/2; i++, j--)  
        {     
            temp = infix[i];  
            infix[i] = infix[j];  
            infix[j] = temp;  
        }  

        for (int i = 0; i < infix[i] != '\0'; i++)
        {
            if ((infix[i] <= 'z' && infix[i] >= 'a') || (infix[i] <= 'Z' && infix[i] >= 'A'))
            {
                prefix[j] = infix[i];
                j++;
            }

            else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
            {
                if (S.Empty() == 1 || (Priority(S.Get_Top()) < Priority(infix[i])))
                {
                    S.Push(infix[i]);
                }
                else
                {
                    while (Priority(S.Get_Top()) >= Priority(infix[i]))
                    {
                        prefix[j++] = S.Pop();
                    }
                    S.Push(infix[i]);
                }
            }
            else if(infix[i]==')')
            {
                S.Push(infix[i]);
            }
            else if (infix[i] == '(')
            {
                while (S.Get_Top() != ')')
                {
                    prefix[j++] = S.Pop();
                }
                S.Pop();
            }
        }
        while (S.Empty() != 1)
        {
            prefix[j++] = S.Pop();
        }

        prefix[j] = '\0';

        //strrev(prefix); 
        for (int i = 0, j = strlen(prefix) - 1; i < strlen(prefix)/2; i++, j--)  
        {     
            temp = prefix[i];  
            prefix[i] = prefix[j];  
            prefix[j] = temp;  
        }   

        cout << "\n --> Prefix Expression is :: " << prefix <<endl;
	}
    if(var == 1)
    {
        Eval_Prefix();
    }
}

template <class T>
void Expression<T>::Eval_Postfix()
{
	char x;
	float value;

	for(int i=0 ; postfix[i]!='\0' ;i++)
    {
        x = postfix[i];
     	if(isalpha(x))
      	{
         	cout<<" >> Enter the value of "<<x<<" = ";
         	cin>>value;
            S.Push(value);
      	}
        else
        {
            float op1 = S.Get_Top();
            S.Pop();
            float op2 = S.Get_Top();
            S.Pop();

            switch (postfix[i])
            {
                case '+' :
                    S.Push(op2+op1);
                    break;
                
                case '-' :
                    S.Push(op2-op1);
                    break;

                case '*' :
                    S.Push(op2*op1);
                    break;

                case '/' :
                    S.Push(op2/op1);
                    break;

                case '^' :
                    S.Push(pow(op2,op1));
                    break;
            }
        }
    }

    cout << "\n --> Evaluation of Postfix Expression is = " << S.Get_Top() << endl;
	cout<<"=====================================================================\n";
}

template <class T>
void Expression<T>::Eval_Prefix()
{
  	char x;
  	float value;

    for (int i = (strlen(prefix) - 1); i >= 0; i--)
    {
        x=prefix[i];
     	if(isalpha(x))
      	{
         	cout<<" >> Enter the value of "<<x<<" = ";
         	cin>>value;
         	S.Push(value);
      	}
        else
        {
            float op1 = S.Get_Top();
            S.Pop();
            float op2 = S.Get_Top();
            S.Pop();

            switch (prefix[i])
            {
                case '+':
                    S.Push(op1 + op2);
                    break;

                case '-':
                    S.Push(op1 - op2);
                    break;

                case '*':
                    S.Push(op1 * op2);
                    break;

                case '/':
                    S.Push(op1 / op2);
                    break;

                case '^':
                    S.Push(pow(op1, op2));
                    break;
            }
        }
    }

    cout << "\n --> Evaluation of Prefix Expression is = " << S.Get_Top()<<endl;
	cout<<"=====================================================================\n";
}

int main()
{	
	cout<<"\n \t\t ========================== \n";
	cout<<" \t\t ||   Infix to Postfix   || \n";
	cout<<" \t\t ========================== \n\n";
    Expression <float>obj;
    int choice;

    while(1)
	{
		cout<<"\n=====================================================================\n";
		cout<<" >>> Conversion Menu :- \n";
		cout<<"\n 1] Infix to Postfix. \t 2] Postfix Evaluation. \n 3] Infix to Prefix \t 4] Prefix Evaluation \n 5] Exit the Program "<<endl;
		cout<<"\n >> Enter the Conversion to be Performed = ";
		cin>>choice;
		cout<<"=====================================================================\n";

		if(choice==5)
		{
			cout<<"\n \t -----> Program Exited Successfully --> "<<endl;
			cout<<"\n=====================================================================\n\n";
			break;
		}
		else
		{
			switch (choice)
			{
				case 1 :
                    obj.Postfix();
					break;
		
				case 2 :
					obj.Postfix();
					cout<<endl;
                   // obj.Eval_Postfix();
					break;

				case 3 :
                    obj.Prefix();
					break;	

				case 4 :
					obj.Prefix();
					cout<<endl;
                  //  obj.Eval_Prefix();
					break;	
			}
		}
	}


    return 0;
}
