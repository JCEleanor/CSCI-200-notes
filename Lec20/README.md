### collection of objects

```c++
// enroll students
for (size_t i = 0; i < courseCatalog.size(); i++) {
    Course currentCourse = courseCatalog.at(i);
    currentCourse.registerStudent();
    currentCourse.registerStudent();
    // currentCourse is a local varaible that lives inside the for loop, so the value of the actual vector courseCatalog doesn't change
}
```

- Java is all references, and it hides pointer from users

```c++
Course *pCSCI200 = new Course("CSCI 200");
// dereference that object
(*pCSCI200).getEnrollment(); // parenthesis is needed!!!
pCSCI200->getEnrollment(); // is the same

```

- **`->`** is short for (\*someVariable).operation()

```c++
// enroll students
for(size_t i = 0; i < courseCatalog.size(); i++) {
    Course* pCurrentCourse = courseCatalog.at(i); // making reference on the actual vector on the free store
    pCurrentCourse->registerStudent();
    pCurrentCourse->registerStudent();
}
```

### Passing Objects to Functions

- be careful of PBV, bc it makes a copy of that value, if the value is huge, it takes up memory

```c++
// PBV
void add_to_vector_b_v( vector<int> vec ) {
    vec.push_back( 100 ); // nothing changes to vec
}

// PBR
void add_to_vector_b_r( vector<int>& vec ) {
    vec.push_back( 200 );
}

// PBP, pVec is a pointer to a vector
void add_to_vector_b_p( vector<int>* pVec ) {
    pVec->push_back( 300 );
}

vector<int> myVec;
add_to_vector_b_v( myVec ); cout << myVec.size() << endl;
add_to_vector_b_r( myVec ); cout << myVec.size() << endl;
add_to_vector_b_p( &myVec ); cout << myVec.size() << endl;
```

```c++
void string_func_v( string str ) {...}
void string_func_r( string& str ) {...}
void string_func_p( string* pStr ) {...}
...
string word = "does this work?";
string_func_v( word ); // YES
string_func_r( word ); // YES
string_func_p( &word ); // YES
string_func_v( "does this work?" ); // YES

// can't reference that readonly chunck of memory
string_func_r( "does this work?" ); // NO :(
string_func_p( "does this work?" ); // NO :(
```

#### How Much Memory Used?

```c++
void string_func_v( string str ) {...}
void string_func_r( string& str ) {...}
void string_func_p( string* pStr ) {...}

string word = "does this work?";
// 2: `word` and the function param in `str`
string_func_v( word );

// str will be a copy
string_func_r( word );
// one copy plus on pointer
string_func_p( &word );

// one copy
string_func_v( "does this work?" );

```

**Pass by reference whenever we can For Maximum Efficiency**
let overloading functions do the work, to cut down copies (memory usage)

- PBV: makes 2 copies – **O(n)**, has to loop through that copies to get all the values
- PBR: make 1 copy - **O(1)**
- PBP: vector_p( &numbers ); // 1 copy + pointer – **O(1)**

- Read only: `void vector_r (const vector<int>&VEC) {}`
