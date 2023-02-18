#include<iostream>
#include<string>
using namespace std;
// I want to make a program to a company for calculating salary, name, deisgnation and length of code.
struct employe{
	string name;
	int salary;
	string desig;
};
int length=0;
void initial(int n, struct employe **data_arr){//pointer points to pointer that points to structure.
	cout<<"----------- Loading ----------"<<endl;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]: "<<"Enter the name of employe: ";cin>>data_arr[i]->name;cout<<endl;
		cout<<"Enter the designation of employe: ";cin>>data_arr[i]->desig;
		cout<<"Enter the salary of employe: ";cin>>data_arr[i]->salary;
		cout<<endl;
	}
	cout<<"---------- Please Wait ----------"<<endl;
	length =length +1;
	cout<<endl;
	return;
}
void sort(int n, struct employe **data_arr){
	cout<<"---------- Alphabetized order ----------"<<endl;// data_arr 0 location and next location and points to employe structure with a and b.
	sort(data_arr, data_arr +n, [](employe *a, employe *b){// sorting in accordance to their designations.
		return a->desig<b->desig;
	});
	return;
}
// printing function
void printing(int n, struct employe **data_arr){
	cout<<"---------- Loading -----------"<<endl;
	cout<<endl<<"---------- Recorded Data -----------"<<endl;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]: "<<"Name: "<<data_arr[i]->name<<" Salary: "<<data_arr[i]->salary<<" Designation: "<<data_arr[i]->desig<<endl;
	}
	cout<<endl;
	length =length +1;
}

int main (){
	int n;
	cout<<"Enter the number of person's data that you want to store in structure: ";
	cin>>n;cout<<endl;
	employe arr[n];// array of structure
	employe *ptr_arr[n];// pointer array points to structure. 
	for(int i=0;i<n;i++){
		ptr_arr[i]=new employe;// new pointer structure & new multiples dynamic memory alocations.
	}
	cout<<endl;
	initial(n,ptr_arr);// calling with orignal ptr_arr[] instead of data_arr[]. 
	//sort(n,ptr_arr);
	printing(n,ptr_arr);
	cout<<"Length of Function: "<<length<<endl;
	for(int i=0;i<n;i++){
		delete ptr_arr[i];
	}
	return 0;
}
