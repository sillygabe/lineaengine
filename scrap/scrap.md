# Linea Scraps

Your code may not compile when you use the `std` libraries because of sdl.
This folder contains datastructures that you can use instead of `std`.

# Array

```c++
array<int, 5> arr; 
```

Array - a class for static storage which also has useful methods and a for-range loop.
Works for any type of data.

# List

```c++
list<int> arr;
arr.add(10);
```

List - a dynamic array.

# String

```c++
string a = "foobar";
```

String - dynamic string class. Can be used with IO.
You can get cstring using string.get_cstring()
They support concatenation.

# Exception

Basically an exception.
You can use it with throw/cath.

# IO

```c++
outstream a = "foo"; //Opens the file "foo"
a("Hello, ", 10, "\n"); //Prints "Hello, 10" and newline
instream b = "bar"; //Opens the file "bar" for input
double foo; char bar;
b(foo, bar); //Inputs these variables from file "bar"
```

Input and output, you can use it with file you want.
Also `print`, `input`, `printerr` are predefined for your use.

# Pair

A pair structure just like in `std`.