from __future__ import print_function
import sys
import numpy as np
from IPython import embed

def help():
    print("This program takes debugging map output and format it in C")
    print("Example Usage: python {0} map.txt".format(sys.argv[0]))

# struct maze_cell {
#     char s_open;
#     char w_open;
#     char n_open;
#     char e_open;
# };
#
# struct maze_map {
#     maze_cell map[30][30]; // hold the maze map
# };

def get_struct_str(printed_map, cell_x, cell_y):
    #1 is open; 0 is closed
    ret_str = ''
    lut = {True: 0, False: 1}
    upper_wall = printed_map[cell_y - 1][cell_x] == '-'
    lower_wall = printed_map[cell_y + 1][cell_x] == '-'
    left_wall = printed_map[cell_y][cell_x - 1] == '|'
    right_wall = printed_map[cell_y][cell_x + 1] == '|'
    ret_str += "    cur_cell.s_open = {0};\r\n".format(lut[lower_wall])
    ret_str += "    cur_cell.w_open = {0};\r\n".format(lut[left_wall])
    ret_str += "    cur_cell.n_open = {0};\r\n".format(lut[upper_wall])
    ret_str += "    cur_cell.e_open = {0};\r\n".format(lut[right_wall])
    return ret_str

def main(file_path = "map.txt"):
    print_str = '#include "make_map.h"\r\n\r\n'
    print_str += "void make_map(maze_map* allocated_struct) {\r\n    maze_cell cur_cell;\r\n    "
    cell_coordinates = [(i, j) for i in range(60) for j in range(60) if i % 2 == 1 and j % 2 == 1]
    with open("map.txt") as f:
        printed_map = f.readlines()

    for x, y in cell_coordinates:
        print_str += '\r\n'
        print_str += get_struct_str(printed_map, x, y)
        print_str += "    allocated_struct->map[{0}][{1}] = cur_cell;\r\n".format(int(x / 2), int(y / 2)) #ensure it works correctly in python3

    print_str += '}'
    print(print_str)

if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
    else:
        main()
