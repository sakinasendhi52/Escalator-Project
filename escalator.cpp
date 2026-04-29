// STACK OPERATIONS


//header files
#include<iostream>
using namespace std;
   
class Stack{       //base class
    public:               //pure virtual functions
        virtual void pushInStack()=0;

        virtual void popFromStack()=0;

        virtual void peekInStack()=0;

        virtual void displayStack()=0;

        virtual void isEmpty()=0;

        virtual void isFull()=0;

        virtual void checkSize()=0;

        virtual ~Stack() {}
};

class StackOperations:public Stack{           //derived class
    private:         //private data members
        int top, size, count,element;
        int* arr;
    public:
        StackOperations(){         //constructor
            cout<<endl<<"Enter the size of Stack : ";
            cin>>size;

            top=-1;
            count=0;

            arr=new int[size];
        }

        void pushInStack(){           //insert operation
            if(top>=size-1){
                cout<<"STACK IS OVERFLOW"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - PUSH OPERATION - - - - - - -"<<endl;
                cout<<"Enter element : ";
                cin>>element;
                top++;
                arr[top]=element;
                count++;
                cout<<"ELEMENT INSERTED"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void popFromStack(){           //delete operation
            if(top==-1){
                cout<<"STACK IS UNDERFLOW"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - POP OPERATION - - - - - - - -"<<endl;
                int temp;
                temp=arr[top];
                top--;
                count--;
                cout<<"TOP ELEMENT "<<temp<<" DELETED"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void peekInStack(){            //top element display
            if(top==-1){
                cout<<"STACK IS UNDERFLOW"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - PEEK OPERATION - - - - - - -"<<endl;
                cout<<"TOP ELEMENT IS "<<arr[top]<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void displayStack(){            //display stack
            if(top==-1){
                cout<<"STACK IS UNDERFLOW"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - VIEW STACK ELEMENTS - - - - - - -"<<endl;
                for(int i=top; i>=0; i--){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void isEmpty(){              //check stack is empty or not
            if(top==-1){
                cout<<"- - - - - - - STACK IS EMPTY - - - - - - -"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - STACK IS NOT EMPTY - - - - - - -"<<endl<<endl;
            }
        }

        void isFull(){            //check stack is full or not
            if(top==size-1 && count==size){
                cout<<"- - - - - - - STACK IS FULL - - - - - - -"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - STACK IS NOT FULL - - - - - - -"<<endl<<endl;
            }
        }

        void checkSize(){           //check size of stack
            cout<<"- - - - - - - STACK SIZE : "<<count<<" - - - - - - -"<<endl<<endl;
        }

        ~StackOperations(){                   //destructor
            delete[] arr;
            cout<<"MEMORY RELEASED";
        }
};

int main(){      //main function
    int choice;            //variables
    Stack* s;        //pointer object
    s=new StackOperations();         //runtime polymorphism

    //do while loop
    do{
        cout<<"------------------------------------- STACK OPERATIONS ------------------------------------"<<endl<<endl;
        cout<<"1. PUSH ELEMENT               2. POP ELEMENT                    3. PEEK TOP ELEMENT"<<endl;
        cout<<"4. DISPLAY STACK              5. CHECK STACK EMPTY OR NOT       6. CHECK STACK FULL OR NOT"<<endl;
        cout<<"7. CHECK SIZE                 8. EXIT"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;      //input choice
        cout<<endl;

        //switch case for menu
        switch(choice){
            case 1:{          //Push element in the stack
                s->pushInStack();
                break;
            }
            case 2:{          //Pop element from the stack
                s->popFromStack();
                break;
            }
            case 3:{          //Peek top element
                s->peekInStack();
                break;
            }
            case 4:{          //Display element in the Stack
                s->displayStack();
                break;
            }
            case 5:{          //Check Stack Empty or not
                s->isEmpty();
                break;
            }
            case 6:{          //Check Stack Full or not
                s->isFull();
                break;
            }
            case 7:{          //Check Size of the Stack
                s->checkSize();
                break;
            }
            case 8:{              //exit case
                cout<<"---------------------------------------- THANK YOU ----------------------------------------"<<endl;
                break;
            }
            default:{            //default case
                cout<<"INVALID CHOICE"<<endl<<endl;
                break;
            }
        }
    }
    while(choice!=8);

    delete s;       //destructor call

    return 0;
}