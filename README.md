
### 20250827
- Abstraction
- Static Declarations: know data type, size and range
- negative: two’s complement. steps: absolute value -> switch the value (1 -> ) -> add 1.  why? it’s more efficient for computer to do subtraction and addition

### 20250829
- the key takeaway is that data types matter. Be sure to know each data type and its bits and range

### 20250903 L03
- `#` is pre processor directive
- First only compile: `g++ -o main.o -c main.cpp` 
- then only link: `g++ -o a.exe main.o`
- then run `./a.exe`

#### In practice
- need to remember which files change, and then recompile, and relink it MANUALLY EVERY TIME, OR you can use a makefiles.

```
// step 1. use random_device here as a seed generator
random_device rd

// maxim twister? a french mathmatician 
mt19937 mt ( rd() )


// step 2. choose distribution
uniform_int_distribution<int> intDist (iMin, iMax);
uniform_real_distribution<int> floatDist (iMin, iMax);

// step 3. generate random nunm
int randomInt intDist(mt);
float randomFloat= floatDist(mt); 

// be sure to remember the diff between, one is include one is not include [ and (
// for C++ it's all inclusive
```

- uniform_int_distribution<int> intDist(14, 19)
    - what's the smallest/largest value generated? 14, 19
    - what's total different number it can generate? 6

```C++
#include <random>
using namespace std;

random_device rd;
mt19937 mt (rd());

uniform_int_distribution<int> intDist(iMin, iMax);
uniform_float_distribution<float> floatDist(fMin, fMax); 

int randomInt = intDist(mt);
float randomFloat = floatDist(mt)

```

- you can use makefile cheatsheet to learn how to use config makefile
- `make clean` clean object file
- `make submission` 


