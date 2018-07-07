import json

class PythonObjectEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, set):
            return list(obj)
        return json.JSONEncoder.default(self, obj)

def obj_dump_to_string(obj):
    return json.dumps(obj, cls=PythonObjectEncoder)
