#include<iostream>
#include "cdec.h"
using namespace std;
int main(){

    int a,b;
    char op;
    cout << "Enter any two numbers :\n";
    cin >> a >> b;
    cout << "Enter the operation to be performed: + , -, /, *\n";
    cin >> op;
    switch(op){

        case '+':
            cout << a << "+" <<b << "=" <<add(a,b);
            break; 

        case '-':
            cout << a << "-" <<b << "=" <<subtract(a,b);
            break; 

        case '*':
            cout << a << "*" <<b << "=" <<multiply(a,b);
            break; 

        case '/':
            cout << a << "/" <<b << "=" <<divide(a,b);
            break; 
        
        default:
            cout << "error,invalid operator";
            break;
    }
    return 0;
}