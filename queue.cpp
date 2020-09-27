#include <iostream>

using namespace std;

// node class for the queue
class nodeq
{
public:
	int val;
	nodeq *next;
	nodeq(int a)
	{ 
		val = a;
	}
};

// node class for the hash table which stores a version's information
class node
{
public:
	int ver;
	nodeq *first, *second;
	node *next;
	node(int a=0, nodeq *b=NULL, nodeq *c=NULL)
	{
		ver = a;
		first = b;
		second = c;
	}
};

// hash table to store versions' data
class hash_table
{
	node* adds[101];
public:
	hash_table()
	{
		for(int i=0; i<101; i++) adds[i]= NULL;
	}
	node* find(int version)
	{
		node *head = adds[version%101];
		node *ans = new node();
		while(head!=NULL)
		{
			if(head->ver==version)
			{
				ans->ver = version;
				ans->first = head->first;
				ans->second = head->second;
				return ans;
			}
		}
		return ans;
	}
	void insert(int ver, nodeq *first, nodeq *last)
	{
		node *temp = new node(ver, first, last);
		node *head = adds[ver%101];
		if(!head) 
		{
			adds[ver%101] = temp;
			return;
		}
		while(head->next!=NULL) head=head->next;
		head->next=temp;
	}
};


// queue class to store all the values which have come so far
class queue
{
	nodeq  *head, *tail;
	hash_table ht;
	int version;
public:
	queue()
	{
		head = NULL;
		tail = NULL;
		version = 0;
	}
	void enque(int val)
	{
		version++;
		nodeq *temp = new nodeq(val);
		if(!head) 
		{
			head = temp;
			tail = temp;
		} 
		else 
		{
			tail->next = temp;
			tail = temp;
		}
		ht.insert(version, head, tail);
	}
	void deque()
	{
		if(!head) 
		{
			cout<<"NULL\n";
			return;
		}
		version++;
		cout<<head->val<<"\n";
		if(head==tail) tail = tail->next;
		head = head->next;
		ht.insert(version, head, tail);
	}
	void enquiry(int ver)
	{
		if(ver>version)
		{
			cout<<"greater than the latest version: "<<version<<"\n";
			return;
		}
		node* temp = ht.find(ver);
		nodeq *h = temp->first, *t = temp->second;
		if(!h) 
		{
			cout<<"NULL\n";
			return;
		}
		while(h!=t)
		{
			cout<<h->val<<" ";
			h = h->next;
		}
		cout<<h->val<<"\n";
	}
};

int main()
{
	queue q;
	int a, b;
	cout<<"*****instructions*****"<<"\n"
		<<"1 followed by value for enqueue\n"
		<<"2 followed by none for deque\n"
		<<"3 followed by version number for enquiry\n"
		<<"4 for termination\n*******************\n";
	while(1)
	{
		cin>>a;
		if(a==4) break;
		if(a==1) 
		{
			cin>>b;
			q.enque(b);
		}
		else if(a==2) q.deque();
		else
		{
			cin>>b;
			q.enquiry(b);
		}
	}
	return 0;
}