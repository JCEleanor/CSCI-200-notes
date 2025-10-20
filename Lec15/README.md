## Streams

- `#include <iostream>`
- all the photos, videos, and mp3 are a **stream of bits**

## Reading files

### `fstream`

#### `ifstream`

```c++
ifstream myInput ("filename.txt");
// `>>` is Extraction operator
myInput >> fileString;
```

Suppose we have text file like so:
`12 34 56\n78 90 91`

Read the next value after the cursor up until a whitespace character:

```c++
int x;
while(fileIn >> x){
    cout << x << endl;
    // 12
    // 34
    // ...
    // 91
}
```

Read **one character** after the cursor:

```c++
char x;
// generally considered unsafe in C++? according to gemini
while (!fileIn.eof()){
    x = fineIn.get();
    cout << x << endl;
    //   The output will be:
    //     1
    //     2
    //
    //     3
    //     4
    //
    //     5
    //     6
    //
    //     7
    //     8
    //
    //     9
    //     0
    //
    //     9
    //     1
    //     (an extra character)
}
```

`fileIn.get()`: This function reads the very next character from the input stream, unlike >> which skips whitespace. It reads spaces, digits, and newline characters (\n) alike.

#### Reading files boilerplate (6 steps)

1. Include header
2. Declare file stream
3. Open file
4. Check for error opening
5. Read/Write data
6. Close files

#### Reading files boilerplate 1 (from lecture slides)

```c++
#include <fstream>
#include <iostream>

using namespace std;
int main (){
    ifstream myDataIn ("FILENAME");
    if (myDataIn.fail()){
        cerr << "Could not open \"FILENAME"\"" << endl;
        return -1;
    }

    char x; // or int, double, etc.
    while (!myDataIn.eof()){
        myDataIn >> x;
        // do something or cout
    }

    myDataIn.close();
    return 0;
}
```

##### A breakdown

1. Setup:
   _ myDataIn opens the file XY.
   _ The check myDataIn.fail() passes. \* The file cursor is at the beginning: |XY

2. First Loop Iteration:

   - `!myDataIn.eof()` is true. The eof flag has not been set.
   - The loop body runs.
   - `myDataIn >> x;` reads the character 'X'. The variable x now holds 'X'.
   - The file cursor is now between X and Y: X|Y
   - Your code does "marvelous things" with the value 'X'.

3. Second Loop Iteration:

   - `!myDataIn.eof()` is still true. The last read was successful.
   - The loop body runs.
   - `myDataIn >> x`; reads the character 'Y'. The variable x now holds 'Y'.
   - The file cursor is at the end of the file: XY|
   - Your code does "marvelous things" with the value 'Y'.

4. Third Loop Iteration (The "Extra" Loop):

   - `!myDataIn.eof()` is STILL TRUE! The eof flag has not been set because the last read of 'Y' was successful. The program doesn't know it's at the end yet.
   - The loop body runs again.
   - `myDataIn >> x;` is executed. The read operation fails because there is nothing left to read.
   - The stream myDataIn now enters a "fail" state, and the eof flag is finally set.
   - Crucially, the value of `x` is not changed. It still contains 'Y' from the last successful read.
   - Your code now does "marvelous things" with the old, stale value of `x`. It processes 'Y' for a second time, which is a bug.

5. Fourth Loop Check:
   - `!myDataIn.eof()` is now false. The loop finally terminates.

#### Reading files boilerplate 2 (the correct idiom according to gemini)

```c++
    while (myDataIn >> x) {
        // This code only runs if the read was successful
    }
```

Reading a File Line-by-Line: this is the most common and robust pattern for reading a text file.

```c++
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 1. Open the file
    // The ifstream object is created, and its constructor tries to open the file.
    std::ifstream fileIn("data.txt");

    // 2. Error Handling: Check if the file opened successfully
    // If the file couldn't be opened (e.g., doesn't exist, no permissions),
    // the stream object will be in a "fail" state.
    if (!fileIn) {
        std::cerr << "Error: Could not open file for reading." << std::endl;
        return 1; // Indicate an error
    }

    std.string line;
    // 3. The Standard Read Loop
    // - std::getline() attempts to read a line from fileIn and store it in 'line'.
    // - It then returns the stream object (fileIn).
    // - The while loop checks the state of the stream. If the read was successful,
    //   the stream is in a "good" state, which evaluates to 'true', and the loop runs.
    // - If the read fails (because it hit the end of the file), the stream is no
    //   longer "good", it evaluates to 'false', and the loop terminates correctly.
    while (std::getline(fileIn, line)) {
        // Process the line
        std::cout << line << std::endl;
    }

    // 4. Close the file
    // File streams are automatically closed when the object (fileIn) goes out of scope
    // at the end of the function. This is part of a C++ principle called RAII.
    // You can also close it explicitly if you want to.
    fileIn.close();

    return 0;
}
```

### Alternative: Reading Word-by-Word

The same principle applies if you want to read whitespace-separated data.

```cpp
// (Includes and file opening are the same as above)

std::string word;
// The loop condition is now the extraction operator.
// It attempts to read a "word", and the loop continues as long as it succeeds.
while (fileIn >> word) {
    // Process the word
    std::cout << "Read word: " << word << std::endl;
}
```

### Summary of Best Practices:

1.  **Initialization:** Create an `ifstream` object to open the file.
2.  **Error Check:** Immediately check the state of the stream object (`if (!fileIn)`) to ensure the file was opened successfully.
3.  **Loop Condition:** Place the read operation (`std::getline` or `>>`) directly inside the `while` loop's condition. This is the most important step for safety.
4.  **Automatic Closing:** Rely on the object's destructor to close the file automatically when it goes out of scope. Explicitly calling `.close()` is optional but can be used for clarity.

#### `ofstream`

#### Writing files

use it like cout

```c++
ofstream myOutPut ("filename.txt");
// `>>` is Extraction operator
myOutput << "this goes to a file";
```

#### Writing files boilerplate

```c++
#include <fstream>
#include <iostream>

using namespace std;
int main(){
    ofstream fileOut("Filename");
    if (fileOut.fail()){
        cout << "Error opening file to write" << endl;
        return -1;
    }

    fileOut << "write out all your data";
    fileOut.close();
    return 0;
}
```

#### fstream Takeaway

- `ifstream` and `ofstream` comes from `fstream` class

##### operator overloading

The shift operator (>> & <<) and extraction/insertion operators are the same symbols.

- `<<` (Left Shift): Shifts the bits of a number to the left by a specified number of positions. The new empty bit positions on the right are filled with zeros. This is a fast way to multiply by powers of 2.

```c++
int a = 5;      // Binary: 00000101
nt b = a << 2; // Shift left by 2 positions
// Result is 20 (Binary: 00010100)
// Equivalent to 5 * 2^2
```

- `>>` (Right Shift): Shifts the bits of a number to the right. For unsigned numbers, the new empty bit positions on the left are filled with zeros. This is a fast way to divide by powers of 2.

```c++
int a = 20; // Binary: 00010100
int b = a >> 2; // Shift right by 2 positions
// Result is 5 (Binary: 00000101)
// Equivalent to 20 / 2^2
```

How does the compiler know which one to use?

The compiler looks at the types of the operands.

- If you write int << int, it knows you mean a bitwise shift.
- If you write ostream << int, it knows you mean stream insertion.

* `>>` in `cin >>` is an **Extraction Operator**
* `<<` in `cout <<` is an **Insertion Operator** (point to where the data is flowing)
