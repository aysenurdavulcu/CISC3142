#Problem:
To make a calculator, allowing for the user-defined operator to add, subtract, multiply, divide or take the square root of two user-defined data inputs. 
Solution:
-The task is done by declaring a struct called “calculator”.  Data members in the struct are two “double” datatype objects for operands (“op1”,”op2”) and one “char” datatype operand for the operator (“operator”). 
- Enumeration is done for different operators that can be used. Default constructor and parameterized constructors are made for the two operands and one operator object. 
-The operands and operators have a set and get function used to store and return the user-defined values. In the Set operator function, a switch case is used to assign the “enum” operator based on the input. In the get operator function, a switch case is used to return the operator based on the value sorted in “operator”. 
- The “Calculate()” function is made to do perform calculations based on the operator. In this function, switch cases are used to see what operator is to be used by the user. The desired operator is used to perform the calculation of the two operands and return the result.  In the case of square root, only “op1” is used to perform the calculation.
-The “Display()” function is used to compensate for the squire root operator as it only requires one operand. If the statement is used to check if the squire root operator is used or not and the result is displayed accordingly.
