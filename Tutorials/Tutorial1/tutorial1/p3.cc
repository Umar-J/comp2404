#include<iostream>
#include<string>

using namespace std;

void power(int, int, int&);

using namespace std;

int main(){
    int x,y,z;
    cout<<"Please enter two integers:"<<endl;
    cin>>x>>y;
    power(x,y,z);
    cout<<x<<" to the power of "<<y<<" is "<<z<<endl;
}