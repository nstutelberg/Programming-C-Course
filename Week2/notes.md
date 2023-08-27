# Value literals or Constants
- By default, compilier interprets 123 as an integer. If you want to tell the compiler to treat it as a long, you need to specify that with `123L`
- Also by default, floating point numbers are interpreted as double. If you type in `3.14`, the compiler will interpret that as a double. If you want it to treat as a float, do `3.14F` or `3.14f`. 
# More info on floats
- Compiler passes both floats and doubles as doubles. Float are always converted to doubles. 
- for printf
    - %f, %e, %E all work for float and double values
- for scanf
    - %f is for float values
    - %lf is for double values
    - %LF is for long double values
# Variable 