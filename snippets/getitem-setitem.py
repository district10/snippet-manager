class Building(object):
    def __init__(self, floors):
        self._floors = [None]*floors
    def __setitem__(self, floor_number, data):
        self._floors[floor_number] = data
    def __getitem__(self, floor_number):
        return self._floors[floor_number]

building1 = Building(4)
building1[0] = 'Reception'
building1[1] = 'ABC Corp'
building1[2] = 'DEF Inc'
print( building1[2] )

#   The [] syntax for getting item by key or index is just syntax sugar.
#
#   When you evaluate a[i] Python calls a.__getitem__(i) (or type(a).__getitem__(a, i),
#   but this distinction is about inheritance models and is not important here).
#   Even if the class of a may not explicitly define this method, it is
#   usually inherited from an ancestor class.
