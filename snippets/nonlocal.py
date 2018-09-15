# python 3.x only
def outer():
    string = ""
    def inner():
        nonlocal string
        string = "String was changed by a nested function!"
    inner()
    return string

def outer():
    def inner():
        inner.string = "String was changed by a nested function!"
    inner.string = ""
    inner()
    return inner.string
