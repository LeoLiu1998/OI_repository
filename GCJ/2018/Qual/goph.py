#! /usr/bin/python3
import sys

def write_to_file(val):
    f_out = open("testrecvive",'w')
    f_out.writelines(val)

def read_one_int():
    return int(input())

def read_next_two_int():
    two_int = [int(s) for s in input().split(" ")]
    return two_int

def push_int(val):
    assert len(val) == 2
    print(val[0],val[1])
    sys.stdout.flush()


def Gopher(A):
    if A % 3 == 0:
        colnum = A / 3
    else:
        colnum = 3*int(A/3) + 1
    fill_arr = [0 for i in range(colnum+1)]
    playground = [[0 for i in range(70)] for j in range(5)]
    while 1:
        for i in range(1,colnum):
            if not fill_arr[i-1]:
                print(2, i+1)
                sys.stdout.flush()
                coordinate = read_next_two_int()
                if coordinate[0] == 0 and coordinate[1] == 0:
                    return
                if coordinate[0] == -1 and coordinate[1] == -1:
                    return
                coordinate[0] -= 1
                coordinate[1] -= 1
                playground[coordinate[0]][coordinate[1]] = 1
                if not fill_arr[i-1]:
                    fill_arr[i-1] = playground[1][i-1] == 1 and playground[2][i-1] == 1 and \
                                    playground[3][i-1] == 1
                if not fill_arr[i]:
                    fill_arr[i] = playground[1][i] == 1 and playground[2][i] == 1 and \
                                    playground[3][i] == 1
                if not fill_arr[i+1]:
                    fill_arr[i+1] = playground[1][i] == 1 and playground[2][i] == 1 and \
                                    playground[3][i] == 1
    return

if __name__ == "__main__":
    t = read_one_int()
    for i in range(1, t + 1):
        A = read_one_int()
        Gopher(A)
