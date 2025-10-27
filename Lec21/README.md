## Four uses of `const`

1. variable modifier
2. parameter modifier
3. pointer modifier
4. member function modifier

- const is modifying the datatype. **Could place in front of or behind the datatype. Typically ahead of the datatype**
- compiler error if try to change constant value

### Variable Modifier

```c+

const double PI_D = 3.14159265;
float const PI_F = 3.141f;

```

### parameter modifier

```c++
// the print function should not modify the VAKYE
void print (const vector<int>& VEC){
    for (size_t i = 0; i < VEC.size(); i++){
        cout << VEC[i] << " " ;
    }
}
```

### pointer modifier

```c++
// pPI pointer should not modify the value it is pointing at
const float * pPI= new float(3.14f);

// P_pi should not point at a different address
float * const P_pi = new float(3.14f);

// P_PI pointer should not point at a different address nor modify the value it is pointing at
const float * const P_PI= new float(3.14f);
```

### functions with const

```c++
float * circle_area(const float * const P_PI, const float R){
    return new float (*P_PI * R * R)
}

const float * const P_PI = generatePiPrecision(2);
float * pCircleArea = circle_area(P_PI, 2.0f);
```

### Function Modifier

```c++
// Zombie.h
class Zombie {
    public:
        Zombie(std::string);
        // the getName function SHOULD NOT modify the callee
        std::string getName() const;
    private:
        std::string name;
}

// Zombie.cpp
string Zombie::getName() const { // not modify the callee
    return _name;
}
```

- getter (in a class) in general will be marked `const` (bc they won't change the instance)

- callee and caller in a function
- constant function: can't change memeber data

### Object Terminology

```c++
string Zombie::getName() const {
    return _name;
}

void Zombie::greet(const Zombie * pOther) const { // not modify the callee
    // const objects can only call const functions, so getName has to be a const function
    cout <<< "Hi " << pOther->getName() << endl;
    cout << "I'm " << getName() << endl; // the callee's name
}

Zombie bill("Bill");
Zombie ted("Ted");

ted.greet(&bill); // Hi Bill, I'm Ted

```

### this

`this` is a pointer to the callee (to self)

you mark a functoin const unless it doesn't have a reason to not mark
