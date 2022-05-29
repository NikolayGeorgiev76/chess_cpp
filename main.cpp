#include <iostream>
using namespace std;
//class - template , has - name, attributes, behaviour.
//object - instance of class , has - identity, attributes, behaviour
//OOP Pillars - Abstraction, Encapsulation, Inheritance, Polymorphism
//Abstraction - use only needed data for program execution
//Encapsulation - data hiding, uses access specifiers
//this - keyword, pointer to self
class Humanoid{//ABSTRACT class - can not have insances
  public:
    string race;
    Humanoid(){
      cout<<"A humanoid is created"<<endl;
    };
    virtual void showRace() = 0;//pure virtual function - has no body, must be overloaded in derived MANDATORY
    virtual ~Humanoid(){
      cout<<"A humanoid was lost"<<endl;
    };
};

class Person:public Humanoid{//by default access specifier is private
    int cash;
  public://access specifier - public,private , protected
    int age;//atributes
    int *height = new int();
    int weight;
    string name;

    //behavior - functions in class are called methods
    Person(){//constructor - special method , that has the same name as the class, has no type, doesn't return a type
      cout<<"New Person is born!"<<endl;
      age = 10;
    }//default constructor
    Person(string name){
      this->name = name;
    }
    Person(int age,int height, int weight){
      this->age = age;
      *this->height = height;
      this->weight = weight;
    }//with params

    Person(Person const &other){
      age = other.age;
      *height = *other.height;
      weight = other.weight;
    }//copy constructor

    virtual void sayHi(){//virtual function - expected to be overloaded in derived classes
      cout<<"Hi"<<endl;
    }
    void setCash(int _c){
      cash = _c;
    }
    int getCash(){
      return cash;
    }
    void showRace(){
      cout<<"I'm human"<<endl;
    }

    virtual ~Person(){//destructor - special method, same name as class, DOES NOT take arguments or return value, not required
      cout<<"A person has left us"<<endl;
      delete height;
    }
}obj1;

class Organization{
  Person p[10];
  string name;
};

class Sportsperson{
  public:
    Sportsperson(){
      cout<<"A new superstar!"<<endl;
    }
    string teamName;
  
    ~Sportsperson(){
      cout<<"A sportsperson retired"<<endl;
    }
};

class Student : public Person, protected Sportsperson{
public:
  Student(){
    cout<<"A new student arrives!"<<endl;
  }
  int grades[10];
  virtual ~Student(){
    cout<<"A student graduates."<<endl;
  }

  void sayHi(){
    cout<<"Good day!"<<endl;
  }
};

class CumLaude : public Student{
  public:
    CumLaude(){
    cout<<"A new honors student arrives!"<<endl;
  }
  int ringNum;

  void sayHi(){
    cout<<"Ad astra!"<<endl;
  }

  virtual ~CumLaude(){
    cout<<"A honors student graduates."<<endl;
  }

};
//Task 1 - define a class with at least 3 private and 3 public attributes. Define getters and setters for private data and at least 2 methods of choice. Create an object and test.
class Drinks{
  private:
    double price;
    double volume;
    string name;
    double discount;
  public:
    string deliveryLocation;
    int number;
    string colour;
    bool isEmpty;

    void printLabel(){//get name value
      cout<<name<<endl;
    }
    double discountPrice(){//% discount - 1/2
      return price*discount;
    }
    void setDiscount(double discount1){//set discount value
      discount = discount1;
    }
    void setName(string newName){
      name = newName;
    }
    void setVolume(double newVolume){
      volume = newVolume;
    }
    void setPrice(double newPrice){
      price = newPrice;
    }
    void notAvailable(bool available = true){
        cout<<"Is available: "<<available<<endl;
    }
    
};

int main() {
  Person p3("pesho");//calls ctr with params
  Person p1;//calls default ctr
  Person p2();//default ctr
  Person pCopy(p3);
  cout<<p1.age<<endl;//dot operator
  cout<<p1.getCash()<<endl;
  p1.setCash(50);

  Drinks drink1;
  drink1.deliveryLocation = "Sofia";
  cout<<drink1.deliveryLocation<<endl;
  cout<<p3.name<<endl;
  drink1.notAvailable();


  Person PeshoP;
  Student PeshoS;
  CumLaude PeshoC;

  PeshoP.sayHi();
  PeshoS.sayHi();
  PeshoC.sayHi();

  Humanoid *hp = new Person();
  hp->showRace();

  Student s1;
}