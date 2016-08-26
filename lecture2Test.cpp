#include <iostream>

using namespace std;

int A(int &v){
    v++;
}

int main(){
    int x = 4;
    A(x);

    cout << x << endl;
}