# membermethod, classmethod, staticmethod 三个层次
class A(object):
    def foo(self,x):
        print "executing foo(%s,%s)"%(self,x)

    # A classmethod, on the other hand, is a method that gets passed the class
    # it was called on, or the class of the instance it was called on, as first
    # argument.
    @classmethod
    def class_foo(cls,x):
        print "executing class_foo(%s,%s)"%(cls,x)

    # A staticmethod is a method that knows nothing about the class or instance
    # it was called on. It just gets the arguments that were passed, no
    # implicit first argument. It is basically useless in Python -- you can
    # just use a module function instead of a staticmethod.
    @staticmethod
    def static_foo(x):
        print "executing static_foo(%s)"%x

a=A()
a.foo(1)
a.class_foo(1)
a.static_foo(1)
