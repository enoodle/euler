#! /usr/bin/python3

from functools import lru_cache

ROMAN_VALUES = {
                "M": 1000,
                "D": 500,
                "C": 100,
                "L": 50,
                "X": 10,
                "V": 5,
                "I": 1,
               }

CHARS_TO_USE = 5 * ['M', ] + ['D', ] + 4*['C', ] + ['L', ] + \
        4*['X', ] + ['V', ] + 4*['I', ]


def value_from_string(st):
    if len(st) == 0:
        return 0
    v = value_from_string(st[1:])
    if len(st) >= 2 and ROMAN_VALUES[st[0]] < ROMAN_VALUES[st[1]]:
        return v - ROMAN_VALUES[st[0]]
    return v + ROMAN_VALUES[st[0]]


@lru_cache(maxsize=None, typed=False)
def minimal_form(n, chars=CHARS_TO_USE):
    '''
    '''
    if n <= 0:
        return []
    if len(chars) == 0:
        return []

    y = next(x for x in chars if ROMAN_VALUES[x] <= n)
    sol = [y, ] + minimal_form(n - ROMAN_VALUES[y],
                               tuple(chars[chars.index(y)+1:]))

    for minus, upper in [('I', 'X'), ('I', 'V'), ('X', 'C'),
                         ('X', 'L'), ('C', 'M'), ('C', 'D')]:
        value = ROMAN_VALUES[upper] - ROMAN_VALUES[minus]
        if value > n or upper not in chars:
            continue
        usable_chars = tuple([c for c in chars if
                              ROMAN_VALUES[c] < ROMAN_VALUES[upper]])
        candid = [minus, upper] + minimal_form(n - value, usable_chars)
        if n == value_from_string(''.join(candid)):
            if len(candid) < len(sol):
                sol = candid

    return sol


if __name__ == "__main__":
    pass
