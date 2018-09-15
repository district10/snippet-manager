# python 3.x only
def outer():
    string = ""
    def inner():
        nonlocal string
        string = "String was changed by a nested function!"
    inner()
    return string
