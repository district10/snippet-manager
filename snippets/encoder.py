import json
import dataclasses
import numpy as np
from enum import Enum

class PythonObjectEncoder(json.JSONEncoder):
    def default(self, obj: Any) -> Any:
        if dataclasses.is_dataclass(obj):
            return dataclasses.asdict(obj)
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, Enum):
            return obj.name
        if isinstance(obj, set):
            return list(obj)
        if callable(getattr(obj, 'to_json', None)):
            return obj.to_json()
        return json.JSONEncoder.default(self, obj)

def obj_dump_to_string(obj):
    return json.dumps(obj, cls=PythonObjectEncoder)
