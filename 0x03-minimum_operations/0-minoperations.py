#!/usr/bin/python3
"""
Minimum Operations function.
"""

def minOperations(n):

    # Validations
    if n <= 1:
        return (0)

    str = 'H'
    copy = ''
    count = 0

    while len(str) < n:
        # Copy
        if n % len(str) == 0:
            copy = str
            count += 1
        
        # Paste
        str += copy
        count +=1
    return count
 