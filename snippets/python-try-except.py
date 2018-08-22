try:
    firstaxis, parity, repetition, frame = _AXES2TUPLE[axes]
except (AttributeError, KeyError):
    _TUPLE2AXES[axes]  # validation
    firstaxis, parity, repetition, frame = axes
