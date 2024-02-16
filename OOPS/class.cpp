#include<bits/stdc++.h>
using namespace std;

//creating a class

class Hero{
    //properties
   int health;  //data members
   public:
   char level;
   static int totalTime;  //static keyword is used to declare variable as static member which belongs to class
    //default constructor it is automatically invoked when an object is created
   Hero(){
    cout<<"Constructor called"<<endl;
   }

    //parametrised constructor -> it has parameters and it is used to provide different values to different objects
    Hero(int health){
        this->health = health; //this points to the current object
    }
    //copy constructor -> it is used to initialize and declare objects from another objects

    Hero(Hero &temp){
        this->health = temp.health;
        this->level = temp.level;
    }

   //Access specifiers 
   //private, public and protected.
   //by default it is private where member and functions cannot be accessed outside the class
   //public means variables and functions can be accessed anywhere
   //protected means it is private but it can be acccessed by child 

   void print(){ //member functions
    cout<<health<<endl;
   }

   //getter and setter methods
   int getHealth(){
    return health;
   }

   char getLevel(){
    return level;
   }

   void setHealth(int h){
    health = h;
   }

   void setLevel(char ch){
    level = ch;
   }


    static int staticFunction(){ //static function can only access static member and it belongs to class
        return totalTime;
    }
   ~Hero(){
    cout<<"Destructor is called"<<endl;
    //destructor is called automatically for static allocation but in dynamic allocation it requires manually calling
    
   }


};

//paddding and greedy alignment are used to optimise the memory usage and performance of program

class padding{ //padding is a technique of adding extra bytes to a class to align its data members to a specific boundary
    char ch;
    int value;
    char c;
    double d;
    //if we print the size of object of this class then it will be 24 1 + 3(padding) + 4 + 1 + 7(padding) +8

};
class greedyAlignment{ //greedy alignment is a technique of minimising padding by ordering the data members in decreasing order
    char ch;  
    char h; 
    double d;
    int value;
   
    
    
    //here the size of object of this class is 24

};

int Hero::totalTime = 18; //here we are initialising static member

int main(){

    cout<<Hero::totalTime<<endl; //we can access static member without creating object
    cout<<Hero::staticFunction()<<endl; //here we can access only static members 
    //creation of object
    Hero h1(20); //static allocation


    Hero *shreyansh = new Hero; //dynamic allocation
    delete shreyansh;
    cout<<"Health in dynamic allocation:"<<(*shreyansh).getHealth()<<endl;
    cout<<"level in dynamic allocation:"<<(*shreyansh).getLevel()<<endl;

    cout<<shreyansh->getHealth()<<endl;
    cout<<shreyansh->getLevel()<<endl;
    cout<<"Size of object is:"<<sizeof(h1)<<endl; //if the class is empty then the size of object is 1 byte

    h1.level = 'A';
    cout<<"Level is:"<<h1.level<<endl;
    h1.print();
    h1.setHealth(70);
    h1.setLevel('S');
    cout<<"Health is:"<<h1.getHealth()<<endl;
    cout<<"Level is:"<<h1.getLevel()<<endl;

    cout<<"Size of the object is:"<<sizeof(h1)<<endl;

    padding p1;
    greedyAlignment g1;
    cout<<"Padding:"<<sizeof(p1)<<endl;
    cout<<"Greedy alignment:"<<sizeof(g1)<<endl;


    Hero ramesh;
    ramesh.setHealth(18);
    ramesh.setLevel('V');
    cout<<"Level of ramesh is:"<<ramesh.getLevel()<<endl;
    cout<<"Health of ramesh is:"<<ramesh.getHealth()<<endl;

    Hero suresh(ramesh);
    cout<<"Level of suresh is:"<<suresh.getLevel()<<endl;
    cout<<"Health of suresh is:"<<suresh.getHealth()<<endl;

    return 0;
}