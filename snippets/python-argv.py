import sys
if __name__ == '__main__':
    argv1 = sys.argv[1] if len(sys.argv) > 1 else "default value 1"
    argv2 = sys.argv[2] if len(sys.argv) > 2 else "default value 2"

# get or default
def get_or_default(argv, index, default):
    return argv[index] if len(argv) > index else default
