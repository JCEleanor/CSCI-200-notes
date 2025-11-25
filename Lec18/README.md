### default contructor

```c++
class Polygon
{
public:
    Polygon() = default;
};
```

Here's what `= default` does:

1.  Compiler-Generated Default Behavior: For certain special member functions (like constructors, destructors, copy/move constructors, and assignment operators), C++ can automatically generate an implementation if you don't provide one yourself. This generated implementation performs a standard, default action (e.g., for a default constructor, it initializes member variables according to their own default constructors or leaves built-in types uninitialized).

2.  Explicitly Requesting the Default: Sometimes, you might declare another constructor (e.g., Polygon(int x, int y);). If you declare any constructor, the compiler will not automatically generate a default constructor for you. If you still want the compiler's default, no-argument constructor, you can explicitly request it using = default;.

3.  Clarity and Control: Using = default; is a way to be explicit about your intent. It clearly states that you want the compiler'sstandard behavior for that function, rather than writing a custom implementation or accidentally suppressing the default behavior.
