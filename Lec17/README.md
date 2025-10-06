- c++ vector ref: https://cplusplus.com/reference/vector/vector/size/
- **use `size_t`**, which is another name for unsigned int
- size_t in C++ is an unsigned integer type defined in the <cstddef> header (or <stddef.h> in C). [ref](https://cplusplus.com/reference/cstddef/size_t/)

- the `at` function is a setter and a getter

#### example:

```c++

CSCI 200 11 CS @ Mines
#include <iostream>
#include <vector>
using namespace std;
int main() {
vector< int > myVec;
while( true ) {
cout << "Enter a num (zero to stop): ";
int x;
cin >> x;
if(x > 0) { myVec.push_back( x ); }
else if (x == 0) { break; }
}
cout << "# positive values entered: " << myVec.size() << endl;
cout << "Values are: ";
for(size_t i = 0; i < myVec.size(); i++) {
cout << myVec.at(i) << " ";
}
cout << endl;
return 0;
}

```

- `String::npos` is basically -1 (not found)
