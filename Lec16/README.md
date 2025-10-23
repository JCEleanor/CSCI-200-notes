## Reading paradigms

## Stream errors

## Formatting

- \n & endl & flush => \n might not show up, because it's not immediate. while endl flush the stream, but it's less efficient.
- iomanip (i/o manipulaton) lib to help formatting

```
#include <iomanip>
using namespace std;

```

### std::setw(int width) - Set Width

- What it does: Sets the width of the next output field. It specifies the minimum number of characters to be used for the next output
  operation.
- Key Behavior: It is not sticky. You must call setw immediately before each item you want to format.
- Default Alignment: By default, the output is right-aligned within the field.

Example:

```c++
cout << "*" << setw(10) << "hello" << "*" << endl;
cout << "*" << setw(10) << 123     << "*" << endl;
// Output:
// *     hello*
// *       123*
```

Notice the 5 spaces before "hello" and 7 spaces before "123" to make the total width 10.

### ✦ std::setfill(char fill_char)

an I/O manipulator from the <iomanip> library that allows you to specify the character used to pad output fields when the data
being printed is smaller than the width set by std::setw().

Here's a breakdown:

- Purpose: To change the default padding character (which is a space) to any other character you desire.
- Header: You must include <iomanip> to use std::setfill.
- Stickiness: std::setfill is sticky. Once you set a fill character on an output stream (like std::cout or a file stream), it remains in effect for all
  subsequent output operations on that stream until you explicitly change it again.
- Usage: It only has an effect when used in conjunction with std::setw(). If std::setw(N) is used, and the data you're printing takes up fewer than N
  characters, the remaining N - data_length characters will be filled with the character set by std::setfill.
