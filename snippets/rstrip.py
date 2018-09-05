from builtins import float

class FormattedFloat(float):

    def __str__(self):
        return "{:.10f}".format(self).rstrip('0')
