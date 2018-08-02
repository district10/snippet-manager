pip install -U autopep8
find . -iname "*.py" | xargs autopep8 --in-place --aggressive
