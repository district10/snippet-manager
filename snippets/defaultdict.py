from collections import defaultdict
evaluation_info = defaultdict(dict)
evaluation_info['one']['two'] = {}
# evaluation_info['one1']['two2']['three3'] = {}

Tree = lambda: defaultdict(Tree)
nest = Tree()
nest['one1']['two2']['three3'] = {}
