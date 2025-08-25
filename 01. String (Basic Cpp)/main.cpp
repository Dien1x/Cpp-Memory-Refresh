#include <iostream>
using namespace std;
#include <cstring>
#include "STRING.h"

int main() {

	char str[80]="This is a string";
	STRING str1(str);
	STRING str2;
	str2=str1;
	strcpy(str, "This is a new string");
	str1.set_string(str);
	cout<<str1;
	cout<<str2;
	STRING str3;
	str3="Hello World";
	cout<<str3;
	str3="Hello World";
	cout<<(strcmp(str3.get_string(), "Hello World")==0)<<endl;
	cout<<str3;
	str3[4]='z';
	cout<<str3;

	str1==str1 ? cout<<"true"<<endl : cout<<"false"<<endl;

	cout<<str1;
	
	for(int i=0; i<10;i++){
	    str1+='+';
	};
	
	cout<<str1;
	
	STRING str4 = str1 + str3;
	
	cout<<str4;

	cin>>str1;
	cout<<str1;

	cout<<STRING::get_max_length()<<endl;

	STRING::max_length = 47;

	cout<<STRING::get_max_length()<<endl;

	return 0;
};