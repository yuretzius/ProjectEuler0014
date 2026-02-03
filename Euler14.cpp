#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

int *cache = new int [5000001]; // the proper way to declare a primitive C-style array, cache is a pointer to its start

int Collatz(unsigned long n) 
// this is the function that returns the length of the chain for n   
{
    unsigned long m = 0;
    if (cache[n] != 0) return cache[n]; // return from cache, otherwise have to compute
    // bitwise operations are supposed to be faster (?)
    if (!(n&1)) // n&1 = 1 if last bit of n is 1, otherwise 0, so if(!(n&1)) is a fancy way of writing if(n%2 == 0)
    {  
        m = n >> 1; // n >> 1 bitshift of n one bit to the right, i.e. 10 >> 1 = 1, so it is just n/2
        cache[n] = 1 + Collatz(m); // caching the new length and using recursion
        return cache[n];
    }
    
    m = 3*n + 1; // n is odd
    int length = 1;
    unsigned long maxm = 0;
    // note that inside this cycle
    // m goes to very large values, often higher than max int
    // that's why it is important to declare it as unsigned long
    while (m > 5000000) // not going beyond the available cache
    {
        m = (m & 1) ? 3*m + 1 : m >> 1; // if m odd then 3m+1 otherwise m/2
        // if (m > maxm) maxm = m;
        length++;
    }
    // if (maxm > 2147483647) cout << maxm << " : ";
    cache[n] = length + Collatz(m);
    return cache[n];
}

int main() {
    clock_t c_start = clock();
    int N = 1000000;
    memset(cache, 0, sizeof(cache)); // filling cache with 0s
    // preparatory work
    cache[1] = 1; // by definition
    
    // if the sequence starts with a power of two
    // then it just goes down straight to 1
    // e.g 16 -> 8 -> 4 -> 2 -> 1 = length 5
    // so immediately fill these values
    int p = 1;
    for(int i = 2; i < 5000001; i <<= 1) {
        p++;
        cache[i] = p;
    }
    for(unsigned long i = 1;  i != 5000001; i++) {
        Collatz(i);
    }
    int *index = new int[5000001];
    index[1] = 1;
    // this trick is not really necessary when we have only one N
    // to check, but it is a cool one, it creates a map of indeces
    // of the largest previous elements for the whole array
    for(int i=2; i != 5000001; i++) {
        //if (cache[i] >= cache[index[i-1]]) index[i] = i;
        //else index[i] = index[i-1];
        // index[] keeps the index of the largest previous element
        // e. g. if we have sequence {1, 2, 3, 1, 2, 8, 1, 12}
        // then the index[] will be  {1, 2, 3, 3, 3, 6, 6, 8}        
        index[i] = (cache[i] >= cache[index[i-1]]) ? i : index[i-1];
    }
    
    clock_t c_end = clock();
    cout << "starting number: " << index[N] << " longest chain: " << cache[index[N]]<< endl;
    cout << endl;
    cout << 1000.0*(c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
    return 0;
}

