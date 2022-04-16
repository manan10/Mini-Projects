#include<stdio.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

node* getnode()
{
	node* tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp -> next = NULL;
	return tmp;
}


node* create()
{	
	node *start,*trv,*new;
	start = NULL;
	int value;
	char ch;
	do
	{
		new=getnode();
		printf("Enter Data : ");
		scanf("%d",&value);
		new->data=value;
		if(start==NULL)
		{
			start=new;
			trv=new;
		}	
		else
		{
			trv->next=new;
			trv = new;
		}
		printf("Press Y to continue : ");
		scanf("%s",&ch);
	}
	while(ch=='y' || ch=='Y');
	return start;
}

void display(node* start)
{
	node *trv;
	trv=start;
	if(trv==NULL)
	{
		printf("\nThere are no nodes in the link list");
	}
	else
	{
		printf("\nThe Values in link list are :\n");
		while(trv != NULL)
		{
			printf("%d ",trv->data);
			trv=trv->next;
		}
	}			
}

node* insert(node* start)
{
	node *new;
	new=getnode();
	printf("\nEnter new data :");
	scanf("%d",&new->data);
	if(start == NULL)
	{
		start=new;
	}
	else
	{
		new->next=start;
		start = new;
	}
	return start;
}
				

node* insert_end(node* start)
{
	node *new,*trv;
	trv=start;
	new=getnode();
	printf("\nEnter new Value to put at the end :");
	scanf("%d",&new->data);
	if(start==NULL)
	{
		new=start;
	}
	else
	{
		while(trv->next !=NULL)
		{
			trv=trv->next;
		}
		trv->next=new;
	}
	return start;
}


node* insert_pos(node* start)
{
	node *new,*trv;
	int pos,cnt=0;
	trv=start;
	new=getnode();
	printf("\nEnter new Value : ");
	scanf("%d",&new->data);
	if(start==NULL)
	{
		start=new;
	}				
	else
	{
		printf("\nEnter the position at which you want to insert the value: ");
		scanf("%d",&pos);
		while(trv !=NULL && cnt < pos)
		{
			trv=trv->next;
			cnt++;
		}
		if(trv !=NULL)
		{
			new->next = trv->next;	
			trv->next = new;
		}
		else
		{
			printf("\nNo such position found in linked list.");
			free(new);
		}	
		return start;
	}	
}	


node* insert_bef_val(node* start,int x)
{
	node *new,*trv,*prev;
	trv=start;
	prev=start;
	new=getnode();
	printf("\nEnter The Data");
	scanf("%d",&new->data);
	if(start==NULL)
	{
		printf("Link List is Empty");
	} 
	else
	{
		while(trv->next !=NULL && trv->data != x)
		{
			trv=trv->next;
		}
		while(prev->next !=trv)
		{
			prev=prev->next;
		} 
		new->next=trv;
		prev->next=new;
	}
	return start;
}

node* insert_aft_val(node *start,int x)
{
	node *new,*trv,*prev;
	trv=start;
	prev=start;
	new=getnode();
	printf("\nEnter the data :  ");
	scanf("%d",&new->data);
	if(start==NULL)
	{
		printf("\nThe link list is empty");
	}
	else
	{
		while(trv->next !=NULL && trv->data !=x)
		{
			trv=trv->next;
			prev=trv;
		}
		trv=trv->next;
		new->next=trv;
		prev->next=new;
	}
	return start;  
}	 

node* del_first(node *start)
{
	node *trv;
	trv = start;
	if(start==NULL)
	{
		printf("\nLink List is empty.");
	}
	else
	{
		start=start->next;
		free(trv);
	}
	return start;
}

node* del_last(node *start)
{
	node *trv,*prev;
	trv=start;
	if(start==NULL)
	{
		printf("\nLink List is empty");
	}
	else
	{
		while(trv->next != NULL)
		{
			prev=trv;
			trv=trv->next;
		}
		prev->next=NULL;
		free(trv);
	}
	return start;
}
node* del_pos_bef(node* start)
{
	node *old,*trv;
	int pos,cnt=1;
	trv=start;
	if(start==NULL)
	{
		printf("\nLink list is empty");
	}
	else
	{
		printf("\nEnter the position to delete a node before it: ");
		scanf("%d",&pos);
		while(trv!=NULL && cnt<pos-2)
		{
			trv=trv->next;
			cnt++;
		}
		if(trv!=NULL)
		{
			old=trv->next;
			trv->next=old->next;
			old->next=NULL;
			free(old);
		}
		else
		{
			printf("INVALID POSITION\n");
		}	
	}
	return start;
}

node* del_pos_aft(node* start)
{
	node *old,*trv;
	int pos,cnt=1;
	trv=start;
	if(start==NULL)
	{
		printf("\nLink list is empty");
	}
	else
	{
		printf("\nEnter the position to delete a node after it: ");
		scanf("%d",&pos);
		while(trv!=NULL && cnt<pos)
		{
			trv=trv->next;
			cnt++;
		}
		if(trv->next!=NULL)
		{
			old=trv->next;
			trv->next=old->next;
			old->next=NULL;
			free(old);
		}
		else
		{
			printf("INVALID POSITION\n");
		}	
	}
	return start;
}

int max(node *start)
{
	node *trv;
	int max;
	trv = start;
	if(start == NULL)
	{
		printf("\nThe Linked List is Empty");
	}
	else
	{
		max = trv->data;
		while(trv->next != NULL)
		{
			trv = trv-> next;
			if(trv->data > max)
			{
				max = trv->data;
			}
		}
	}
	return max;
}

int length(node *start)
{
	node *trv;
	int cnt=1;
	trv=start;
	if(start == NULL)
	{
		printf("\nThe Length of the linked list is %d",cnt-1);
	}
	else
	{
		while(trv->next != NULL)
		{
			trv = trv-> next;
			cnt++;
		}
		printf("\nThe Length of the linked list is %d",cnt);
	}						
	return cnt;
}	


int search(node *start,int value)
{
	node *trv;
	trv=start;
	int cnt=1;
	if(start == NULL)
	{
		printf("Linked List is Empty");
	}
	else
	{
		while(trv != NULL && trv->data != value)
		{
			trv = trv -> next;
			cnt++; 	
		}
	}
	if(trv == NULL)
	{
		return -1;
	}	
	else
	{
		return cnt;
	}
}	


void replace(node *start,int x,int y)
{
	node *trv;
	trv=start;
	int cnt=1;
	if(start == NULL)
	{
		printf("\nLinked List is Empty");
	}
	else
	{
		while(trv != NULL && trv->data != x)
		{
			trv = trv -> next;
			cnt++; 	
		}
		if(trv == NULL)
		{
			printf("\nThe value does'nt exist");
		}	
		else
		{
			trv->data = y;
			printf("\nThe Value is Replaced");
		}
	}	
}	
	
void sort_asc(node *start)
{
	int i;
	node *trv1,*trv2;
	trv1=start;
	if(start==NULL)
	{
		printf("Linked List is empty");
	}
	else
	{
		while(trv1 != NULL)
		{
			trv2 = trv1->next;
			while(trv2 != NULL)
			{
				if(trv1->data >  trv2->data)
				{
					i = trv1->data;
					trv1->data = trv2->data;
					trv2->data = i;
				}
				trv2 = trv2->next;
			}
			trv1 = trv1->next;
		}
	}
}

void sort_desc(node *start)
{
	int i;
	node *trv1,*trv2;
	trv1=start;
	if(start==NULL)
	{
		printf("Linked List is empty");
	}
	else
	{
		while(trv1 != NULL)
		{
			trv2 = trv1->next;
			while(trv2 != NULL)
			{
				if(trv1->data <  trv2->data)
				{
					i = trv1->data;
					trv1->data = trv2->data;
					trv2->data = i;
				}
				trv2 = trv2->next;
			}
			trv1 = trv1->next;
		}
	}
}

node* reverse(node *start)
{
	node *trv3,*trv1,*trv2;
	trv1=start;
	trv2=NULL;
	if(start==NULL)
	{
		printf("Linked List is Empty");
	}
	else
	{
		while(trv1 != NULL)
		{
			trv3=trv2;
			trv2=trv1;
			trv1=trv1->next;
			trv2->next=trv3;
		}
		start=trv2;
	}
	return start;
}


node* copy(node* start)
{
	node *start2,*trv1,*trv2;
	trv1=start;
	if(start == NULL)
	{
		printf("The LInked List is Empty");
	}
	else
	{
		start2=(node*)malloc(sizeof(node));
		start2->next=NULL;
		trv2=start2;
		trv1->data=trv2->data;
		while(trv1 != NULL)
		{
			trv1=trv1->next;
			trv2->next=(node*)malloc(sizeof(node));
			trv2=trv2->next;
			trv1->data=trv2->data;
		}
		trv2=NULL;
	}
	return start2;
}      

node* concate(node *start,node *start2) 
{   
	printf("\nEnter values of second Linked List \n");   
	start2 = create();   
	node *trv;  
	trv=start;  
	if(start==NULL)
	{
		return start2;  
	}   
	else if(start2==NULL)   
	{
		return start;
	} 
	else 
	{   
		while(trv->next!=NULL)   
		{       
			trv=trv->next;   
		}    
		trv->next=start2;  
		printf("\nConnected linked list = ");    
		return start;  
	} 
}
			

node* insert_asc(node *start,int x)
{
	node *trv,*new,*prev;
	trv=start;
	prev=trv;
	if(start==NULL)
	{
		printf("Linked List was empty");
		trv=getnode();
		trv->data==x;
		trv->next=NULL;
	}
	else
	{
		sort_asc(start);
		trv=start;
		new=getnode();
		new->data=x;
		while(trv->data < x)
		{
			trv=trv->next;
		}
		 
		if(trv==start)                                                                           // IF X is lowest insert at beginnning //
		{
			new->next=trv;
			start=new;
		}
		else if(trv==NULL)																		// IF X is max insert at last    //		
		{
			trv=new;
		}
		else																				   // IF X is intermidiate inset in between //
		{
			while(prev->next !=trv)
			{	
				prev=prev->next;
			}
			new->next=trv;
			prev->next=new;
		}
	}
	return start;
}




main()
{
	node *start,*start2;
	char ch1; 
	int ch,m,c,value,cnt,x,y;
	start=create();
	display(start);
	do
	{	
		printf("\n--------------------------------------MENU------------------------------------------------");
		printf("\nPlease Enter the corresponding no to perform the required task");
		printf("\n\n1-->Insert Node at the Beginning");
		printf("\n2-->Insert Node at the end");
		printf("\n3-->Insert Node at any specific position");
		printf("\n4-->Insert before specific data");
		printf("\n5-->Insert after specific data");
		printf("\n6-->Delete First Node");
		printf("\n7-->Delete Last Node");
		printf("\n8-->Delete Node before the Entered Position");
		printf("\n9-->Delete Node after the Entered Position");
		printf("\n10-->To get the Maximum Value in the Linked List");
		printf("\n11-->To Find the total no of Nodes");
		printf("\n12-->To get the position of a specific data in the Linked List");
		printf("\n13-->To Replace an existing data with a new one");
		printf("\n14-->To Sort The Linked List in ascending order");
		printf("\n15-->To Sort The Linked List in descending order");
		printf("\n16-->To Reverse The Linked List");
		printf("\n17-->To Copy Linked List");
		printf("\n18-->To Concate Linked List");
		printf("\n19-->To insert such that Linked list is in ascending order.");
		scanf("\t%d",&ch);
	
		switch(ch)
		{
			case 1:
			{
				start=insert(start);
				display(start);
				break;
			}
			case 2:
			{
				start=insert_end(start);
				display(start);
				break;
			}
			case 3:
			{	
				start=insert_pos(start);
				display(start);
				break;
			}
			
			case 4:
			{
				printf("\nEnter the value before which you want to insert the new data :  ");
				scanf("%d",&x);
				start=insert_bef_val(start,x);
				display(start);
				break;
			}
			
			case 5:
			{
				printf("\nEnter the value after which you want to insert the new data :  ");
				scanf("%d",&x);
				start=insert_aft_val(start,x);
				display(start);
				break;
			}	
	
			case 6:
			{
				start=del_first(start);
				display(start);
				break;
			}	
			
			case 7:
			{
				start=del_last(start);
				display(start);
				break;
			}	
			
			case 8:
			{
				start=del_pos_bef(start);
				display(start);		
				break;
			}
			
			case 9:
			{
				start=del_pos_aft(start);
				display(start);
				break;
			}
			
			case 10:
			{		
				m=max(start);
				printf("\n%d is the maximum value",m);
				break;
			}
			
			case 11:
			{
				c=length(start);
				break;
			}
			case 12:
			{
				printf("\nEnter the value that you wish to search : ");
				scanf("%d",&value);
				value = search(start,value);
				if(value == -1)
					printf("\nThe Value Doesn't Exist");
				else	
					printf("\nThe Specific Value lies at %dth position\n",value);
				break;
			}
			case 13:
			{
				printf("\nEnter the value you want to replace");
				scanf("%d",&x);
				printf("\nEnter the new value");
				scanf("%d",&y); 
				replace(start,x,y);
				display(start); 
				break;
			}
			case 14:
			{
				sort_asc(start);
				display(start);
				break;
			}
			
			case 15:
			{
				sort_desc(start);
				display(start);
				break;
		    }
			case 16:
			{
				start=reverse(start);
				display(start);
				break;
			}	
			case 17:
			{
				start=copy(start2);
				display(start);
				break;
			}	               
			case 18:
			{
				start = concate(start , start2);
				display(start);
				break;
			}			
			case 19:
			{
				printf("Enter the value :");
				scanf("%d",&x);
				start = insert_asc(start,x);
				display(start);
				break;
			}	
			default:
			{
				printf("\nWrong Choice.");
				break;
			}
		}
		printf("\nDo you wish to Perform some other Task? Press Y if Yes .");
		scanf("\t%s",&ch1);
	}
	while(ch1=='y' || ch1=='Y');
}

				
	
