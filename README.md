1.Introduction
      An intal can be taken as an abbreviation for “Integer of arbitrary length”.
      The main reason to implement such a data type is that the built-in datatypes have a limit up to which they can store numbers.
      Considering the “int” data type supported by C, it is known that it can only hold numbers not exceeding 4 bytes. (10 digits long) 
      Considering an even bigger number, suppose we use “Big Int”, even that can not exceed values greater than 8 bytes. (19 digits long)


      But there can be times, where we need to use larger numbers, which exceed 19 digits, and can not be stored in any built-in data type.


      Many applications include:
            1. Public-key cryptography, where the ciphertext conversion employs algorithms that use integers of 100 or more digits.
            2. Most importantly, to calculate fundamental mathematical constants like Pi up to million digits.
            3. In most mathematical calculation, like Gaussian integration: for example the value of sqrt(⅓)


2.Approach
        
        
In order to be able to implement basic functions like add, subtract, multiply, on such large numbers, one method which can be thought of, is using the “char” data type.
Since “char” has no restrictions on the size it can hold, it can hold even a million digits, of course, taking up more space.


The basic idea behind the implementation of this library is : 
      1. Store integers as strings.
            The number would be stored as a string, with ‘\0’ as the terminator.
      2. Dynamically allocate memory to the string
            Depending on the memory the result would require, allocate it dynamically
      3. Convert the string to an integer to perform atomic level addition, subtraction etc,
            Conversion is required because the values are stored as ASCII in a string.
            Subtracting 48 from each character of the string makes it an integer array.
      4. Convert it back to a string.
            This conversion is required to be able to store a result whose digits are more than what a builtin data type can store.

1. ADD 
Syntax and usage : char * intal_add(char * intal1 , char *intal2)
This function takes two arguments: the numbers to be added as a string.
The logic behind addition is elementary school addition, where digits are added from the left to right shifting the carry to the left.
It returns the resultant sum of the two numbers as a string.
Any leading zeros are trimmed off before returning the sum.


2. COMPARE
Syntax and usage : int intal_compare(char * intal1 , char *intal2)
It takes the two numbers to be compared as arguments and returns 0 if they are equal , 1 if intal1 >intal2 and -1 if intal1<intal2.
When the lengths of the two strings are not equal, it does not have to compare each digit, and returns 1 if the length of intal1 is more than intal2.
But when the lengths are equal, it proceeds to check each digit of the string and returns accordingly.


3. DIFFERENCE 
Syntax and Usage : char * intal_diff(char *intal1 ,char* intal2)
The two numbers to be subtracted are sent as parameters to the function.
It returns the absolute value of the difference. For doing so, it compares the two numbers and swaps them to ensure the smaller number is being subtracted from the larger one.


The subtraction done here is by subtracting each digit from left to right.
If the difference results in a negative answer, then 10 is added to the difference, and the borrow is updated to one.
This borrow is subtracted from the result in the next iteration.


4. MULTIPLICATION
Syntax and usage : char *intal_multiply(char* intal1 , char * intal2)
The product of the two numbers is returned as a string.
This function is an implementation of the intal_add, where it repeatedly adds the sub-products to obtain the final product.
Any leading zeros are trimmed off before returning the result.


5. MODULUS
Syntax and usage : char *intal_mod(char* intal1 , char * intal2)
Returns the remainder of the division of two numbers.
The logic behind dividing strings goes back to the elementary long-division method.
Where, the first number is compared with the second, till the length of the divisor, with the second number. If this value results in a negative, then we append a 0 to the start of the next comparison ( basically like a carry forward). If it results in a positive, then the divisor is continuously subtracted from the compared portion till it becomes lesser than the divisor. 
This is repeated till the end of the string.
The remainder is returned as the last subtracted value.


6. POWER
Syntax and usage: char* intal_pow(char* intal1 , unsigned int intal2)
Computes the power taking intal1 as the base and intal2 as exponent.
It follows the decrease and conquer method where , if the exponent is odd, it calculates intal1*(intal1^(intal2-1)) else , intal1^((intal2/2)*2) if it is even.
If the exponent is zero , it returns 1 . If the base is zero it returns 0.


7. FIBONACCI
Syntax and usage: char *intal_fibonacci(unsigned int n)
Returns the nth fibonacci number in the series.
It is computed by initializing the first two numbers to 0 and 1 , and then repeatedly adding them till the count becomes n.


8. FACTORIAL
Syntax and usage: char * intal_factorial( unsigned int n)
Returns the factorial of a number. Initialising the first number to start from 2, it is incremented till the value of n and is continuously multiplied with the previous result.
The result is stored in reverse order , and is reversed back before returning.


9. GCD
Syntax and usage: char* intal_gcd(char* intal1, char* intal2) 
It returns the Greatest common divisor of two intals . 
It is calculated using recursion , where : GCD(a,b)  returns b if a=0
And returns GCD(b mod a , a) otherwise.


10. BINOMIAL COEFFICIENT
Syntax and usage: char* intal_bincoeff(unsigned int n, unsigned int k)
It returns the value C(n.k) where n and k are two intals.
It follows the Bottom up approach where 
C(n,k)=C(n-1,k)+C(n-1,k-1)
C(n,0)= 1
C(n,1)=n
It recursively calls for C(n,k) while computing large numbers .


11. MINIMUM 
Syntax and usage : int intal_min(char **arr, int n)
It returns the minimum value in an array of intals.
Assuming the first element is the smallest , it compares it with all other elements to get the new smallest intal.


12. MAXIMUM 
Syntax and usage: int intal_max(char **arr, int n)
It returns the maximum value in an array of intals.
Assuming the first element is the largest , it compares it with all other elements to get the new largest intal.
 
13. SEARCH
Syntax and usage: int intal_search(char **arr, int n, const char* key)
It takes two arguments , the array and the element to be searched for.
Performs linear search on an array of intals. It returns the index of the element if found , else returns -1.


14. BINARY SEARCH
Syntax and usage: int intal_binsearch(char **arr, int n, const char* key)
Returns the index of the key element if found , else returns -1.
It divides the array into two parts , and if the key is less than the middle element , it searches for it in the first half. Else it searches in the second half.


15. SORT
Syntax and usage: void intal_sort(char **arr, int n)
It sorts a given array , inplace. It is done using a heap-sort algorithm  , where the parent element is larger than the child element .
Once this is achieved , the element in the first index is shifted to the last , second to the second-last and so on. 
This gives us the ascending order of elements .


16. COIN ROW
This function solved the coin-row problem using the dynamic programming approach.
There is a row of n coins whose values are some positive intals c1, c2, . . . , cn, not necessarily distinct. The goal is to pick up the maximum amount of money subject to the constraint that no two coins adjacent in the initial row can be picked up.
If there is only one coin of a particular value , then that is the optimum value.
For the nth type of coin , its effect with optimum value is checked . If it is greater than the optimum value obtained in the previous case it is updated else the previous optimum value is maintained. 
      CR(0) = 0
      CR(1) = Coin[1]
      CR(n) = MAXIMUM(CR(n - 1), Coin[n] + CR(n - 2));


3.Future work

Since this project has already covered most of the basic functionality required by any library, some additional functions that can be developed are :
   1. Absolute:  Returns the absolute value of an intal
   2. Binary: Return the binary string of an intal
   3. Bool: Convert the intal to a boolean value 
      For example: 
         1. bool(“1234”) , bool(“0001”) returns True
         2. bool(“0”) , bool( ) and bool(“”) returns False.  
        
If there were no restrictions on the implementations, it would have been easier to implement these functions with other built-in libraries like math.h, etc..
Exteding the library to negative numbers
A linked list representation of intal could also be implemented.