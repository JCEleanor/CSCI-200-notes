### default contructor

A default constructor is a constructor that can be called with no arguments.

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

#### Why do we need default constructor

##### Rule of Five

If you define any of the five special member function yourself, the compiler might not generate the others automatically.

1. Destructor (~Polygon)
2. Copy Constructor (`Polygon (const Polygon& other)`)
3. Copy Assignment operator
4. Move Constructor
5. Move-assignment operator

Imagine a simple class. By default, this works fine:

```c++

    class MyData {
        int x;
    };

    MyData d1; // This works because the compiler generates MyData() for us.
```

Now, let's say we decide to manage how MyData is copied, so we add a copy constructor:

```c++
    class MyData {
         int x;
     public:
         // We added a copy constructor
         MyData(const MyData& other) {
         x = other.x;
         }
     };

    MyData d1; // COMPILER ERROR!
```

The line MyData d1; will now fail to compile. Why? Because by providing a copy constructor, we told the compiler, "I'm taking control of how objects are created/copied." The compiler, trying to be safe, no longer provides the automatic default constructor.

The fix:

```c++
     class MyData {
         int x;
     public:
         MyData() = default; // The fix: "Please give me the default constructor back."

         // Our custom copy constructor
         MyData(const MyData& other) {
             x = other.x;
         }
    };

    MyData d1; // This works again!
```
