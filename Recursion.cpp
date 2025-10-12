#include <iostream>
using namespace std;

// time complexity of Facorial problem is O(n)
// space complexity O(n) (number of levels in recursion tree)
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

// time complexity of Fibonacci problem is O(2^n)
// space complexity O(n) (number of levels in recursion tree)
int fibonacci(int n){
    if(n==0 || n==1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// time complexity of TOH problem is O(2^n)
// space complexity O(n) (number of levels in recursion tree)
void TOH(int n,char source,char aux,char destination){ 
    if(n==1) cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
    else{
        TOH(n-1,source,destination,aux);
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        TOH(n-1,aux,source,destination);
    }
}
int main(){
    cout<<factorial(5)<<endl;
    cout<<fibonacci(10)<<endl;
    TOH(4,'A','B','C');
}