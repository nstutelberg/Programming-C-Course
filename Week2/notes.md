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

Ternary Expressions
    - These are if/else statements that can also be written shorthand in the form of ternary expressions
    - `int result = (x > y) ? x : y;`
    - In the above example, first `x > y` is evaluated. If it's true, then x is the result. If it's false or undefined, then y is the result

# Precedence
- Operators have an order of which they execute, and you can refer to a list of precedence
- For example, `&&` comes before `||` in if/or statements. You can use parentheses to be same. 

# Associativity
- Associativity in programming refers to the order in which operations of the same precedence are performed when they appear consecutively in an expression. It determines whether operations are evaluated from left to right or from right to left
- left-to-right: `3 * 8 / 4 % 4 * 5` -> `((((3 * 8) / 4) % 4) * 5)` This goes from left to right because every operation in here has the same precedence
- right-to-left: `a += b *= c -= 5` -> `(a += (b *= (c -=5)))` This goes from right to left because the operations on the right have higher precedence

# Side effects
- These are actions that occurs from the evaluation of an expression
- Ex: `x = 4` This is a side effect because x is taking on a new value
- Ex 2: `x = x + 4` This is a side effect because x is already 4, and the side effect of running this line of code is that x will be reassigned its value and will now have a value of 8

# Evaluating expressions
- Never modify a variable in an expression and use it more than one time because the result will be undefined. For example you can't do this: `y = x + 4 + x` because x is being used twice in same expression
- Also can't do `y = x++ * 3 - x;` because if x=2, and at the beginning it is incremented by one, then you don't know if that last x is going to be 2 or 3. You don't know if the last x is going to use the original x or the x that has been modified within the expression
- If you write code like this, the result will be `undefined`

# Type conversions
- There are two types of type conversions
- Implicit   
    - This is when a compiler automatically does a type conversion. Like if you do `int + float`, the compiler will convert the int to a float so it is like `float + float`
    Ex: `x = 3 * 5.0` will convert to `x = 3.0 * 5.0`
- Explicit
    - This is when you convert the data yourself
    - Example
        - Converting from a string to an int with `double x;` then `x = 3 / 2;`. The result will be 1 and NOT 1.5, because we did integer division here. 
        - To achieve the value of 1.5, you would need to do `x = (double)3/2;`, since now it converts this to double division and you get `3.0/2.0` which is `1.5`

# Statements
- A statement causes an action to be performend by the program. An example is `3 + a;`. 
    - This is just declaring `3+a` and not using it anywhere. It is not storing the value either, so it is useless
- An expression is turned into an expression statement by placing a semicolon after it. You know that if you do `expression;` or `i++`, that that line was executed and side effects were all completed
- There are 11 types of statements, but we are only going to talk about 4 of them

Null statement
    - `;`
    - This statement is just a semicolon. You do these maybe in a loop where you want to pass over or continue past the block of code. Just use the null statmenet when no action is required

Expression statement
    - `int x = 5` or `int result = x + y`
    - A statement that consists of an expression, which is a combination of values, variables, operators, and function calls that can be evaluated to produce a value.
    - An expression statement doesn't necessarily have to change the state of the program, but it can be used to calculate a value, which can then be used elsewhere in the program.

Here are a few examples of expression statements in different programming languages:
Return statement
    - `return expression` this will return the `expression` value
    - All functions including main must have a return statement. When there is no return statement at the end of teh function the system inserts a void return value

Compound statement
    - This is a unit of code consisting of zero or more statements, also known as a block
    - Groups statements together into one entity. 
    - Basically means anything that is contained within a `{}`
    - Ex: `int main() {       <mycodehere>        }`

# Semicolons
- Every declaration in C is terminated by a semicolon and most statements are terminated by one
- Just make sure not tu use them when importing modules or libraries. Like it should be `#include <stdio.h>` and NOT `#include <stdio.h>;`
- If you don't use a semicolon in the code, the program acts like the two lines are just one big line that are stored in different lines. You want to end each line with a semicolon 

