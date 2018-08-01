# CRS
class CoordinateReferenceSystem(GeoJSON):
    """
    Represents a CRS.
    """
    def __init__(self, properties=None, **extra):
        super(CoordinateReferenceSystem, self).__init__(**extra)
        self["properties"] = properties or {}
