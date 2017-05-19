#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main (int argc, char **argv) {

  if (argc > 1) {
    int n = atoi(argv[1]);

    vector<unsigned char> primes(n + 1);

    for (int i = 0; i <= n; i++) {
      primes[i] = 1;
    }

    primes[0] = 0;
    primes[1] = 1;

    for (int i = 2; i <= sqrt(n); i++) {
      if (primes[i] == 1) {
        for (int j = i; i*j <= n; j++) {
          primes[i*j] = 0;
        }
      }
    }

    if (argc > 2) {
      int count = 0;
      for (int i = 0; i < primes.size(); i++) {
        if (primes[i]) {
			cout << i << "\n";
        //   count++;
        }
      }
      cout << "\nThere are " << count << " primes less than or equal to " << n << "\n" << endl;

    }
  } else {
    cout << "usage: ./e_seq n [--print]" << endl;
  }

  return 0;
}
