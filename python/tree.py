#! /usr/bin/python

class Tree():

        def __init__(self,left_sun=None,right_sun=None,
                        right_father=None,left_father=None,
                        value=0):
                self.lsun = left_sun
                self.rsun = right_sun
                self.rfather = right_father
                self.lfather = left_father
                self.val = value

        def set_rsun(self,right_sun):
                self.rsun = right_sun
        def set_lsun(self,left_sun):
                self.lsun = left_sun

        def get_rsun(self):
                return self.rsun
        def get_lsun(self):
                return self.lsun

        def set_right_father(self,rfather):
                self.rfather = rfather

        def get_right_father(self):
                return self.rfather

        def set_left_father(self,lfather):
                self.lfather = lfather

        def get_left_father(self):
                return self.lfather

        def get_rbro(self):
                fa = self.get_right_father()
                if not fa:
                        return None
                return fa.get_rsun()
        
        def get_lbro(self):
                fa = self.get_left_father()
                if not fa:
                        return None
                return fa.get_lsun()

        def set_val(self,value):
                self.val = value

        def make_rsun(self,rvalue):
                if self.get_rsun():
                        print "right sun already existed"
                rbro = self.get_rbro()
                right_sun = Tree(left_father=self,right_father=rbro,value=rvalue)
                if rbro:
                        rbro.set_lsun(right_sun)
                self.set_rsun(right_sun)

        def make_lsun(self,lvalue):
                if self.get_lsun():
                        print "left sun already existed"
                lbro = self.get_lbro()
                left_sun = Tree(right_father=self,left_father=lbro,value=lvalue)
                if lbro:
                        lbro.set_rsun(left_sun)
                self.set_lsun(left_sun)

        def print_lcr(self):
                left_sun = self.get_lsun()
                if left_sun:
                        left_sun.print_lcr()
                print self.val ,
                right_sun = self.get_rsun()
                if right_sun:
                        right_sun.print_lcr()




if __name__ == "__main__":
        tr = Tree(value = 10)
        tr.make_rsun(5)
        tr.make_lsun(11)
        tr.print_lcr()

