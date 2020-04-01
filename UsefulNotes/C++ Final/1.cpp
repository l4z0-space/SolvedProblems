1

int main(){

    char c;
    cout<<"Enter a char: ";
    cin>>c;

    switch(c){

        case 'y':cout<<"Yes"<<endl;break;
        case 'Y':cout<<"Yes"<<endl;break;
        case 'N':cout<<"No"<<endl;break;
        case 'n':cout<<"No"<<endl;break;
        default: cout<<"Unknown\n";
    }
    return 0;
}