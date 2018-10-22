class AttributeDictionary(dict):
    __getattr__ = dict.__getitem__
    __setattr__ = dict.__setitem__

import json
data = json.loads(json_str, object_hook=AttributeDictionary)
