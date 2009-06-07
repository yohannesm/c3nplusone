#include<iostream>

using namespace std;
int i, j, v;
void eval();
int maxLength(int n);


int main(){
cin >> i >> j;
eval();
cout << v << endl;
cout << maxLength(3);
return 0;
}

void eval(){
v = 0;
int maxCycleLength = 0;
for(int a = i; a<=j; a++){
maxCycleLength  = maxLength(a);
if(maxCycleLength >v) v = maxCycleLength;
}
}

int maxLength(int n){
int ctr = 1;
while(n!=1){
   if(n%2==0){
	n = n/2; ctr++;	}
else{
n = 3*n+1; ctr++;
}
	}
return ctr;
}


