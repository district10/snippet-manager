raise NotImplementedError()
raise NotImplementedError       # 一样的

raise NotImplemented()
raise NotImplemented
# https://help.semmle.com/wiki/display/PYTHON/NotImplemented+is+not+an+Exception
NotImplemented is not an Exception, but is often mistakenly used in place of
NotImplementedError. Executing raise NotImplemented or raise NotImplemented()
will raise a TypeError. When raise NotImplemented is used to mark code that is
genuinely never called, this mistake is benign. However, should it be called,
then a TypeError will be raised rather than the expected NotImplemented, which
might make debugging the issue difficult.

The correct use of NotImplemented is to implement binary operators. Code that
is not intended to be called should raise NotImplementedError.

# https://stackoverflow.com/questions/2052390/manually-raising-throwing-an-exception-in-python
raise ValueError('A very specific bad thing happened.')

def demo_bad_catch():
    try:
        raise ValueError('Represents a hidden bug, do not catch this')
        raise Exception('This is the exception you expect to handle')
    except Exception as error:
        print('Caught this error: ' + repr(error))

>>> demo_bad_catch()
Caught this error: ValueError('Represents a hidden bug, do not catch this',)

try:
    some_code_that_may_raise_our_value_error()
except ValueError as err:
    print(err.args)

logger = logging.getLogger(__name__)

try:
    do_something_in_app_that_breaks_easily()
except AppError as error:
    logger.error(error)
    raise

# python 3, chain exception
raise RuntimeError('specific message') from error
