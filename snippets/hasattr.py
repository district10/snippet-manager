try:
    doStuff(a.property)
except AttributeError:
    otherStuff()

if hasattr(a, 'property'):
    doStuff(a.property)
else:
    otherStuff()
