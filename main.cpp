#include <iostream>
#include <cmath> 
using namespace std;

/*
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
 */

int gcdExtended(int a, int b){
  if(b == 0){
    return a;
  }
  return gcdExtended(b, a % b);
}

bool isPrime(int n){
  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int decrypt(int a, int b, int p){
  if(b == 0){
    return 1;
  }
  int r = decrypt(a, (b/2), p);
  r = (r * r) % p;
  if(b % 2){
    r = (r * a) % p;
  }
  return r;
}

int main(){

int n = 0; //598115629;
int e = 0; //71;
int cipherText = 0;

int p = 0; 
int q = 0; 
//int l;
//int totient = ((p-1)*(q-1));
//int n = (p*q);
//int e = 3; 
//int x, y;
//int gcd;
//int a = totient;  
//int b = e;
int d;


cout << "Enter value for n: ";
cin >> n;
cout << "Enter value for e: ";
cin >> e;

for(int i = 2; i * i <= n; ++i){
  if(n % i == 0){
    if(isPrime(i) && isPrime(n / i)){
      p = i;
      q = n / i;
      break;
    }
  }
}


/*
  if(p > q){
    l = p;
  }
  else{
    l = q;
  }
*/

int totient = ((p-1)*(q-1));

  while(1){
    if(gcdExtended(e, totient) == 1){
      break;
    }
    ++e;
  }

/*
  while(1){
    if(l%(p-1) == 0 && l%(q-1) == 0){
      //cout << "The LCM of " << p << " and " << q << " is " << l << endl;
      break;
    }
    l++;
  }
*/
/*
a = l; 
if(a < b) swap(a, b);
gcd = gcdExtended(a, b, x, y); 

if(y < 0){
  d = totient + y;
}
else{
  d = y; 
}
*/


int z = 2;
d = (1 + z * totient) / e;


cout << "Public Key: (" << n << ", " << e << ")"  << endl;
cout << "Private Key: (" << n << ", " << d << ")"  << endl;

cout << "Enter cipher text: ";
cin >> cipherText;
//long long z2 = pow(cipherText, d);
int birthYear = decrypt(cipherText, d, n);
cout << "Decryption key: " << d << endl;
cout << "Birth Year: " << birthYear << endl;


//gcd = gcdExtended(p, q, x, y);

/*
if(y < 0){
  d = totient + y;
}
else{
  d = y;
}
*/


  return 0;
}

