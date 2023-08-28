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
# Expressions
- Series of operands that are reduced to a single value
- Expressions like `12 / 3 * 2` are executed by a set of priorities known as precendence
    - Ex: if you don't use parentheses, the above value will result to 8. But if you put parentheses `12 / (3*2)`, then the result is 2. This is like PEMDAS
    - If the two operators like a `*` and a `/` are in the same line, then the program executes from left to right. 
    - Right to left execution would would look like this: `A = B = 3;`, because first B is assigned the value of 3, and then A is assigned the value of B
# Types of Expressions
Primary Expressions
- These only have one operand with no operator. Like `A` or like `3.14`. These are just items that aren't having any operations executed on them


Postfix Expressions
- Have one operand followed by one operator
- Examples include:
    - Incrementing: `i++;` Because the ++ is incrementing the variable i
    - Function calls: `addNumbers();` The function name is the operand and the parentheses is the operator since the parentheses are doing something to the word
    - Decrementing: `i--;` Because the -- is decrementing the variable i


Prefix Expressions
- having the operator go first then the operand after
- different thatn postfix operators because in this case, the operation takes place before the expression that contains the operator is evaluated
- Examples include:
    - Prefix increment and prefix decrement: `++i` and `--i`. These are used to add or subtract one from a variable.


Unary Expressions
- has one operator and one operand, and the operator comes before the operand
- Examples include:
    - converting values to other data types (casting): `(int) x` or `(int) 3.4`
    - basic plus and minus: `... + x` or `... - x`, where it is the operator and then operand


Binary Expressions
- Have a setup of operand-operator-operand
-Examples include:
    - Basic addition and subtraction: `x + y` or `x - y` Here x and y are the operands and the math symbol is the operator

# Precedence
- Operators have an order of which they execute, and you can refer to a list of precedence
- For example, `&&` comes before `||` in if/or statements. You can use parentheses to be same. 

# Associativity
- Associativity in programming refers to the order in which operations of the same precedence are performed when they appear consecutively in an expression. It determines whether operations are evaluated from left to right or from right to left
- left-to-right: `3 * 8 / 4 % 4 * 5` -> `((((3 * 8) / 4) % 4) * 5)` This goes from left to right because every operation in here has the same precedence
- right-to-left: `a += b *= c -= 5` -> `(a += (b *= (c -=5)))` This goes from right to left because the operations on the right have higher precedence