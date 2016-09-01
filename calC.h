#include<iostream>
#include<conio.h>
using namespace std;

string test;

class calC
{
	private:

		string strvar;

	public: 

		calC(string str="")
		{
			strvar=str;
			cout<<strvar;
		}
		calC(calC & x)
		{
			strvar=x.strvar;
			cout<<strvar;
		}
		~calC(){}
		
		bool str_grt(string str1,string str2);
		bool str_les(string str1,string str2);
		bool str_eql(string str1,string str2);
		string str_dhz(string str);
		string str_reverse(string str);
		string str_par(int x);
		int int_par(string str);
		
		string numstr_add(string str1,string str2);
		string numstr_sub(string str1,string str2);
		string multi(string str1,int num);
		string numstr_mlt(string str1,string str2);
		string numstr_fct(int num);
		string divi(string *str1,string str2);
		string numstr_dvd(string str1,string str2);
		string numstr_mod(string str1,string str2);
		
		
		friend istream & operator>>(istream &input, calC &x);		// & is for nick name
		friend ostream& operator<<(ostream &output, calC x);
		
		calC operator+(calC &y);
		calC operator-(calC &y);
		calC operator/(calC &y);
		calC operator%(calC &y);
		calC operator*(calC &y);
		friend calC operator!(calC &x);
//		calC operator=(calC &y);
		string operator=(string y);
//		friend string operator=(string x,calC &y);

		string calC2str(calC &x);
		bool d_minus();
		bool i_minus();

				
};


		istream& operator>>(istream &input, calC &x)
		{
			input>>x.strvar;
			return(input);
		}
		
		ostream& operator<<(ostream &output, calC x)
		{
			//output<<x.strvar;
			return(output);
		}

		calC calC :: operator+(calC &y)
		{
			calC z;
			z.strvar = z.numstr_add(strvar,y.strvar);
			return z;
		}

		calC calC :: operator-(calC &y)
		{
			calC z;
			z.strvar = z.numstr_sub(strvar,y.strvar);
			return z;
		}

		calC calC :: operator/(calC &y)
		{
			calC z;
			z.strvar = z.numstr_dvd(strvar,y.strvar);
			return z;
		}

		calC calC :: operator%(calC &y)
		{
			calC z;
			z.strvar = z.numstr_mod(strvar,y.strvar);
			return z;
		}

		calC calC :: operator*(calC &y)
		{
			calC z;
			z.strvar = z.numstr_mlt(strvar,y.strvar);
			return z;
		}

		calC operator!(calC& x)
		{
			calC z;
			int num;
			num=z.int_par(x.strvar);
			z.strvar = z.numstr_fct(num);
			return z;
		}

/*		calC calC :: operator=(calC &y)
		{
			calC z;
			strvar = y.strvar;
			z.strvar = y.strvar;
			return z;
		}
*/		
		string calC :: operator=(string y)
		{
			string z;
			strvar = y;
			z = y;
			return z;
		}

/*		string operator=(string x,calC &y)
		{
			x=y.strvar;
			return x;
		}
*/


		string calC :: calC2str(calC &x)
		{
			string str;
			str=x.strvar;
			return str;
		}

	bool calC :: d_minus()
	{
		calC z;
		if(strvar[0]=='-'||strvar[0]=='~')
		{
			for(int i=1;i<strvar.length();i++)
			{
				z.strvar+=strvar[i];
			}
			strvar=z.strvar;
			return true;
		}
		
		return false;
	}			
	
	bool calC :: i_minus()
	{
		calC z;
		z.strvar='-';
		for(int i=0;i<strvar.length();i++)
		{
			z.strvar+=strvar[i];
		}
		strvar=z.strvar;
		return true;
	}






bool calC :: str_grt(string str1,string str2) //if str1 grt return true
{
	int l1,l2;
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	l1=str1.length();
	l2=str2.length();
	if(l1>l2)
	return true;
	else if(l1<l2)
	return false;
	else
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i]>str2[i])
			return true;
			else if(str1[i]<str2[i])
			return false;
		}
	}
	return false;
}

bool calC :: str_les(string str1,string str2) //if str1 less return true
{
	int l1,l2;
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	l1=str1.length();
	l2=str2.length();
	if(l1<l2)
	return true;
	else if(l1>l2)
	return false;
	else
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i]<str2[i])
			return true;
			else if(str1[i]>str2[i])
			return false;
		}
	}
	return false;
}

bool calC :: str_eql(string str1,string str2)		// if equal return true
{
	int l1,l2;
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	l1=str1.length();
	l2=str2.length();
	if(l1!=l2)
	return false;
	else
	{
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i]!=str2[i])
			return false;
		}
	}
	return true;
}
	

string calC :: str_dhz(string str)		// delete heading zeros
{
	
	
	string temp="";
	int i=0;
/*	if(str[i]=='-')		//neglected
	temp+=str[i++];*/
	while(str[i]=='0')
	i++;
	
	if(i==str.length())
	return "0";
	
	while(i<str.length())
	{
		temp+=str[i];
		i++;
	}
	return temp;
}

string calC :: str_reverse(string str)		//reverses the string
{
	string temp="";
	for(int i=str.length()-1;i>=0;i--)
	{
		temp+=str[i];
	}
	return temp;
}

string calC :: numstr_add(string str1,string str2) 		//Numerical string add
{
	
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	
	str1=str_reverse(str1);
	str2=str_reverse(str2);

	string temp="";
	int max,min,i,c1,c2;		// c1,c2 for carry management
	if(str1.length()>str2.length())
	{
		max=str1.length();
		min=str2.length();
			
		for(c2=0,i=0;i<min;i++)
		{
			c1=str1[i]+str2[i]+c2-48-48;
			temp+=c1%10+48;
			c2=c1/10;
		}
		for(;i<max;i++)
		{
			c1=str1[i]+c2-48;
			temp+=c1%10+48;
			c2=c1/10;
		}
		if(c2!=0)
		{
			temp+=c2+48;
		}
		
	}
	else if(str1.length()<str2.length())
	{
		max=str2.length();
		min=str1.length();
			
		for(c2=0,i=0;i<min;i++)
		{
			c1=str1[i]+str2[i]+c2-48-48;
			temp+=c1%10+48;
			c2=c1/10;
		}
		for(;i<max;i++)
		{
			c1=str2[i]+c2-48;
			temp+=c1%10+48;
			c2=c1/10;
		}
		if(c2!=0)
		{
			temp+=c2+48;
		}
		
	}
	else
	{
		max=str1.length();
			
		for(c2=0,i=0;i<max;i++)
		{
			c1=str1[i]+str2[i]+c2-48-48;
			temp+=c1%10+48;
			c2=c1/10;
		}
		if(c2!=0)
		{
			temp+=c2+48;
		}
		
	}
	temp=str_reverse(temp);
	temp=str_dhz(temp);
	return temp;
}

string calC :: numstr_sub(string str1,string str2) 		//Numerical string sub
{
	
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	
	str1=str_reverse(str1);
	str2=str_reverse(str2);

	string temp="";
	int max,min,i,c1,c2,c3;		// c1,c2,c3 for carry management
	int minus=0;				// if this is set then the answer is negative
	if(str1.length()>str2.length())
	{
		max=str1.length();
		min=str2.length();
			
		for(c2=0,i=0;i<min;i++)
		{
			if(str1[i]>0&&c2>0)
			{
				str1[i]--;
				c2--;
			}		
			if(str1[i]>=str2[i])
			c1=str1[i]-str2[i];
			else
			{
				c1=str1[i]-str2[i]+10;
				c2=1;
			}
			temp+=c1+48;
		}
		for(;i<max;i++)
		{
			if(str1[i]>0&&c2>0)
			{
				str1[i]--;
				c2--;
			}
			c1=str1[i]-48;
			temp+=c1+48;
		}
	}
	else if(str1.length()<str2.length())
	{
		minus=1;
		max=str2.length();
		min=str1.length();
			
		for(c2=0,i=0;i<min;i++)
		{
			if(str2[i]>0&&c2>0)
			{
				str2[i]--;
				c2--;
			}		
			if(str2[i]>=str1[i])
			c1=str2[i]-str1[i];
			else
			{
				c1=str2[i]-str1[i]+10;
				c2=1;
			}
			temp+=c1+48;
		}
		for(;i<max;i++)
		{
			if(str2[i]>0&&c2>0)
			{
				str2[i]--;
				c2--;
			}
			c1=str2[i]-48;
			temp+=c1+48;
		}
	}
	else
	{
		max=str1.length();	
		for(c2=0,i=0;i<max;i++)
		{
			if(str1[i]>0&&c2>0)
			{
				str1[i]--;
				c2--;
			}		
			if(str1[i]>=str2[i])
			c1=str1[i]-str2[i];
			else
			{
				c1=str1[i]-str2[i]+10;
				c2=1;
			}
			temp+=c1+48;
		}
		if(c2)
		{
			minus=1;
			temp[0]=10-(temp[0]-48)+48;
			for(i=1;i<max;i++)
			temp[i]=9-(temp[i]-48)+48;
		}
	}
	
	if(minus)		// to include '-' in answer      	// comment it to stay +ve
	temp+='-';
	
	
	temp=str_reverse(temp);
	temp=str_dhz(temp);
	return temp;
}

string calC :: multi(string str1 , int num)    // string and intiger multiply
{
	int car=0,temp=0,i,j;
	string str;
	str=str1+"0";
	
	for(i=str.length()-1;i>0;i--)
	{
		temp=str[i-1]-48;
		temp=temp*num+car;
		str[i]=temp%10+48;
		car=temp/10;		
	}
	str[0]=car+48;
	return str;
}

string calC :: numstr_mlt(string str1,string str2)		// numerical string multiply
{
	
	str1 = str_dhz(str1);
	str2 = str_dhz(str2);
	
	string str3="";
	int i,j,k,int2,int3,int4,car=0;
//	cin>>str1>>str2;
	for(i=0;i<str1.length()+str2.length();i++)
	{
		str3=str3+"0";
	}
	for(i=str2.length()-1;i>=0;i--)
	{
		string str4;
		int2=str2[i]-48;
		str4=multi(str1,int2);
		for(j=str2.length()-1-i;j>0;j--)
		str4=str4+"0";
//		cout<<str4<<endl;
		k=str3.length()-1;
		for(j=str4.length()-1;j>=0;j--)
		{
			int3=str3[k]-48;
			int4=str4[j]-48;
			int3=int3+int4+car;
			str3[k]=int3%10+48;
			car=int3/10;
			k--;
		}
		str3[k]=car+48;
	}
	
	/*if(str3[0]!='0')
	cout<<str3;
	else
	{
			for(i=1;i<str3.length();i++)
			cout<<str3[i];
	}
	*/
	
	str3=str_dhz(str3);
	return str3;
}

string calC :: numstr_fct(int num) 		// numerical string factorial
{
	int i,j,k;
	int ex,r=0,top=0;
	string str="1";
//	cin>>num;
	i=1;
	j=1;
	while(i<=num)
	{
		j=j*i;

		k=0;
		r=0;
		while(k<=top)
	{
		ex=str[k]-48;
		ex=ex*i+r;
		str[k]=ex%10+48;
		r=ex/10;
		k++;
	}
		while(r>0)
	{
		top++;
		str=str+(char)(r%10+48);
		r=r/10;
	}

		i++;
	}	
	str=str_reverse(str);
//	for(i=top;i>=0;i--)
//	cout<<str[i];
	return str;
}



string calC :: divi(string *str1,string str2) 		//returning qutionent with range: 1-9, str1>str2;       also modifies the divident to remainder
{
	*str1 = str_dhz(*str1);
	str2 = str_dhz(str2);

	int i;
	string str3="",str4=str2,ans="";
	if(str_eql(*str1,str2))
	{
		*str1="0";
		ans="1";
		return ans;
	}
	
	if(str_les(*str1,str2))		// hardly reqd.
	{
		ans="0";
		return ans;
	}
	
	
	
	for(i=1;i<=9;i++)
	{
		str3=numstr_add(str4,str2);
		if(str_grt(str3,*str1))
		{
			*str1=numstr_sub(*str1,str4);
			ans+=i+48;
			return ans;
		}
		str4=str3;
	}
	
	*str1=numstr_sub(*str1,str4);		//must never execute: because returning 10
	ans+=i+48;
	return ans;
}
	
string calC :: numstr_dvd(string str1,string str2)//for overload,string *rem=NULL)		//	str1/str2
{
	if(str2=="0")
	{
		cout<<"UNABLE TO DIVIDE BY 0";
		return "0";
	}
	int i,l1,l2,l3;
	string str,str3,str4;
	l1=str1.length();
	l2=str2.length();
	l3=l1;
	
	if(l1<l2)
	{
//	cout<<"\n rem:"<<str1<<endl;   // print remainder
	//*rem=str1;
		return "0";
	}
	if(l1==l2&&str_les(str1,str2))
	{
//	cout<<"\n rem:"<<str1<<endl;   // print remainder
	//*rem=str1;
		return "0";	
	}
	if(l1==l2&&str_eql(str1,str2))
	{
		str = divi(&str1,str2);
//	cout<<"\n rem:"<<str1<<endl;   // print remainder
	//*rem=str1;

		return str;
	}

	str3="";str="0";
	for(i=0;i<l2;i++)
	{
		str3+=str1[i];
		l3--;
	}
	if(str_les(str3,str2)&&l1>l2)
	{
		str3+=str1[i++];
		l3--;
	}
	while(l3+1)
	{
		str += divi(&str3,str2);
		int carry=0;
		
		if(!l3)
		break;
		
		while(str_les(str3,str2)&&l3>0)
		{
			str3+=str1[i++];
			l3--;
			if(carry++)
			{
				str+="0";
			}
		}
	}
//	cout<<"\n rem:"<<str3<<endl;   // print remainder
	//*rem=str3;
	str = str_dhz(str);
	return str;
}


	
string calC :: numstr_mod(string str1,string str2)
{
	if(str2=="0")
	{
		cout<<"UNABLE TO DIVIDE BY 0";
		return "0";
	}
	int i,l1,l2,l3;
	string str,str3,str4;
	l1=str1.length();
	l2=str2.length();
	l3=l1;
	
	if(l1<l2)
	{
		return str1;
	}
	if(l1==l2&&str_les(str1,str2))
	{
		return str1;	
	}
	if(l1==l2&&str_eql(str1,str2))
	{
		str = divi(&str1,str2);
		return str1;
	}

	str3="";str="0";
	for(i=0;i<l2;i++)
	{
		str3+=str1[i];
		l3--;
	}
	if(str_les(str3,str2)&&l1>l2)
	{
		str3+=str1[i++];
		l3--;
	}
	while(l3+1)
	{
		str += divi(&str3,str2);
		int carry=0;
		
		if(!l3)
		break;
		
		while(str_les(str3,str2)&&l3>0)
		{
			str3+=str1[i++];
			l3--;
			if(carry++)
			{
				str+="0";
			}
		}
	}
	
	str3 = str_dhz(str3);
	return str3;
}




string calC :: str_par(int x)
{
	int r;
	string s;
	if(!x)
	s="0";
	while(x)
	{
		r=x%10;
		x=x/10;
		s+=r+48;
	}
	
	s=str_reverse(s);
	return s;
}


int calC :: int_par(string str)
{
	int x=0;
	for(int i=0;i<str.length();i++)
	{
		x=x*10+(str[0]-48);
	}
	return x;
}


