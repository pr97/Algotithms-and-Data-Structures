#include <bits/stdc++.h> 
#define ll long long
using namespace std; 
  
/* Iterative Function to calculate (a^n)%p in O(logy) */
ll power(ll a, unsigned ll n, ll p) 
{ 
    ll res = 1;      // Initialize result 
    a = a % p;  // Update 'a' if 'a' >= p 
  
    while (n > 0) 
    { 
        // If n is odd, multiply 'a' with result 
        if (n & 1) 
            res = (res*a) % p; 
  
        // n must be even now 
        n = n>>1; // n = n/2 
        a = (a*a) % p; 
    } 
    return res; 
} 
  
// If n is prime, then always returns true, If n is 
// composite than returns false with high probability 
// Higher value of k increases probability of correct 
// result. 
bool isPrimeFermat(unsigned ll n, ll k) 
{ 
   // Corner cases 
   if (n <= 1 || n == 4)  return false; 
   if (n <= 3) return true; 
  
   // Try k times 
   while (k>0) 
   { 
       // Pick a random number in [2..n-2]         
       // Above corner cases make sure that n > 4 
       ll a = 2 + rand()%(n-4);   
  
       // Fermat's little theorem 
       if (power(a, n-1, n) != 1) 
          return false; 
  
       k--; 
    } 
  
    return true; 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// C++ program Miller-Rabin primality test 
  
// This function is called for all k trials. It returns 
// false if n is composite and returns false if n is 
// probably prime. 
// d is an odd number such that  d*2<sup>r</sup> = n-1 
// for some r >= 1 
bool miillerTest(ll d, ll n) 
{ 
    // Pick a random number in [2..n-2] 
    // Corner cases make sure that n > 4 
    ll a = 2 + rand() % (n - 4); 
  
    // Compute a^d % n 
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
  
    // Keep squaring x while one of the following doesn't 
    // happen 
    // (i)   d does not reach n-1 
    // (ii)  (x^2) % n is not 1 
    // (iii) (x^2) % n is not n-1 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    // Return composite 
    return false; 
} 
  
// It returns false if n is composite and returns true if n 
// is probably prime.  k is an input parameter that determines 
// accuracy level. Higher value of k indicates more accuracy. 
bool isPrimeMiller(ll n, ll k) 
{ 
    // Corner cases 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  
    // Find r such that n = 2^d * r + 1 for some r >= 1 
    ll d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  
    // Iterate given nber of 'k' times 
    for (ll i = 0; i < k; i++) 
         if (miillerTest(d, n) == false) 
              return false; 
  
    return true; 
}

bool isPrimeFuckYeah(ll n, ll k){
  return isPrimeFermat(n, k) && isPrimeMiller(n, k);
}
  
// Driver Program to test above function 
int main() 
{ 
    int k = 3; 
    isPrime(11, k)?  cout << " true\n": cout << " false\n"; 
    isPrime(15, k)?  cout << " true\n": cout << " false\n"; 
    return 0; 
} 