# throw exception
#       https://stackoverflow.com/questions/2052390/manually-raising-throwing-an-exception-in-python
raise ValueError('A very specific bad thing happened.')
raise Exception('This is the exception you expect to handle')

def demo_no_catch():
    try:
        raise Exception('general exceptions not caught by specific handling')
    except ValueError as e:
        print('we will not catch exception: Exception')

try:
    some_code_that_may_raise_our_value_error()
except ValueError as err:
    print(err.args)
