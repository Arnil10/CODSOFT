#include<iostream>
#include<string>
#include<list>
#include<ctime>
using namespace std;

class todoitems{

    private:
        int id;
        string task;
        bool completed;
    
    public:
        todoitems() : id(0),task(""),completed(false) {}
        ~todoitems()=default;

    void create(string new_task){

        id=rand()%100+1;
        task=new_task;

    }
    int getid(){ return id; }
    string gettask(){ return task;}
    bool iscompleted(){ return completed;}
    void markcompleted(bool mark){

        completed=mark;
        
    }

};
void choice_box(){

    cout<<"a]Add a Todo.\n";
    cout<<"b]Mark a Todo completed.\n";
    cout<<"c]Remove a Todo.\n";
    cout<<"d]Quit.\n";
    cout<<"choice : ";
}



int main(){

    char input_choice;
    string new_task;
    int input_id1,input_id2;
    list<todoitems> items;
    list<todoitems>::iterator it;
    srand(time(NULL));
    items.clear();

    while(1){

        system("cls");
        cout<< "*****TO DO LIST:******\n\n";
        for(it=items.begin();it!=items.end();it++){
            
            string completed = it->iscompleted()?"Completed":"Pending";
            cout<<it->getid()<<" | " << it->gettask() <<" | " << completed << endl;
        }
        cout<< endl << endl;
        if(items.empty()){

            cout<<"Enter your first Todo:\n \n";
        }

        choice_box();
        cin>>input_choice;

        if(input_choice == 'a'){
            
            cout<<"Enter new Todo: ";
            cin.clear();
            cin.ignore();
            getline(cin,new_task);
            todoitems newitem;
            newitem.create(new_task);
            items.push_back(newitem);

        }
        else if(input_choice == 'b'){

            cout<<"Enter the id of a Todo to be marked completed: ";
            cin>>input_id1;
            for(it=items.begin();it!=items.end();it++){
                
                if(input_id1 == it->getid()){

                    it->markcompleted(true);
                    break;
                }
            }

        }
        else if(input_choice=='c'){

            cout<<"Enter the id of a Todo to be removed:";
            cin>>input_id2;
            it=items.begin();
            while(it->getid() !=input_id2 && it!=items.end()){

                it++;
            }
            items.erase(it);
        }
        else if(input_choice == 'd'){

            cout<<"Thank you!!";
            break;            
        }

    }    
}