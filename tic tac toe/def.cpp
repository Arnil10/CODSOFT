#include<iostream>
#include<array>
#include "declaration.h"
using namespace std;
string arr[9]={" "," "," "," "," "," "," "," "," "};
int player=1;
int position=0;

void board(){

    cout << "player 1) X.\n";
    cout << "player 2) O.\n\n";

    cout <<"     |     |      \n";
    cout <<"  1  |  2  |  3   \n";
    cout <<"_____|_____|_____ \n";
    cout <<"     |     |      \n";
    cout <<"  4  |  5  |  6   \n";
    cout <<"_____|_____|_____ \n";
    cout <<"     |     |      \n";
    cout <<"  7  |  8  |  9   \n";
    cout <<"     |     |      \n\n";
    


}
bool iswinner(){

    //vertical
    bool winner=false;
    if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[0]!=" "){

        winner=true;
    }
    else if(arr[3]==arr[4]&&arr[4]==arr[5]&& arr[3]!=" "){

        winner=true;
    }
    else if(arr[6]==arr[7]&&arr[7]==arr[8]&&arr[6]!=" "){

        winner=true;
    }
    //horizontal
    else if(arr[0]==arr[3]&&arr[3]==arr[6]&&arr[0]!=" "){

        winner=true;
    }
    else if(arr[1]==arr[4]&&arr[4]==arr[7]&&arr[1]!=" "){

        winner=true;
    }
    else if(arr[2]==arr[5]&&arr[5]==arr[8]&&arr[2]!=" "){

        winner=true;
    }
    //diagonal
    else if(arr[0]==arr[4]&&arr[4]==arr[8]&&arr[0]!=" "){

        winner=true;
    }
    else if(arr[2]==arr[4]&&arr[4]==arr[6]&&arr[2]!=" "){

        winner=true;;      
    }
    return winner;

}
bool isfilled(){

    bool filled=true;
    for(int i=0;i<9;i++){

        if(arr[i]==" "){

            filled=false;
        }
    }
    return filled;
}


void draw(){

    cout <<"     |     |      \n";
    cout <<"  "<<arr[0]<<"  |  "<<arr[1]<<"  |  "<<arr[2]<<"    \n";
    cout <<"_____|_____|_____ \n";
    cout <<"     |     |      \n";
    cout <<"  "<<arr[3]<<"  |  "<<arr[4]<<"  |  "<<arr[5]<<"   \n";
    cout <<"_____|_____|_____ \n";
    cout <<"     |     |      \n";
    cout <<"  "<<arr[6]<<"  |  "<<arr[7]<<"  |  "<<arr[8]<<"   \n";
    cout <<"     |     |      \n";
    cout <<"\n";
}
void get_position(){

    cout << "player "<<player<<"'s turn.(enter 1-9):\n";
    while(!(cin>>position)){

        cout << "invalid input,Enter proper number[1-9]\n";
        cin.clear();
    cin.ignore();
    }
    while(arr[position-1]!=" "){

        cout << "Already occupied,enter different position\n";
        cout << "player"<<player<<"'s turn\n";
        cin >> position;
    }
}
void update_board(){

    if(player%2==0){

        arr[position -(int)1]="O";
    }
    else{

        arr[position -(int)1]="X";
    }

}
void next_player(){

    if(player==1){

        player++;
    }
    else{

        player--;
    }

}
void take_turn(){

    while(!(iswinner()) && !(isfilled()))
    {   
        get_position();
        update_board();
        draw();
        next_player();
    }
}
void endgame(){

    if(iswinner()==true){

        cout << "There is a winner !\n";
    }
    else if(isfilled()==true)
    {
        cout << "There is a tie!\n";
    }
}
 void reset_array(){

    for(int x=0;x<9;x++)
    {
        arr[x]=" ";
    }
}



