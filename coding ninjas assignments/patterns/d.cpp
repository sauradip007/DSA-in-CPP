#include<iostream>
using namespace std;
int main()
{
  	int basic;
    cin>>basic;
    char grade;
    cin>>grade;
    
    int allow;
    double hra,da,pf, total;
    hra = 0.2*basic;
    da =  0.5*basic;
    pf = 0.11*basic;
    if(grade = 'A'){
        allow = 1700;
    }
    else if (grade = 'B'){
        allow = 1500;
    }
    else{
        allow = 1300;
    }
    total =  (basic + hra + da + allow) - pf;
    int totalSalary  = total;

cout<<totalSalary<<endl;
}
