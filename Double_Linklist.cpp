
#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node*prev;
	
	node(int n){
		data=n;
	}
	
};
node* head;
node*tail;


void create_list(int a1)
{
	node* nn=new node(a1);
	
	if(head==NULL){
	head=tail=nn;
	nn->prev=NULL;
	nn->next=NULL;
	}	
}

void insertatstart(int a2){
	node* nn=new node(a2);
	head->prev=nn;
	nn->next=head;
	nn->prev=NULL;
	head=nn;
}

void insertatend(int a3){
	node* nn=new node(a3);
	if(head==NULL){
		cout<<"Create list first";		
	}
	else{
		tail->next=nn;
		nn->prev=tail->next;
		tail=nn;
		tail->next=NULL;
	}
}

void insertatpos(int aa,int posi){

	node* nn=new node(aa);
	node* tmp=head;
	node* tmp2;
	int i=1;
	while(tmp!=NULL){
		if(i==posi-1){
			tmp2=tmp->next;
			tmp->next=nn;
			nn->prev=tmp->next;
			
			tmp2->prev=nn->next;
			nn->next=tmp2;	
		}
		
		i++;
		tmp=tmp->next;		
	}	
}


void search(int a4)
{
	node* tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->data==a4)
			{
				cout<<"Value exist in list";
		    	break;
			}
		    
		    tmp=tmp->next;
	}
}


void gtrcount(int a5,int count=0,int a=0)
{
	node* tmp=head;
	while(tmp!=NULL)
	{
		if(tmp->data > a5)
			{		
			a++;
			}
			
		    count++;
		    
			tmp = tmp->next;
	}
	cout<<"Greater numbers are:"<<a;	
}


void deletefirst(){
	if(head == NULL)
    {
        cout<<"List is already empty.";
    }
    else{
    	node*tmp=head;
    		head=tmp->next;
    		head->prev=tmp->prev;
    		delete(tmp);
    	cout<<"First node has being deleted.\n";
	}
		
	
}

void deletelast(){
	node* tmp=head;
	
	while(tmp!=NULL){
		if(tmp->next==tail){
			tmp->prev->next=NULL;
			tail=tmp;
		}
		
		tmp=tmp->next;
	}
	
	cout<<"Last node has being deleted.\n";
}

void delatposi(int posi){
	node* tmp=head;
	node* tmp2;
	node*tmp3;
	int noofnode=1;
	
	while(tmp->next!=NULL){

		if(noofnode==posi-1){
			tmp2=tmp->next;
			tmp3=tmp2->next;
			tmp->next=tmp3;
			tmp3->prev=tmp;
			tmp2->next=NULL;	
		}
	noofnode++;
	tmp=tmp->next;	
	}
}

void display(){
	node* tmp=head;
	
	while(tmp!=NULL){
		cout<<tmp->data<<"  ";
		
		tmp=tmp->next;
	}
}




int main(){	
	cout<<"\t\t\t****DOUBLE LINKLIST****"<<endl;
	cout<<"\t1: Create list"<<endl;																		
	cout<<"\t2: Insert new node at start"<<endl;			
	cout<<"\t3: Insert node at the end"<<endl;	
	cout<<"\t4: Insert the node in specific position"<<endl;				
	cout<<"\t5: Search user given value in list"<<endl;	
	cout<<"\t6: Count number of elements greater than user given number"<<endl;
	cout<<"\t7: Delete first node"<<endl;								
	cout<<"\t8: Delete element from last"<<endl;		
	cout<<"\t9: Delete from specific position"<<endl;
	cout<<"\t10: Display values of list"<<endl;			
	cout<<"\t11: Exit\n"<<endl;	
	
	int a,n,loop;
	
	while(true){
		cout<<"\nEnter Choice"<<endl;
		cin>>a;
	
	
	switch(a)
	{
		case 1:
			
			cout<<"Enter data to list:"<<endl;
			cin>>n;
			create_list(n);
			
			
			cout<<"List has being created"<<endl;
			display();
			break;
		
		case 2:
			cout<<"Enter value you want to insert at start:\n";
			cin>>n;
			insertatstart(n);
			cout<<"List is :"<<endl;
			display();
			break;
			
		case 3:
			cout<<"Enter value to insert at end:"<<endl;
			cin>>n;
			insertatend(n);
			cout<<"List is :"<<endl;
			display();
			break;
			
		case 4:
			int i;
			cout<<"Enter the position to add node:";
			cin>>n;
			cout<<"\nEnter value to insert:"<<endl;
			cin>>i;
			insertatpos(i,n);
			cout<<"List is :"<<endl;
			display();
			break;
			
		case 5:
			cout<<"\nEnter value you want to search:"<<endl;
			cin>>n;
		    search(n);
			break;
			
		case 6:
			cout<<"\nEnter value by which you want to check greater numbr:"<<endl;
			cin>>n;
			gtrcount(n);
			
			break;
			
	
    	
    	case 7:
			deletefirst();
			cout<<"list is:"<<endl;
			display();	
			break;
			
		case 8:
			deletelast();
			cout<<"list is:"<<endl;
			display();
			break;
			
		case 9:
			cout<<"Enter the position to del"<<endl;
			cin>>n;
			delatposi(n);
				cout<<"list is:"<<endl;
			display();
			break;
					
		case 10:
			cout<<"List is:\n";
			display();
			
			
	    case 11:
	    	exit(0);
	    	
	    default:
	    	cout<<"\t\tInvalid output!";
			
	}

		
}
	return 0;
}