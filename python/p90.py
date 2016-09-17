#! /usr/bin/python3

from itertools import combinations


SQUARES = [1, 4, 9, 16, 25, 36, 49, 64, 81]


def is_valid(ca, cb):
    ca = add_6_9(ca)
    cb = add_6_9(cb)
    for sq in SQUARES:
        d1, d2 = divmod(sq, 10)
        if d1 not in ca or d2 not in cb:
            if d2 not in ca or d1 not in cb:
                return False

    return True


def add_6_9(tp):
    if 6 in tp and 9 not in tp:
        return tuple([x for x in tp] + [9, ])
    if 9 in tp and 6 not in tp:
        return tuple(sorted([x for x in tp] + [6, ]))
    return tp


def p90():
    tot = 0
    found = set()
    for ca in combinations(range(10), 6):
        for cb in combinations(range(10), 6):
            if is_valid(ca, cb):
                if ca+cb not in found:
                    found.add(ca+cb)
                    found.add(cb+ca)
                    tot += 1

    return tot


if __name__ == "__main__":
    print("The value is ", p90())
