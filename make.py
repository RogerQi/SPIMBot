#!/usr/bin/env python
from __future__ import print_function
import os
import sys

dependency_dir = ["./LIB/"]
assembled_file_path = "./spimbot.s"

def print_help():
    print("Example Usage: python {0} test_puzzle_solver".format(sys.argv[0]))
    print("The above command would acquire main/test_puzzle_solver.s and assemble it with BSP/LIB to make a comprehensive file for submission")

def main():
    if sys.version_info < (3, 0):
        print("Please run the script in Python3!")
        sys.exit(1)
    try:
        assert len(sys.argv) == 2
        assert sys.argv[1].endswith(".s")
    except AssertionError:
        print("Malformed Parameters!")
        print_help()
        sys.exit(1)
    #assemble
    main_file_path = os.getcwd() + "/./main/" + sys.argv[1]
    visible_libs = []
    for sub_dir in dependency_dir:
        visible_libs += [os.path.join(dp, f) for dp, dn, filenames in os.walk(sub_dir) for f in filenames if f.endswith(".s")]
    assembled_file_content = "" #string that will hold the assembled file
    with open(main_file_path) as f:
        assembled_file_content += f.read()

    assembled_file_content += "\r\n\r\n#/***************End Main File***************/"
    assembled_file_content += "\r\n\r\n#/***************Start Lib File***************/\r\n"

    for lib_file_path in visible_libs:
        with open(lib_file_path) as f:
            assembled_file_content += f.read()

    with open(assembled_file_path, "w") as f:
        f.write(assembled_file_content)

    print("Finished!")

if __name__ == '__main__':
    main()
