First



int largest(int one,int two,int three){
    int result;
    if(one>=two)result=one;
    else result = two;
    if(three>result)result=three;
    return result;
}