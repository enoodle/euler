#! /usr/bin/python

from roman import minimal_form, value_from_string


def p89():
    with open("p089_roman.txt", "r") as f:
        total = 0
        for line in f:
            minimal = minimal_form(value_from_string(line.strip()))
            total += len(line.strip()) - len(minimal)
    return total

if __name__ == "__main__":
    print("The value is: ", p89())
