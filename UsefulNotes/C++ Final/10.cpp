// 10

class BaseStudent{

public:

    virtual void displayGrade()=0;

};


class Student: public BaseStudent{

private:
    string name;
    double exams;
    double quizzes;
public:

    Student(string n,double e, double q){
        this->name=n;
        this->exams=e;
        this->quizzes=q;
    }
    string getName(){
        return name;
    }

    double getFinalGrade(){
        return 0.6*exams + 0.4 *quizzes;
    }

    void displayGrade(){
        double grade = getFinalGrade();
        cout << "Final Grade for " << getName() <<" is: ";
        if(grade>90)cout<<"A";
        else if(grade>80)cout<<"B";
        else if(grade>70)cout<<"C";
        else if(grade>60)cout<<"D";
        else cout<<"F";
        cout<<" ("<<grade<<")";
        cout<<endl;
    }
};

class PFStudent: public Student{

public:

    PFStudent();

    PFStudent(string n, double e,double q):
        Student(n,e,q){};

    void displayGrade(){
        Student::displayGrade();
        if(getFinalGrade()>60){
            cout<< "P" <<endl;
        }
        else cout <<"F"<<endl;
    }


};

int main(){

    BaseStudent * s1 = new PFStudent ("Sotir",97,84);
    BaseStudent * s2 = new PFStudent ("Vladimir",91,76);
    BaseStudent * s3 = new PFStudent ("Lazaron",99,100);

    s1->displayGrade();
    s2->displayGrade();
    s3->displayGrade();
}