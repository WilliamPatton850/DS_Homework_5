#include <iostream>
#include <cmath> 
using namespace std;

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

long long decrypt(long long a, long long b, long long p){
  long long res = 1;
  a = a % p;
  if(a == 0){
    return 0;
  }
  
  while(b > 0){
    if(b % 2 == 1){
      res = (res * a) % p;
    }
    b = b / 2;
    a = (a * a) % p;
  }
  return res;
}



int main(){

int n = 0; //598115629;
int e = 0; //71;
int cipherText = 0;

int p = 0; 
int q = 0; 
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

int totient = ((p-1)*(q-1));

  while(1){
    if(gcdExtended(e, totient) == 1){
      break;
    }
    ++e;
  }


int z = 2;
d = (1 + z * totient) / e;


cout << "Public Key: (" << n << ", " << e << ")"  << endl;
cout << "Private Key: (" << n << ", " << d << ")"  << endl;

cout << "Enter cipher text: ";
cin >> cipherText;

int birthYear = decrypt(cipherText, d, n);
cout << "Decryption key: " << d << endl;
cout << "Original Value: " << birthYear << endl;


  return 0;
}

