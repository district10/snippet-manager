// remove exif
convert <input file> -strip <output file>
jpegtran -copy none image.jpg > newimage.jpg
