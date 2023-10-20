#include<iostream>
#include<string>
#include "declaration.h"

using namespace std;
int main(){


    char op;
    int plug=0;

    do{
        system("cls");
        reset_array();
        board();
        take_turn();
        endgame();

        cout << "do you want ot play again?(y/n)";
        cin >> op;
        if(op=='y'||op=='Y'){

            plug=1;
        }
        else{

            plug=0;
        }

    }while(plug==1);
    
    return 0;
}