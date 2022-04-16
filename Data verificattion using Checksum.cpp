#include <iostream>  
#include <cmath>
#include <conio.h>
#include <iomanip> 
#include <cstring> 																					 

using namespace std;																			

class checksum
{
    public:  																							    
        
		int k;										//sum of all even array elements
		int l;										//sum of all even array elements	
        int n; 										//length of string.
        long A[];									//Array to store ASCII codes

		int ToASCII(string s);
		void length(string s);
		long SumArr(string s);    
		
};

checksum ob1,ob2;									//global class objects

void checksum:: length(string s)  					//To find the length of the input
{
    n=s.length();            																			
}

int checksum::ToASCII(string S)						//To get ASCII code of each character as separate array elements
{
    char a;                    	
    for(int i=0; i<n; i++)    																		
    {
        a=S.at(i);             																			
        A[i]=a;
    }
	return A[n];
}

long checksum:: SumArr(string s)					
{
    k=0;
    for(int i=0; i<n ;i+=2) 				 		//To add all even array elements	
    {
        k=k+A[i];           						// A[0]+A[2]+A[4]+...+A[n]
    }                         
    l=0;
    for(int j=1; j<n; j+=2)							//To add all odd array elements
    {
        l=l+A[j];									// A[1]+A[3]+A[5]+...+A[n-1]
    }
    return k,l;           							//return both sums													
}

int main() 
{
	cout<<"\n\n\t\t\t\t Hexadecimal Checksum Method \t\t"<<endl;
	cout<<"\t\t\t\t ---------------------------\n";
		
	cout<<"\n\t\tAt Sender Side"<<endl;
	cout<<"\t\t--------------\n\n";
	cout<<"Enter a message code : ";

	string s; 																						
	getline(cin, s);								//Read the string from user
		
	ob1.length(s);									//To calculate length of string
	ob1.ToASCII(s); 								//Assinging ASCII codes to characters 
	ob1.SumArr(s);									//To find the values of k & l 

	if(ob1.l>255)
	{
		ob1.k=ob1.k+ob1.l/256;						// checksum algorithm.
		ob1.l=ob1.l%256;  							//make sum operation
		if(ob1.k>255)
		{
			ob1.l=ob1.l+ob1.k/256;
			ob1.k=ob1.k%256;
		}
	}
	else if(ob1.k>255)
	{  
			ob1.l=ob1.l+ob1.k/256;
			ob1.k=ob1.k%256;
	}
 
	int a=ob1.k;
	int b=ob1.l;
	
	//Printing Checksum
	cout<<hex<<endl<<"Sum code at sender side: "<<ob1.k<<ob1.l<<endl;		
	cout<<"Checksum code at sender side: "<<255-ob1.k<<255-ob1.l<<endl<<endl;
    
	//Reciever's Side 
    
	ob2.k=a+(255-ob1.k);
	ob2.l=b+(255-ob1.l);
 	
	if(ob2.l>255)
	{
		ob2.k=ob2.k+ob2.l/256;
		ob2.l=ob2.l%256;
		if(ob2.k>255)
		{
			ob2.l=ob2.l+ob2.k/256;
			ob2.k=ob2.k%256;
	    }
	}
	else if(ob2.k>255)
	{
		ob2.l=ob2.l+ob2.k/256;
		ob2.k=ob2.k%256;
	}	
	cout<<"\n\n\t\tReceiver Side"<<endl;
	cout<<"\t\t-------------\n\n";
	//Printing checksum on reciever's side
	cout<<hex<<"Sum code at receiver side: "<<ob2.k<<ob2.l<<endl;
	cout<<"Checksum code at sender reciver: "<<255-ob2.k<<255-ob2.l<<endl<<endl;
	
    if((255-ob2.k)==0 && (255-ob2.l)==0)				//Acknowledgement acc to Checksum value				
        cout<<endl<<"\nChecksum is zero\n\nData Accepted  !!!"<<endl;		
    else                                								 
        cout<<endl<<"\nChecksum is not Zero.\n\nData Discarded !!!"<<endl;
    return 0;
 }
