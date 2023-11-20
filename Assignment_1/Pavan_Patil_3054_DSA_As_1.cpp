#include <iostream>
#include <iomanip>
using namespace std;

struct student
{
	int rollno;
	float SGPA;
	string name;
};

class studentinfo
{
private:
	student stud[50];

public:
	int len;
	void getdata();
	void bubble_sort();
	void insertion_sort();
	int quick_sort(int left, int right);
	int partition(int left, int right);
	void display_1();
	void display_2();
	void display_3();
	void search_SGPA();
	void search_Name();
};

void studentinfo::getdata()
{
	cout << "Enter the Total No of Students = ";
	cin >> len;
	cout << endl;

	int i;
	for (i = 0; i < len; i++)
	{
		cout << "Enter the Roll No. of Student " << (i + 1) << " = ";
		cin >> stud[i].rollno;
		cout << endl;
		cout << "Enter the name of Student " << (i + 1) << " = ";
		cin >> stud[i].name;
		cout << endl;
		cout << "Enter the SGPA of Student " << (i + 1) << " = ";
		cin >> stud[i].SGPA;

		if (stud[i].SGPA > 10)
		{
			cout << "\n >>>>> Enter valid SGPA >>>>> " << endl;
			stud[i].rollno = 0;
			stud[i].name = " ";
			stud[i].SGPA = 0.0;
			i--;
		}
		cout << endl;
	}

	cout << "Entered Student Details are : " << endl
		 << endl;

	for (i = 0; i < len; i++)
	{
		cout << "Roll No = " << stud[i].rollno << " ";
		cout << "Name = " << stud[i].name << " ";
		cout << "SGPA = " << stud[i].SGPA << " " << endl;
	}
	cout << endl;
}

void studentinfo::bubble_sort()
{
	int i, j;
	student temp;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (stud[j].rollno > stud[j + 1].rollno)
			{
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}
		}
	}
}

void studentinfo::insertion_sort()
{
	int i, j;
	student key;

	for (i = 0; i < (len - 1); i++)
	{
		key = stud[i + 1];

		for (j = i + 1; j > 0; j--)
		{
			if (stud[j-1].name > stud[j].name)
			{
				stud[j] = stud[j - 1];
				stud[j - 1] = key;
			}
			else
			{
				break;
			}
		}
	}
}

int studentinfo::quick_sort(int left, int right)
{
	if (left >= right)
	{
		return 0;
	}

	else
	{
		float p = partition(left, right);
		quick_sort(left, p - 1);
		quick_sort(p + 1, right);

		return 0;
	}
}

int studentinfo::partition(int left, int right)
{
	int i = left, j = right - 1;
	float pivot = stud[right].SGPA;

	while (i <= j)
	{
		while (stud[i].SGPA < pivot)
		{
			i++;
		}

		while (j > 0 && stud[j].SGPA > pivot)
		{
			j--;
		}

		if (i < j)
		{
			swap(stud[i].SGPA, stud[j].SGPA);
		}
		j--;
	}
	swap(stud[i].SGPA, stud[right].SGPA);

	return i;
}

void studentinfo::display_1()
{
	int col_width = 15;
	cout << left;
	cout << "___________________________________________________" << endl;
	cout << "Array Sorted by Roll No using Bubble Sort is : " << endl;
	cout << "___________________________________________________" << endl;
	cout << setw(col_width) << "Sr. No";
	cout << setw(col_width) << "Roll No";
	cout << setw(col_width) << "Name";
	cout << setw(col_width) << "SGPA" << endl;
	cout << "___________________________________________________" << endl;

	int i;
	for (i = 0; i < len; i++)
	{
		cout << left;
		cout << setw(col_width) << (i + 1);
		cout << setw(col_width) << stud[i].rollno;
		cout << setw(col_width) << stud[i].name;
		cout << setw(col_width) << stud[i].SGPA << endl;
		cout << "___________________________________________________" << endl;
	}
	cout << endl
		 << endl;
}

void studentinfo::display_2()
{
	int col_width = 15;
	cout << left;
	cout << "___________________________________________________" << endl;
	cout << "Array Sorted by Name using Insertion Sort is : " << endl;
	cout << "___________________________________________________" << endl;
	cout << setw(col_width) << "Sr. No";
	cout << setw(col_width) << "Roll No";
	cout << setw(col_width) << "Name";
	cout << setw(col_width) << "SGPA" << endl;
	cout << "___________________________________________________" << endl;

	int i;
	for (i = 0; i < len; i++)
	{
		cout << left;
		cout << setw(col_width) << (i + 1);
		cout << setw(col_width) << stud[i].rollno;
		cout << setw(col_width) << stud[i].name;
		cout << setw(col_width) << stud[i].SGPA << endl;
		cout << "___________________________________________________" << endl;
	}
	cout << endl
		 << endl;
}

void studentinfo::display_3()
{
	int col_width = 15;
	cout << left;
	cout << "________________________________________________________" << endl;
	cout << "First 10 Toppers of class are : " << endl;
	cout << "________________________________________________________" << endl;
	cout << setw(col_width) << "Sr. No";
	cout << setw(col_width) << "Roll No";
	cout << setw(col_width) << "Name";
	cout << setw(col_width) << "SGPA" << endl;
	cout << "________________________________________________________" << endl;

	int i, j;
	for (i = len - 1, j = 1; i >= 0, j <= len; i--, j++)
	{
		if (j >= 11)
		{
			break;
		}
		cout << left;
		cout << setw(col_width) << j;
		cout << setw(col_width) << stud[i].rollno;
		cout << setw(col_width) << stud[i].name;
		cout << setw(col_width) << stud[i].SGPA << endl;
		cout << "________________________________________________________" << endl;
	}
	cout << endl
		 << endl;
}

void studentinfo::search_Name()
{
	int i, j;
	student temp;
	
	for (i = 0; i < len - 1; i++)
	{
		temp = stud[i + 1];
		j = i;

		while (stud[j].name > stud[i + 1].name && j >= 0)
		{
			stud[j + 1] = stud[j];
			stud[j] = temp;
			j--;
		}
	}

	int flag = 0, left = 0, right = (len - 1), mid = 0;
	string check;
	cout << "Enter the Name of the Student to Search = ";
	cin >> check;

	cout << "The Students are : " << endl
		 << endl;
		 
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (stud[mid].name == check)
		{
			cout << "Roll No = " << stud[mid].rollno << " " << endl;
			cout << "Name = " << stud[mid].name << " " << endl;
			cout << "SGPA = " << stud[mid].SGPA << " " << endl
				 << endl;
			flag = 1;
		}
		if (stud[mid].name > check)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (flag == 0)
	{
		cout << " There is no student with this Name " << endl
			 << endl;
	}
}

void studentinfo::search_SGPA()
{
	int flag = 0, i;
	float check;
	cout << "Enter the SGPA of the Student to Search = ";
	cin >> check;

	cout << "The Students are : " << endl
		 << endl;
	for (i = 0; i < len; i++)
	{
		if (check == stud[i].SGPA)
		{
			cout << "Roll No = " << stud[i].rollno << " " << endl;
			cout << "Name = " << stud[i].name << " " << endl;
			cout << "SGPA = " << stud[i].SGPA << " " << endl
				 << endl;
			flag++;
		}
	}

	if (flag == 0)
	{
		cout << " There is no student with this SGPA " << endl
			 << endl;
	}
	cout << endl;
}

int main()
{
	cout << "\n <<<<<<<<<< Program to Display the Data of the Students >>>>>>>>>> " << endl;
	int choice;

	cout << "\n ***** Program to Display the Sortings ***** " << endl
		 << endl;
	studentinfo inf;
	inf.getdata();

	while (1)
	{
		cout << " ***** Sorting Menu ***** " << endl
			 << endl;
		cout << " 1. Roll No in Ascending order \n 2. list of students Alphabetically \n 3. List of Students to find our first ten toppers from a class \n 4. Search Students according to SGPA \n 5. Search a particular Student according to Name \n 6. Exit the Program " << endl
			 << endl;

		cout << "Enter the Operation to be Performed = ";
		cin >> choice;
		cout << endl;

		if (choice == 6)
		{
			cout << " ***** Program Exited Successfully ***** " << endl
				 << endl;
			break;
		}
		else
		{
			switch (choice)
			{
			case 1:
				inf.bubble_sort();
				inf.display_1();
				break;

			case 2:
				inf.insertion_sort();
				inf.display_2();
				break;

			case 3:
				inf.quick_sort(0, inf.len - 1);
				inf.display_3();
				break;

			case 4:
				inf.search_SGPA();
				break;

			case 5:
				inf.search_Name();
				break;
			}
		}
	}
	return 0;
}
