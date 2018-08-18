#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import string
import sys

MIN_VALUE = 0
MAX_VALUE = 2 ** 32 - 1

if __name__ == "__main__":
    if 1 == len(sys.argv):
        min_len = 2
        max_len = 10
    else:
        min_len = int(sys.argv[1])
        min_len = int(sys.argv[2])

    for num in range(1, 4):
        pattern = ""
        for i in range(random.randint(min_len, max_len)):
            pattern = pattern + str(random.randint(MIN_VALUE, MAX_VALUE)) + "\t"
        pattern = pattern.strip()
        
        text = ""
        for _ in range(random.randint(1,4)):
            for i in range(random.randint(min_len, max_len)):
                text = text + str(random.randint(MIN_VALUE, MAX_VALUE)) + "\t"
            text += pattern + "\t"
            for i in range(random.randint(min_len, max_len)):
                text = text + str(random.randint(MIN_VALUE, MAX_VALUE)) + "\t"
        text = text.strip()
        
        output_filename = "tests/{:02d}.t".format( num )
        with open( output_filename, 'w+') as output:
            output.write(pattern)
            output.write('\n')
            output.write(text)
            
