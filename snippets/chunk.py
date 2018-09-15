# chunk array/list by length
def chunks(arr, n):
    for i in range(0, len(arr), n):
        yield arr[i:i + n]
