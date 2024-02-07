#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> Optimised_Sieve(int n) { // TC-> O(n*(Log(Log(n))))
  vector<bool> sieve(n, true);

  sieve[0] = sieve[1] = true;

  for (int i = 2; i * i < n;
       i++) { // Optimisation 2 -> Here, since we have made the inner loop
              // optimised, we do the same to the outer loop to ensure
    if (sieve[i]) {
      // int j = 2*i;
      int j = i * i; // Optimisation 1 -> This is the place where we start the
                     // loop. We will start from i*i, as others before it would
                     // have alreayd been marked true by 2 to (i-1).
      while (j < n) {
        sieve[j] = false;
        j += i;
      }
    }
  }
  return sieve;
}

vector<bool> Bounded_Sieve(int L, int R) {
  vector<bool> pre_sieve = Optimised_Sieve(
      sqrt(R)); // Will get all the primes required further to get it
  vector<int> base_primes;
  for (int i = 0; i < pre_sieve.size(); i++) {
    if (pre_sieve[i]) {
      base_primes.push_back(i);
    }
  }

  vector<bool> seg_sieve(R - L + 1);
  if (L == 0 || L == 1) {
    seg_sieve[L] = false;
  }

  for (auto prime : base_primes) {
    int first_multiple =
        (L / prime) * prime;  // Formula to get the first multiple
    if (first_multiple < L) { // If it falls short, add the prime to it
      first_multiple += prime;
    }

    int j = max(first_multiple, prime * prime);

    while (j <= R) {
      seg_sieve[j - L] = false;
      j += prime;
    }
  }
  return seg_sieve;
}

int main() {
  vector<bool> sol = Bounded_Sieve(110, 130);
  for (int i = 0; i < sol.size(); i++) {
    if (sol[i]) {
      cout << i + 110 << " ";
    }
  }
  return 0;
}