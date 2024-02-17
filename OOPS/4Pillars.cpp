#include<bits/stdc++.h>
using namespace std;
class Encapsulation{
    //Encapuslation is process of wrapping up data member and member functions into a single unit called class.
    //In encapsulation data is not accessed directly it is accessed through public getter and setter methods.
    //Encapsulation makes the concept of data hiding possible 
    private:
    int data;
    char ch;
    string name;

    public:
    int getData(){
        return this->data;
    }
};

//Inheritance:- It is process in which one class occupies all properties and behaviours of its parent automatically .


//The parent class is called base class and the child class is called derived class

//Types of inheritance
//1.single :- one class is derived from base class
//2.multilevel:- one class is derived from derived class
//3.multiple:- one class is derived from more than one class
//4.hierachical:- two or more class is derived from one base class
//5.hybrid:- combination of two or more inheritance


//Inheritance ambiguity : means c is a derived class from both a and b and both have func() so for resolving this we use scope resolution operator object_name.base_class::func()
class Human{
    public: //access specifiers
    int age;
    int height;
    int weight;

    public:
    int getAge(){
        return this->age;
    }
};

class Male: public Human{ //class derived_class: access specifiers base_class
    public:
    string name;

    void maleFunction(){
        cout<<"Male Class is derived class from human"<<endl;
    }

};

//Polymorphism :- It is ability to present same interface for differing data types
//Compile time polymorphism and run time polymorphism
class A{
    public:
    int a;

    int add(int a,int b){
        return a+b;

    }
    int add(int a,int b,int c){
        return a+b+c;
    }

    void operator+(A &obj){
        int value1=  obj.a; 
        int value2 = this->a; 
        cout<<"Value is:"<<value2-value1<<endl;
    }
    void operator()(){
        cout<<"Operator overloading of bracket()"<<endl;
    }
};
//run time polymorphism depends on inheritance and contains function overriding while compile time polymorphism contains method overloading
int main(){
    Encapsulation e1;
    cout<<"Encapsulation is running fine:"<<e1.getData()<<endl;

    Male m1;
    cout<< m1.getAge()<<endl;
    A a1;
    cout<< a1.add(1,2)<<endl;
    cout<<a1.add(1,2,3)<<endl;
    A a2;
    a1.a = 4;
    a2.a = 7;
    a1 + a2;
    a1();
   
    return 0;

    //Encapsulation :- information hiding
    //Abstraction :- implementation hiding
}