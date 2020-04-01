// 9

class Student{

private:
    string name;
    double exams;
    double quizzes;
public:
    Student(); // empty constructor
    Student(string n,double e, double q){
        name=n;
        exams=e;
        quizzes=q;
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

int main(){

    Student s("Sotir",87,96);
    s.displayGrade();
    return 0;
}