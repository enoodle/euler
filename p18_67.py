#! /usr/bin/python

'''
from tree.py import tree


class WayTree(Tree):

        def __init__(self,family=None,insource=None):
                if insource and family:
                        print "ERROR: WayTree __init__ : both file and family!"
                        return
                if insource:
                        self._getWayFromFile(insource)
                else: 
                        Tree.__init__(family)

        def _getWayFromFile(self,insource):

                instream = open(insource)

                left_node = self
                right_node = left_node

                for line in insource:
                        intsList = [int(i) for i in line.split(" ") if i]
                        right_node.set_val(intsList[0])
                        for n in intsList[1:]:

#need to finish from here

                close (instream)
'''

def p18_67sol(InputFile):

        instream = open(InputFile)
        last_intsList = []
        intsList = [0]
        for line in instream:
                last_intsList = intsList
                intsList = [int(i) for i in line.split(" ") if i]
                for i in xrange(len(intsList)):
                        if i==0:
                                intsList[i]+=last_intsList[i]
                        else:
                                if i>=len(last_intsList):
                                        intsList[i]+=last_intsList[i-1]
                                else:
                                        intsList[i]+=max(last_intsList[i-1],last_intsList[i])
        print max(intsList)



if __name__ == "__main__":
        pass

