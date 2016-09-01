#include"calC.h"
#include<fstream>

/*  individual Functions for calculator*/


void calC2file(calC x)
{
	string str;
	str=x.calC2str(x);
	fstream result;
	result.open("output.txt",ios::out);
	result<<str;
	result.close();
}



string* in2post(string q,int *pj=0)
{
	
	string *p,*stack;
	int top=-1,i,j=0;
//	cin>>q;
	p = new string[q.length()];
	stack = new string[q.length()];
	
	top++;
	stack[top]="(";	
	q+=")";
	
	for(i=0;i<q.length();i++)
	{
		bool flgj=false;
		while(q[i]!='+'&&q[i]!='-'&&q[i]!='/'&&q[i]!='%'&&q[i]!='*'&&q[i]!='!'&&q[i]!='('&&q[i]!=')')
		{
			flgj=true;
			p[j]+=q[i];			
			if(++i>=q.length())	
			break;
		}
		if(flgj)
		j++;
		if(i>=q.length())	
		break;
		
		if(q[i]=='(')
		{
			top++;
			stack[top]='(';	
			continue;
		}
		
		if(q[i]=='+'||q[i]=='-'||q[i]=='/'||q[i]=='%'||q[i]=='*'||q[i]=='!')
		{
			if(q[i]=='!')
			{
				while(stack[top]=="!"&&top!=-1)
				{
					p[j++]=stack[top--];	
				}
				top++;
				stack[top]=q[i];
				continue;
			}
			else if(q[i]=='/'||q[i]=='%'||q[i]=='*')
			{
				while((stack[top]=="/"||stack[top]=="%"||stack[top]=="*"||stack[top]=="!")&&(top!=-1))
				{
					p[j++]=stack[top--];	
				}
				top++;
				stack[top]=q[i];
				continue;
			}
			else if(q[i]=='+'||q[i]=='-')
			{
				while(top!=-1&&(stack[top]=="+"||stack[top]=="-"||stack[top]=="/"||stack[top]=="%"||stack[top]=="*"||stack[top]=="!"))
				{
					p[j++]=stack[top--];	
				}
				top++;
				stack[top]=q[i];
				continue;
			}
		}
		
		if(q[i]==')')
		{
			while(stack[top]!="("&&top!=-1)
			{
				p[j++]=stack[top--];
			}
			if(stack[top]=="(")
			{
				top--;
			}
			continue;
		}
		
		cout<<"??????????????????";
		
	}
	
/*	for(i=0;i<j;i++)
	{
		cout<<p[i]<<endl;	
	}
*/
	*pj=j;
	return p;
}


calC calculate(calC x)// calculate polish notation
{
	int i,j=0;
	string tempq,q,*p;
	tempq=x.calC2str(x);
	q="";

	for(i=0;i<tempq.length();i++)	//take care of factorial
	{
		if(tempq[i]=='!')
		{
			q+=tempq[i];
			q+="akshat";//for fact operator
		}
		else
		q+=tempq[i];
	}

	tempq=q;	//take care of negative number
	q="";
	i=0;
	if(tempq[i]=='-')
	{
		q+="~";
		i++;
	}
	for(;i<tempq.length();i++)
	{
		if(tempq[i]=='('&&tempq[i+1]=='-')
		{
			q+=tempq[i];
			i++;
			q+="~";
		}
		else
		q+=tempq[i];
	}	//take care of negative number
	
	p=in2post(q,&j);

	calC *stack;
	int top=0;
	stack = new calC[j];
	
//	p[j++]=")";
	
	calC temp1,temp2,temp3;
	bool  m1,m2,m3;			//to take care of negative results
	for(i=0;i<j;i++)
	{
		if(p[i]!="+"&&p[i]!="-"&&p[i]!="/"&&p[i]!="%"&&p[i]!="*"&&p[i]!="!"&&p[i]!="("&&p[i]!=")")
		{
			stack[top++]=p[i];
		}
		else
		{
			temp1=stack[--top];
			temp2=stack[--top];

			m1=temp1.d_minus();
			m2=temp2.d_minus();
			switch(p[i][0])
			{
				case '+' : 	if(!m1&&!m2)
							temp3=temp2+temp1;
							else if(m1&&m2)
							{
								temp3=temp2+temp1;
								m3=temp3.i_minus();
							}
							else if(m1)
							temp3=temp2-temp1;
							else
							temp3=temp1-temp2;
												
							stack[top++]=temp3;
							break;
				
				case '-' : 	if(!m1&&!m2)
							temp3=temp2-temp1;
							else if(m1&&m2)
							temp3=temp1-temp2;
							else if(m1)
							temp3=temp2+temp1;
							else
							{
								temp3=temp2+temp1;
								m3=temp3.i_minus();
							}
							
							stack[top++]=temp3;
							break;

				case '/' : 	temp3=temp2/temp1;
				
							if(m1&&m2);		//do nothing
							else if(m1||m2)
							m3=temp3.i_minus();
							
							stack[top++]=temp3;
							break;

				case '%' : 	temp3=temp2%temp1;
				
							if(m1&&m2);		//do nothing
							else if(m1||m2)
							m3=temp3.i_minus();
							
							stack[top++]=temp3;
							break;

				case '*' : 	temp3=temp2*temp1;
				
							if(m1&&m2);		//do nothing
							else if(m1||m2)
							m3=temp3.i_minus();
							
							stack[top++]=temp3;
							break;

				case '!' : 	temp3=!temp2;
				
							if(m2)		//do something
							cout<<"Factorial of a Negative not possible";
							
							stack[top++]=temp3;
							break;
				default : 	cout<<"check error"<<endl;	
				
			}
		}
		
			
	}	

	calC ans;
	ans=stack[--top];
	
	return ans;
}

