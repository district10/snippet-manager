if isinstance(obj, (tuple, list)):
    coordinates = obj
elif 'geometry' in obj:
    coordinates = obj['geometry']['coordinates']
else:
    coordinates = obj.get('coordinates', obj)
for e in coordinates:
    if isinstance(e, (float, int)):
        yield tuple(coordinates)
        break
    for f in coords(e):
        yield f
