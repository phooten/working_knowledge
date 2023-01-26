*   Size of datatypes change fron machine to machine


Data Types:
( a good reference chart is on pg. 28)

    integer:
    -   typically 32 bits or 4 bytes
    %i  ->  integer
    
    float:
    -   32 bits or 4 bytes
    %f  ->  floats
    %e  ->  scientific notation
    %g  ->  most asthetically pleasing

    double:
    -   64 bits or 8 bytes
    -   double percision of a float
    -   Unless explicitley written, all floating points are taken as doubles
        by the compiler. Append 'f' or 'F' to the number to call it a float: 12.5f
    %e, %g, %f  
    
    long:
    -   32 bits or 4 bytes
    -   %li, %lo, %lx
    
    char:
    -   8 bits or 1 byte
    %c  ->  prints out a character

    short:
    -   16 bits or 2 bytes
    -   %hi, %ho, %hx

    octals:
    -   numbers as base 8
    %o  ->  octal
    %#o ->  octal w/ leading 0
    
    hexadecimal:
    -   numbers as base 16
    %x  ->  hexadecimal (lowercase)
    %#x ->  hexadecimal w/ leading 0x
    %X  ->  hexadecimal (uppercase)

    _Complex
    _Imaginary