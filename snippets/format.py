>>> print('%(language)s has %(number)03d quote types.' % {'language': "Python", "number": 2})
Python has 002 quote types.

>>> "Hello, {1}. You are {0}.".format(age, name)
'Hello, Eric. You are 74.'

>>> person = {'name': 'Eric', 'age': 74}
>>> "Hello, {name}. You are {age}.".format(name=person['name'], age=person['age'])
'Hello, Eric. You are 74.'

>>> person = {'name': 'Eric', 'age': 74}
>>> "Hello, {name}. You are {age}.".format(**person)
'Hello, Eric. You are 74.'

f"Hello, {name}. You are {age}."
class Comedian:
    def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def __str__(self):
        return f"{self.first_name} {self.last_name} is {self.age}."

    def __repr__(self):
        return f"{self.first_name} {self.last_name} is {self.age}. Surprise!"

# By default, f-strings will use __str__(), but you can make sure they use
# __repr__() if you include the conversion flag !r:
>>> f"{new_comedian}"
'Eric Idle is 74.'
>>> f"{new_comedian!r}"
'Eric Idle is 74. Surprise!'

>>> message = (
...     f"Hi {name}. "
...     f"You are a {profession}. "
...     f"You were in {affiliation}."
... )
>>> message

>>> message = f"""
...     Hi {name}.
...     You are a {profession}.
...     You were in {affiliation}.
... """
