#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int is_prime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv) {
  vector<int> primes;

  if (argc > 1) {
    int n = atoi(argv[1]);

    for (int i = 2; i < n; i++) {
      if (is_prime(i)) {
        primes.push_back(i);
      }
    } 
    if (argc > 2) {
      for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;
      }
    }
  } else {
    cout << "usage: ./td n [--print]" << endl;
  }

  return 0;
}
