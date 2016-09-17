from operator import itemgetter


def GreedyOneSKS(items, key, total_size):
    '''
    A Generator for the items that would be picked by a greedy algorithem
    Assumes each item can be picked only once
    '''
    for i, k in sorted(((x, key(x)) for x in items),
                       key=itemgetter(1), reverse=True):
        if k <= total_size:
            total_size -= k
            yield i

if __name__ == "__main__":
    pass
