bool isPalindrome(int x) {
    int num=x;
    int rem;
    long rev=0;
    if(x<0){
        return false;
    }
     while(num!=0){
        rem = num%10;
        rev = rev*10 +rem;
        num=num/10;
    }
    if(rev==x){
        return true;
    }
    return false;
}
