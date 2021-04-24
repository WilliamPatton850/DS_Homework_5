#include <iostream>
#include <cmath> 
using namespace std;

int gcdExtended(int a, int b, int &x, int &y){
    if(b == 0){
      x = 1;
      y = 0;
      return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
  }

int main(){

int n = 598115629;
int e = 71;

int p = 17791;
int q = n / p;
int l;
int totient = ((p-1)*(q-1));
//int n = (p*q);
//int e = 3; 
int x, y;
int gcd;
int a = totient;  
int b = e;
int d;

cout << "Enter value for n: ";
cin >> n;
cout << endl;
cout << "Enter value for e: ";
cin >> e;
cout << endl;



  if(p > q){
    l = p;
  }
  else{
    l = q;
  }

  while(1){
    if(l%(p-1) == 0 && l%(q-1) == 0){
      //cout << "The LCM of " << p << " and " << q << " is " << l << endl;
      break;
    }
    l++;
  }

/*
cout << "p = " << p << endl;
cout << "q = " << q << endl;
cout << "l = " << l << endl;
cout << "Totient = " << totient << endl;
cout << "e = " << e << endl;
cout << "n = " << n << endl;
*/

a = l; 
if(a < b) swap(a, b);
gcd = gcdExtended(a, b, x, y); 
//cout << "gcd = " << gcd << endl;
//cout << "x = " << x << endl;
//cout << "y = " << y << endl;
if(y < 0){
  d = totient + y;
}
else{
  d = y; 
}
//cout << "d = " << d << endl;


cout << "Public Key: (" << n << ", " << e << ")"  << endl;
cout << "Private Key: (" << n << ", " << d << ")"  << endl;

int cipherText = 576148263;
long long z = pow(cipherText, d);
long long birthYear = z % n;
cout << "Birth Year: " << birthYear << endl;

gcd = gcdExtended(p, q, x, y);
//cout << "gcd = " << gcd << endl;
//cout << "x = " << x << endl;
//cout << "y = " << y << endl;
if(y < 0){
  d = totient + y;
}
else{
  d = y;
}
//cout << "d = " << d << endl;
cout << "Public Key: (" << n << ", " << e << ")"  << endl;
cout << "Private Key: (" << n << ", " << d << ")"  << endl;

  return 0;
}

