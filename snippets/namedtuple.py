>>> from collections import namedtuple
>>> Row = namedtuple('Row', ['first', 'second', 'third'])
>>> A = ['1', '2', '3']
>>> Row(*A)
Row(first='1', second='2', third='3')
