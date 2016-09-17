#! /usr/bin/python3


def distance(a, b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2


def is_right_angle(p, q, o=(0, 0)):
    dists = sorted([distance(p, q),
                    distance(p, o),
                    distance(q, o)], reverse=True)
    return dists[0] == dists[1] + dists[2]


def p91(n=50):
    found = set()
    tot = 0
    for x1 in range(n+1):
        for x2 in range(n+1):
            for y1 in range(n+1):
                for y2 in range(n+1):
                    p = (x1, y1)
                    q = (x2, y2)
                    if x1*y2 == x2*y1:
                        continue
                    if (p, q) not in found and is_right_angle(p, q):
                        found.add((p, q))
                        found.add((q, p))
                        tot += 1

    return tot


if __name__ == "__main__":
    print("The value is ", p91(2))
    print("The value is ", p91())
