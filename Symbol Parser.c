#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Variable
{
	char name[10], type[10], value[10];
}v[10];
 
int isKeyword(char c[])
{
	int i;
	if((strcmp("int\n",c)==0) || (strcmp("float\n",c)==0) || (strcmp("char\n",c)==0))
		return 1;
	else
		return 0;
}

int isIdentifier(char ch1[])
{
	char ch[10];
	int j;
	for(j=0;j<strlen(ch1)-1;j++)
		ch[j] = ch1[j];
		
	if((ch[0]>='a' && ch[0]<='z') || ch[0]=='_')
	{
		int z= isKeyword(ch);
		int l=strlen(ch);
		int i,flag=0;
		for(i=0;i<l;i++)
		{
			if((ch[i]>='a' && ch[i]<='z') || (ch[i]=='_') || (ch[i]>='0' && ch[i]<='9'))	
				flag=0;
			else
				flag=1;	
		}
		if(flag==0 && z==0)
			return 1;	
		else
			return 0;			
	}
	else
		return 0;
}

int isConstant(char ch1[])
{
	int l=strlen(ch1),i,flag=0,j;
	char ch[10];
	for(j=0;j<strlen(ch1)-1;j++)
		ch[j] = ch1[j];
	for(i=0;i<l-1;i++)
	{
		if(ch[i]>='0' && ch[i]<='9')		
			flag=0;
		else
			flag=1;	
	}
	if(flag==0)
		return 1;
	else
		return 0;	
}

int isChar(char c[])
{
	if(c[0] == '\'' && c[2] == '\'')
		if(isalpha(c[1]))
			return 1;
	else
		return 0;
}

int isOperator(char c[])
{
	if((strcmp("+\n",c)==0) || (strcmp("=\n",c)==0) || (strcmp("-\n",c)==0) || (strcmp("*\n",c)==0))
		return 1;
	else
		return 0;
}

int getSymbol(char c[])
{
	char ch[10];
	int i, j = -1, k,p;
	
	for(k=0;k<strlen(c)-1;k++)
		ch[k] = c[k];
	for(p=k;p<10;p++)
		ch[p] = '\0';
		
	for(i=0;i<10;i++)
	{
		if(strcmp(ch,v[i].name) == 0)
		{
			j = i;
			break;
		}
	}	
	return j; 
}

int isDoubleOperator(char c[])
{
	if((strcmp("+=\n",c)==0) || (strcmp("-=\n",c)==0) || (strcmp("*=\n",c)==0) || (strcmp("/=\n",c)==0))
		return 1;
	else
		return 0;
}

main()
{
	int i = 0, j = 0, k, id, con, op1, dop, l, z = 0, p, ch, sym, sym1, sym2;
	char input[500], *t, fc[10], c[10], temp[5], idtemp[5], vtemp[4], test[5];
	char* op = " ,\n\t";
	FILE *in, *out;
	
	in = fopen("woe.c","r");
	out = fopen("tokens.txt","w");
	
	while(!feof(in))
	{
		input[i] = fgetc(in);
		i++;
	}
	
	t = strtok(input,op);	

	while(t != NULL)
	{
		fprintf(out,"%s\n",t);
		t = strtok(NULL,op);
	}
	
	fclose(in);
	fclose(out);
	
	in = fopen("tokens.txt","r");
	while(!feof(in))
	{
		fgets(fc,50,in);	
		k = isKeyword(fc);
		id = isIdentifier(fc);
			
		if(k == 1)
		{
			strcpy(temp,"");
			for(j=0;j<strlen(fc)-1;j++)
				temp[j] = fc[j];
			for(p=j;p<5;p++)
				temp[p] = '\0';	
			fgets(fc,50,in);
			id = isIdentifier(fc);
			
			if(id == 1)
			{
				iden:
				strcpy(idtemp,"");	
				for(j=0;j<strlen(fc)-1;j++)
					idtemp[j] = fc[j];
				for(p=j;p<5;p++)
					idtemp[p] = '\0';	
				fgets(fc,50,in);
			
				if(strcmp(fc,";\n") == 0)
				{
					strcpy(v[z].name,idtemp);
					strcpy(v[z].type,temp);
					strcpy(v[z].value,"");
					z++; 
				}
				else if(strcmp(fc,"=\n") == 0)
				{
					strcpy(v[z].name,idtemp);
					strcpy(v[z].type,temp);
					
					fgets(fc,10,in);
					
					con = isConstant(fc);
					ch = isChar(fc);
					
					if(con == 1)
					{
						strcpy(vtemp,"");
						for(j=0;j<strlen(fc)-1;j++)
							vtemp[j] = fc[j];
						for(p=j;p<4;p++)
							vtemp[p] = '\0';	
						strcpy(v[z].value,vtemp);
						
						fgets(fc,20,in);
						z++;
						if((id = isIdentifier(fc)) == 1)
							goto iden;		
					}	
					
					if(ch == 1)
					{
						strcpy(vtemp,"");
						vtemp[0] = fc[1];
						for(p=1;p<4;p++)
							vtemp[p] = '\0';	
						strcpy(v[z].value,vtemp);
						
						fgets(fc,20,in);
						z++;
						if((id = isIdentifier(fc)) == 1)
							goto iden;	
					}	 	
				}
				
				else if((id=isIdentifier(fc)) == 1)
				{
					strcpy(v[z].name,idtemp);
					strcpy(v[z].type,temp); 
					z++;
					goto iden;		
				}
			}
			
		}
		
		else if(id == 1)
		{
			sym = getSymbol(fc);
			fgets(fc,50,in);
			dop = isDoubleOperator(fc);
			if(strcmp(fc,"=\n") == 0)
			{
				fgets(fc,50,in);
				id = isIdentifier(fc);
				con = isConstant(fc);
				ch = isChar(fc);
				
				if(id == 1)
				{
					sym1 = getSymbol(fc);
					if(strcmp(v[sym].type,v[sym1].type)!=0)
						printf("\n\n\tERROR! Type Mismatch :- %s(%s) and %s(%s) do not have the same data type.",v[sym].name,v[sym].type,v[sym1].name,v[sym1].type);
					
					fgets(fc,50,in);
					op1	= isOperator(fc);
					
					if(op1 == 1)
					{
						fgets(fc,50,in);
						id = isIdentifier(fc);
						ch = isChar(fc);
						if(id==1)
						{
							sym2 = getSymbol(fc);
							if(strcmp(v[sym].type,v[sym2].type)!=0)
								printf("\n\n\tERROR! Type Mismatch :- %s(%s) and %s(%s) do not have the same data type.",v[sym].name,v[sym].type,v[sym2].name,v[sym2].type);
							
						}
		
						if(ch == 1)
						{
							if(strcmp(v[sym].type,"char")!=0 || strcmp(v[sym1].type,"char")!=0)
								printf("\n\n\tERROR! Type Mismatch :- %s(%s) , %s(%s) and %c(char constant) do not have same data type.",v[sym].name,v[sym].type,v[sym1].name,v[sym1].type,fc[1]);
								
						}
						fgets(fc,50,in);
					}
				}	
			}
				
			else if(dop == 1)
			{
				fgets(fc,50,in);
				id = isIdentifier(fc);
				con = isConstant(fc);
				ch = isChar(fc);
				
				if(id==1)
				{
					sym1 = getSymbol(fc);
					if(strcmp(v[sym].type,v[sym1].type)!=0)
						printf("\n\n\tERROR! Type Mismatch :- %s(%s) , %s(%s) do not have same data type.",v[sym].name,v[sym].type,v[sym1].name,v[sym1].type);
				}
				else if(ch==1)
				{
					if(strcmp(v[sym].type,"char")!=0)
						printf("\n\n\tERROR! Type Mismatch :- %s(%s) and %c(char constant) do not have same data type.",v[sym].name,v[sym].type,fc[1]);
				}
			}
		}
	}
	printf("\n\n\t\t\t-----------------------------------\n");
	printf("\t\t\t\t    Symbol Table\n");
	printf("\t\t\t-----------------------------------\n");
	printf("\n\t\t\t\tID\tType\tValue\n");
	for(i=0;i<z;i++)
		printf("\n\t\t\t\t%s\t%s\t%s",v[i].name,v[i].type,v[i].value);
	printf("\n\t\t\t-----------------------------------\n\n");	
}
