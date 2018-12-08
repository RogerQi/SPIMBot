from __future__ import print_function
import sys

feature = "spimbot.s:"

def main(start_line_num, end_line_num):
    with open("profile.txt") as f:
        a = f.readlines()
    total_cycles = 0
    for line in a:
        ind = line.find(feature)
        if ind == -1:
            continue
        slice_start_ind = ind + len(feature)
        slice_end_ind = line[slice_start_ind:].find(":") + slice_start_ind
        current_mips_line = int(line[slice_start_ind:slice_end_ind])
        if current_mips_line >= start_line_num and current_mips_line <= end_line_num:
            cnt = int(line[:line.find("[")].replace(" ", ""))
            if cnt == -1: cnt = 0
            total_cycles += cnt
    print("Total cycles between specified lines:", total_cycles)

if __name__ == '__main__':
    start_num = int(sys.argv[1])
    end_num = int(sys.argv[2])
    main(start_num, end_num)
