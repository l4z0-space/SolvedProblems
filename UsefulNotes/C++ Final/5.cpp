// 5

class Person{

private:
    string name;
    int age;
public:

    Person(); //empty constructor
    Person(string n, int a){
        name=n;
        age=a;          // two parameter constructor
    }

    Person(const Person &P){
        name = P.name;
        age = P.age;        //copy constructor
    }

    ~Person(); //destructor


};