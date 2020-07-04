#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
struct alpha
{
int reg_num, quiz_1, quiz_2, quiz_3, mid_term, final_term;
string student_name;


alpha *next = NULL;
alpha *previous = NULL;

}*head = NULL, *tail = NULL;

class beta
{
public:
void create_node()
{
int a, q1, q2, q3, mid, final;
string name;
cout << "Enter Student Name: " << endl;
cin>>name;
cout << "reg num ??? " << endl;
cin >> a;
cout << "quiz 1 " << endl;
cin >> q1;
cout << "quiz 2 " << endl;
cin >> q2;
cout << "quiz 3 " << endl;
cin >> q3;
cout << "Enter Mid Term Marks: " << endl;
cin >> mid;
cout << "Enter Final Term Marks: " << endl;
cin >> final;
alpha *node = new alpha;
node->student_name=name;
node->reg_num = a;
node->quiz_1 = q1;
node->quiz_2 = q2;
node->quiz_3 = q3;
node->mid_term = mid;
node->final_term = final;
node->next = NULL;
node->previous = NULL;
if (head == NULL)
{
head = node;
tail = node;
}
else
{
tail->next = node;
node->previous = tail;
tail = node;
}

}
void insertion()
{
create_node();
}
void display()
{

alpha* disp;
disp = head;
while (disp != NULL)
{

cout << "Student Name : " << disp->student_name << endl;
cout << "Registration number : " << disp->reg_num << endl;
cout << "Quiz 01 marks : " << disp->quiz_1 << endl;
cout << "Quiz 02 marks : " << disp->quiz_2 << endl;
cout << "Quiz 03 marks : " << disp->quiz_3 << endl;
cout << "Mid Term marks : " << disp->mid_term << endl;
cout << "Term marks : " << disp->final_term << endl;
disp = disp->next;
}
cout << endl;
}
void deletion()
{
int r;
alpha *temp = head;
cout << "ENTER the reg no" << endl;
cin >> r;
while (temp != NULL)
{

if (r == temp->reg_num)
{
alpha *arzi = temp;
arzi->previous->next = arzi->next;
arzi->next->previous = arzi->previous;
delete arzi;
break;
}
temp = temp->next;
}
}

void sort_reg()
{
alpha *ptr1, *ptr2 = NULL;
if (head == NULL)
{
return;
}
bool condition = true;
while (condition == true)
{
condition = false;
ptr1 = head; //allocating to start
while (ptr1->next != ptr2)
{
if (ptr1->reg_num > ptr1->next->reg_num)
{
swap(ptr1->reg_num, ptr1->next->reg_num);
condition = true; //reseting
}
ptr1 = ptr1->next;
}
ptr2 = ptr1;
}
}

void sort_mid()
{
alpha *ptr1, *ptr2 = NULL;
if (head == NULL)
{
return;
}
bool condition = true;
while (condition == true)
{
condition = false;
ptr1 = head; //allocating to start
while (ptr1->next != ptr2)
{
if (ptr1->mid_term > ptr1->next->mid_term)
{
swap(ptr1->mid_term, ptr1->next->mid_term);
condition = true; //reseting
}
ptr1 = ptr1->next;
}
ptr2 = ptr1;
}
}
void sort_final()
{
alpha *ptr1, *ptr2 = NULL;
if (head == NULL)
{
return;
}
bool condition = true;
while (condition == true)
{
condition = false;
ptr1 = head; //allocating to start
while (ptr1->next != ptr2)
{
if (ptr1->final_term > ptr1->next->final_term)
{
swap(ptr1->final_term, ptr1->next->final_term);
condition = true; //reseting
}
ptr1 = ptr1->next;
}
ptr2 = ptr1;
}
}
void searching()
{
	alpha *temp=head;
	int r;
	cout<<"Enter the registration no to find the record"<<endl;
	cin>>r;
	while(temp!=NULL)
	{
		if(temp->reg_num==r)
		{
cout << "Student Name : " << temp->student_name << endl;
cout << "Registration number : " << temp->reg_num << endl;
cout << "Quiz 01 marks : " << temp->quiz_1 << endl;
cout << "Quiz 02 marks : " << temp->quiz_2 << endl;
cout << "Quiz 03 marks : " << temp->quiz_3 << endl;
cout << "Mid Term marks : " << temp->mid_term << endl;
cout << "Term marks : " << temp->final_term << endl;
break;
		}
		temp=temp->next;
	}
}
void save_file()
{
	alpha *temp=head;
		ofstream fout ("StudentRecord.txt",ios::app);//creates a file and writes information in the fileS
		while(temp!=NULL)
		{
		fout<<"Student Name :"<<temp->student_name<<endl;
		fout<<"Registration number :"<<temp->reg_num<<endl;
		fout<<"Quiz 01 marks : " <<temp->quiz_1<<endl;
		fout<<"Quiz 02 marks : "<<temp->quiz_2<<endl;
		fout<<"Quiz 03 marks : "<<temp->quiz_3<<endl;
		fout<<"Mid Term marks : "<<temp->mid_term<<endl;
		fout<<"Term marks :  "<<temp->final_term<<endl;
		temp=temp->next;
	}
		fout.close();
}
void load()
{
		ifstream fin("studentinfo.txt");
	string ch;
		while(!fin.eof())
		{
			fin>>ch;
			cout<<ch<<endl;
		}
		fin.close();
	}

};

int main()
{
beta object;
int n = 0;
int srt = 0;
while (1)
{
cout << "Press 1 to Load Record : " << endl;
cout << "Press 2 to Sort Elements : " << endl;
cout << "Press 3 for Display: " << endl;
cout << "Press 4 for Finding: " << endl;
cout << "Press 5 for Insertion: " << endl;
cout << "Press 6 for Deletion: " << endl;
cout << "Press 7 for Saving: " << endl;
cout << "Press 0 for EXIT TASK : " << endl;
cin >> n;
switch (n)
{
 case 1:
 	object.load();
 	break;

case 2:
system("cls");
cout << "Choose type of sorting. " << endl;
cout << "Press 1 to Sort with Registration number. " << endl;
cout << "Press 2 to Sort with MidTerm number. " << endl;
cout << "Press 3 to Sort with FinalTerm number. " << endl;
{
cin >> srt;
switch (srt)
{
case 1:
cout << "Showing data sorted by Registration number: " << endl;
object.sort_reg();
break;
case 2:
cout << "Showing data sorted by Midterm numbers: " << endl;
object.sort_mid();
break;
case 3:
cout << "Showing data sorted by FinalTerm numbers : " << endl;
object.sort_final();
break;
}
break;
}
case 3:
cout << "Displaying... " << endl << endl;
object.display();
break;
case 4:
cout << "Finding Data" << endl;
object.searching();
break;
case 5:
cout << "You choose insertion: " << endl;
object.insertion();
break;
case 6:
cout << "Deleting record: " << endl;
object.deletion();
break;
case 7:
	cout<<"Your Data is Saved"<<endl;
	object.save_file();
	break;


case 0:
system("cls");
return 0; //exit
default:
cout << "You choose wrong option." << endl;
break;
}
}
system("pause");
return 0;
}
