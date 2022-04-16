//To implement next fit algorithm for memory allocation

#include <stdio.h>
#include <stdlib.h>

typedef struct LL							//Declaration of Link-List
{
	int memory,alc;							//memory - total size of partition
	char oc,pn;								//alc - allocated memory in partition
	struct LL *next;						//oc - Occupied/Unoccupied		pn - Process name
}node;

node* getNode()								//To get an empty node
{
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->next = NULL;
	return tmp;
}

node* create()								//To create a partition
{
 	node *start,*trv,*new1;
 	char c;
	start = NULL;
 	trv = start;
 	do
 	{
 		new1 = getNode();
  		new1->alc = 0;
  		new1->oc = 'U';
  		new1->pn = '$';
  		
		printf("\nEnter the size of partition(Mb) : ");
		scanf("%d",&new1->memory);
 		
		if(start == NULL)
  		{
   			start = new1;
  	 		new1->next = start;
   			trv = start;
 		}
  		
		else
  		{
   			trv->next = new1;
  			new1->next = start;
   			trv = new1;
 		}
		
		printf("Do you want to continue(Y/N)? : ");
  		scanf(" %c",&c);
	}while(c == 'Y' || c == 'y');
 	
 	
 	
 	
	 return start;
}

void display(node *start)						//To display all Partitions
{
 	node *trv;
 	trv = start;
 	
	if(start == NULL)
 		printf("\nNo Memory Available!");
 	
	else
 	{

 		printf("\nPartition Structure : |Process Name|Occupancy(U/O)|Allocated Memory|Free space|\n");
  		printf("\nMemory Partition");
  		printf("\n----------------\n\n");
		do
  		{
  			if(trv->next != start)
				printf("|%c|%c|%d|%d|---> ",trv->pn,trv->oc,trv->alc,trv->memory);		
   			else
   				printf("|%c|%c|%d|%d| ",trv->pn,trv->oc,trv->alc,trv->memory);
   			trv = trv->next;
  		}while(trv != start);
 	}
}

node* alloc(node *start,int c,char x)				//To Allocate memory space to a process
{
	int a=0,flag=0;
	node *trv,*tmp;
	trv = start;
	do
	{
		if(c > (trv->memory))
		{
			trv = trv->next;
			a = 0;
		}
					
		else
		{
			trv->alc = c;
			trv->oc = 'O';
			
			tmp = getNode();
			tmp->memory = (trv->memory) - (trv->alc);
			tmp->alc = 0;
			tmp->oc = 'U';
			tmp->pn = '$';
	
			tmp->next = trv->next;
			trv->next = tmp;
			trv->memory = 0;
			trv->pn = x;
			a = 1;
		}
		
		if(trv==start)
		{
			flag=1;
		}
	}while(a==0 && flag==0);
	trv = trv->next;
	
	if(a == 1)
		printf("\nMemory Allocated.");	
	else if(flag==1)
		printf("\nMemory not Allocated\nNo free space\n");

	return trv;
}

node *dealloc(node *start,char c)					//To Deallocate a process from the partition
{
	int found=0,flag=0;
	node *trv,*prev;
	trv = start;
	prev = start;
	do
	{
		if((trv->next)->pn != c)
		{	
			trv=trv->next;
			prev=prev->next;
		}
		else
		{		
			trv=trv->next;
			prev->memory = (prev->memory + trv->alc);
			prev->next = trv->next;
			trv->next = NULL;
			free(trv);
			found = 1;
		}
		
		if(prev==start)
		{
			found=1;
			flag=1;
		}
			
	}while(found != 1);
	if(flag==0 && found==1)
		printf("\nMemory Deallocated\n");
	else if(flag==1 && found==1)
		printf("\nNo Such Process Exists\n");			
	return prev;
}

main()
{
	int mmry,ch;
	char c;
	node *start,*s;
	printf("-----------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tMemory Allocation Using Next fit Algorithm\n");
	printf("-----------------------------------------------------------------------------------------------------------\n\n");
	printf("Create the partitions \n");
	printf("---------------------\n");
	start = create();
	s = start;
	
	menu :
		printf("\n\n-----------------------------------");
		printf("\n\t\tMenu\n");
		printf("-----------------------------------\n");
		printf("\n1.Allocate Memory \n2.Deallocate Memory \n3.Display \n4.Exit \n \nChoice : ");
		scanf("%d",&ch);
		printf("\n-----------------------------------\n");
		
		if(ch == 1)
		{
			printf("\nEnter process name : ");
			scanf(" %c",&c);
			printf("Enter the size of process(Mb) : ");
			scanf("%d",&mmry);
			start = alloc(start,mmry,c);
			goto menu;
		}

		else if(ch == 2)
		{
			printf("\nEnter the name of process : ");
			scanf(" %c",&c);
			start = dealloc(start,c);
			goto menu;
		}
	
		else if(ch == 3)
		{
			display(s);
			goto menu;
		}
		
		else
				exit(0);
}


