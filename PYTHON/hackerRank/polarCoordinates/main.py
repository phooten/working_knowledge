# Date:         10-24-2021
# File:         main.py
# Version:      1.0
# Status        INCOMPLETE
# Contributers	Parker Hooten
#
# Purpose:      to complete a problem statement from hackerrank:
# 				https://www.hackerrank.com/challenges/polar-coordinates/problem


# to run:
# python3 main.py < input.txt

#   sample input:  
#                   1+2j
#
#   sample output:  
#                   2.23606797749979 
#                   1.1071487177940904

import cmath

z = input()
print(z)
z = complex(z);
print(z)
z = cmath.polar(z)
print(z)

print(z[0])
print(z[1])
