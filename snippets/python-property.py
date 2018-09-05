class Celsius:
    def __init__(self, temperature = 0):
        self.temperature = temperature
    def to_fahrenheit(self):
        return (self.temperature * 1.8) + 32
    def get_temperature(self):
        print("Getting value")
        return self._temperature
    def set_temperature(self, value):
        if value < -273:
            raise ValueError("Temperature below -273 is not possible")
        print("Setting value")
        self._temperature = value
    temperature = property(get_temperature,set_temperature)
    # property(fget=None, fset=None, fdel=None, doc=None)

class Celsius:
    def __init__(self, temperature = 0):
        self._temperature = temperature
    def to_fahrenheit(self):
        return (self.temperature * 1.8) + 32
    @property
    def temperature(self):
        print("Getting value")
        return self._temperature
    @temperature.setter
    def temperature(self, value):
        if value < -273:
            raise ValueError("Temperature below -273 is not possible")
        print("Setting value")
        self._temperature = value
