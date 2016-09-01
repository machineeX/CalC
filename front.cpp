#include"calculator.h"
#include<fstream>



int main()
{
	cout<<"\n";
	cout<<"Welcome to 'calC - The no limit calculator'"<<endl<<endl;
	cout<<"Operators presently available: \n\n\t\t+(addition) \n\t\t-(substraction) \n\t\t/(division) \n\t\t%(remainder) \n\t\t*(multiply) \n\t\t!(factorial)"<<endl<<endl;
	calC expression,answer;
	cout<<"Enter Expression to calculate: ";
	cin>>expression;
	answer=calculate(expression);
	calC2file(answer);
	system("cls");
	cout<<"The Expression: ";
	cout<<expression<<endl;
	cout<<"Calculates to: ";
	cout<<answer<<endl;
	cout<<"Answer Written in file: output.txt";
	getch();
	return 0;
}
