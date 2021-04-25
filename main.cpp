#include <iostream>
#include <cmath> 
using namespace std;

long long gcdExtended(long long a, long long b){
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

long long modInverse(long long a, long long m){
  a = a % m;
  for (int x = 1; x < m; x++){
    if((a * x) % m == 1){
      return x; 
    }
  }
  return 1; 
}



int main(){

long long n = 0; //598115629;
long long e = 0; //71;
long long cipherText = 0;

long long p = 0; 
long long q = 0; 
long long d;


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


d = modInverse(e, totient);

cout << "Public Key: (" << n << ", " << e << ")"  << endl;
cout << "Private Key: (" << n << ", " << d << ")"  << endl;

cout << "Enter cipher text: ";
cin >> cipherText;

long long birthYear = decrypt(cipherText, d, n);
cout << "Decryption key: " << d << endl;
cout << "Original Value: " << birthYear << endl;

  return 0;
}

