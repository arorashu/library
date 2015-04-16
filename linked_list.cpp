#include<iostream>
//#include<process.h>
using namespace std;

class node
{
private:
	int data;
	node *next;
public:

	node()
	{
		data=0;
		next=NULL;
	}

	int getdata()
	{return data;}

	node* getnext()
	{return next;}

	void setdata(int x)
	{data=x;}

	void setnext(node *t)
	{next=t;}
};

class list
{
private:
	node *head;
public:
	list()
	{
		head=NULL;
	}

	~list()
	{
		node *t;
		while( head!= NULL )
		{
			t=head;
			head=head->getnext();
			delete t;
		}
	}

	void add_at_start(int x)
	{
		node *t=new node;
		t->setdata(x);
		t->setnext(head);
		head=t;
	}

	void add_at_end(int x)
	{
		node *t;
		t=head;
		while( t->getnext()!=NULL )
		{
			t=t->getnext();
		}

		node *s=new node;
		t->setnext(s);
		s->setdata(x);
		s->setnext(NULL);
	}

	void display()
	{
		if(head==NULL)
			{cout<<"List Empty\n\n";return;}

		node *t;
		t=head;
		while( t->getnext()!=NULL )
		{
			cout<<t->getdata()<<' ';
			t=t->getnext();
		}
		cout<<t->getdata()<<'\n';
	}

	void remove(int n)
	{
		node *t;
		t=head;
		if( t==NULL )
		{
			cout<<"Underflow";
			return;
		}
		if(t->getdata()==n)
		{
			t=head;
			head=head->getnext();
			delete t;
			return;
		}

		while( t->getnext()!=NULL )
		{
			if(t->getnext()->getdata() == n )
			{
				node *s=t->getnext();
				t->setnext(s->getnext());
				delete s;
				return ;
			}

			t=t->getnext();
		}

	}

};
list start;

void menu()
{
	cout<<"List\n";
	cout<<"What do you want to do?\n";
	cout<<"1.add_at_start\n";
	cout<<"2.add_at_end\n";
	cout<<"3.display list\n";
	cout<<"4.Delete data by value\n";
	cout<<"anything else. exit()\n";
	cout<<"Enter choice: ";
	int c;
	cin>>c;

	int x;
	switch(c)
	{
		case 1: 
		cout<<"What number to add at start? : ";
		cin>>x;
		start.add_at_start(x);
		menu();
		break; 

		case 2: 
		cout<<"What number to add at end? : ";
		cin>>x;
		start.add_at_end(x);
		menu();
		break;

		case 3: 
		start.display();
		menu();
		break;

		case 4:
		cout<<"What number to delete? : ";
		cin>>x;
		start.remove(x);
		menu();
		break;

		default:
		break;
	}
}


int main()
{

	menu();
	return 0;
}