3

int arraysum(int a[]){
    int sum=0;
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        sum+= a[i];
    }
    return sum;
}