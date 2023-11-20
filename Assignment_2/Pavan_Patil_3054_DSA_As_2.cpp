#include<iostream>
#include<iomanip>
using namespace std;

class Queue
{
	private:
		int queue[5],front,rear,size=5;
    public:
		Queue()
		{
			front = -1;
			rear = -1;
		}
		void insertion();
		void deletion();
		void display();
};

void Queue::insertion()
{
    int number;
    if(front==-1 && rear==-1)
	{
		front=rear=0;
		cout<<"\n Enter the number to insert = ";
		cin>>number;
		queue[rear]=number;	
	}
    else if((rear+1)%size==front)
	{
		cout<<"\n Queue is full. "<<endl;
	}
	else
	{
		rear = (rear+1)%size;
		cout<<"\n Enter the number to insert = ";
		cin>>number;
		queue[rear]=number;	
	}	
}

void Queue::deletion()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\n >> Queue is empty "<<endl;
	}
    else if(front==rear)
    {
        cout<<"\n >> No. "<<queue[front]<<" is deleted from the Queue"<<endl;
        // front=(front+1)%size;
        front=rear=-1;
    }
	else
	{
		cout<<"\n >> No. "<<queue[front]<<" is deleted from the Queue"<<endl;
        front=(front+1)%size;
	}
}	

void Queue::display()
{
    int i=front;
	cout<<"_____________________________________________________"<<endl;
	cout<<" Front Pointer is = "<<front<<endl<<" Rear Pointer is  = "<<rear<<endl;
	cout<<"_____________________________________________________"<<endl;
	if(front==-1 && rear==-1)
	{
		// cout<<"\n >> Queue is empty "<<endl;
	}
	else
	{
		cout<<"\n >> Queue Displayed is : "<<endl;
		int col_width = 5;
		cout << left;
		cout<<"_____________________________________________________"<<endl;
		cout<<" Queue Value   ";
        while(i!=rear)
		{
			cout<< setw(col_width) <<queue[i];
            i=(i+1)%size;
		}
        cout<< setw(col_width) <<queue[i];

		cout<<"\n_____________________________________________________"<<endl;
	}	
}

int main()
{
	Queue obj;
	int choice;
	cout<<"\n ***** Program For Circular Queue ***** "<<endl;

	do
	{
		cout<<"\n <<< Queue Menu >>> "<<endl;
		cout<<" 1. Enqueue (Insert No.) \n 2. Dequeue (Delete No.) \n 3. Exit the program. "<<endl;
		cout<<"\n >> Enter the Operation to be Performed :: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
			obj.insertion();
			obj.display();
			break;
			case 2:
			obj.deletion();
			obj.display();
			break;
		}
	}while(choice!=3);
	cout<<"\n >>>>> Program Exited Successfully >>>>> \n"<<endl;

	return 0;
}
