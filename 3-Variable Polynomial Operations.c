// To Add and Subtract 2 Polynomials of any no of variables of any order //

#include<stdio.h>
#include<stdlib.h>


typedef struct Poly
{
	int co,ex;																						// co - co-efficient      ex - exponent      var - variable 
	char var;
	struct Poly *next;
}node;

node* getnode()
{
	node* tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp -> next = NULL;
	return tmp;
}

node* create(int n)
{
	node *start,*trv,*new;
	char var1,var2,var3;
	start = NULL;
	trv=start;
	int i=n;
	printf("\nEnter the 1st variable : ");
	scanf("%s",&var1);
	for(i=n;i>0;i--)
	{
		new = getnode();
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
		trv->var = var1;
		trv->ex = i ;
		printf("Enter the co-efficient for the term %c^%d : ",trv->var,trv->ex);
		scanf("%d",&trv->co);
	}
	i = n;
	printf("\nEnter the 2nd variable : ");
	scanf("%s",&var2);
	for(i=n;i>0;i--)
	{
		new = getnode();
		trv->next=new;
		trv = new;
		trv->var = var2;
		trv->ex = i ;
		printf("Enter the co-efficient for the term %c^%d : ",trv->var,trv->ex);
		scanf("%d",&trv->co);
		
	}
	i = n;
	printf("\nEnter the 3rd variable : ");
	scanf("%s",&var3);
	for(i=n;i>0;i--)
	{
		new = getnode();
		trv->next=new;
		trv = new;
		trv->var = var3;
		trv->ex = i ;
		printf("Enter the co-efficient for the term %c^%d : ",trv->var,trv->ex);
		scanf("%d",&trv->co);
		
	}
	new=getnode();
	trv->next=new;
	trv = new;
	printf("\nEnter the constant term : ");
	scanf("%d",&trv->co);
	trv->var = 'x';
	trv -> ex = 0;	
	return start;
}	

void display(node *start)
{
	node* trv;
	trv=start;
	while(trv != NULL)
	{
		if(trv->co != 0)
		{
			if(trv->next != NULL)
			{
				
				if(trv->ex == 0)
				{
					printf(" %d +",trv->co);
				}
				else if(trv->co == 1 && trv ->ex == 1)
				{
					printf(" %c +",trv->var);
				}
				else if(trv->ex == 1)
				{
					printf(" %d%c +",trv->co,trv->var);
				}
				else if(trv->co == 1)
				{
					printf(" %c^%d +",trv->var,trv->ex);
				}
				else
				{
					printf(" %d%c^%d +",trv->co,trv->var,trv->ex);
				}	
			}
			else
			{
				if(trv->ex == 0)
				{
					printf(" %d",trv->co);
				}
				else if(trv->co == 1 && trv ->ex == 1)
				{
					printf(" %c +",trv->var);
				}
				else if(trv->ex == 1)
				{
					printf(" %d%c",trv->co,trv->var);
				}
				else if(trv->co == 1)
				{
					printf(" %c^%d + ",trv->var,trv->ex);
				}
				else
				{
					printf(" %d%c^%d",trv->co,trv->var,trv->ex);
				}
			}
			trv = trv ->next;
		}
		else
		{
			trv = trv ->next;
		}
	}
	printf(" = 0");
}


node* add(node *start,node *start1)
{
	node *trv,*trv1,*trv2,*start2,*new;
	trv=start;
	trv1=start1;
	start2 = NULL;
	trv2 = start2;
	do
	{
		new=getnode();
		if(start2==NULL)
		{
			start2=new;
			trv2=new;
		}	
		else
		{
			trv2->next=new;
			trv2 = new;
		}
		if(trv->var == trv1 ->var && trv->ex == trv1->ex)
		{
			trv2->co = trv1->co + trv->co;
			trv2->var = trv1->var;
			trv2->ex = trv1 ->ex;
		}
		trv = trv->next;
		trv1 = trv1->next;
	}while(trv != NULL);
	return start2;
}

node* subtract(node *start,node *start1)
{
	node *trv,*trv1,*trv2,*start2,*new;
	trv=start;
	trv1=start1;
	start2 = NULL;
	trv2 = start2;
	do
	{
		new=getnode();
		if(start2==NULL)
		{
			start2=new;
			trv2=new;
		}	
		else
		{
			trv2->next=new;
			trv2 = new;
		}
		if(trv->var == trv1->var && trv->ex == trv1->ex)
		{
			trv2->co = trv->co - trv1->co;
			trv2->var = trv1->var;
			trv2->ex = trv1 ->ex;
		}
		trv = trv->next;
		trv1 = trv1->next;
	}while(trv != NULL);
	return start2;
}


main()
{
	node *start,*start1,*start2;
	int ch,n;
	char ch1;
	printf("Enter the order of your Polynomials: ");
	scanf("%d",&n);
	printf("Enter the 1st Polynomial\n");
	printf("------------------------\n");
	start=create(n);
	printf("\nYour Polynomial is : \n");
	display(start);
	printf("\n\nEnter the 2nd Polynomial\n");
	printf("------------------------\n");
	start1=create(n);
	printf("\nYour Polynomial is : \n");
	display(start1);
	do
	{
		printf("\n\nEnter");
		printf("\n1-->Add the two Polynomials");
		printf("\n2-->Subtract the two Polynomials");
		printf("\nChoice : ");
		scanf("%d",&ch);
		printf("\n\n");
		if(ch == 1)
		{
			start2 = add(start,start1);
			display(start);
			printf("\n");
			display(start1);
			printf("\n------------------------------------------------------------------------------\n");
			display(start2);
			printf("\n------------------------------------------------------------------------------\n");		
		}
		else if(ch==2)
		{
			start2 = subtract(start,start1);
			display(start);
			printf("\n");
			display(start1);
			printf("\n------------------------------------------------------------------------------\n");
			display(start2);
			printf("\n------------------------------------------------------------------------------\n");		
		}	
		printf("\n\nPress Y to continue : ");
		scanf("%s",&ch1);
	}while(ch1 == 'y' || ch1 == 'Y');
}		

