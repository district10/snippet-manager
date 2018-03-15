convert -verbose -density 150 -trim test.pdf -quality 100 -flatten -sharpen 0x1.0 24-18.jpg
// -flatten is '-layers flatten', http://www.imagemagick.org/script/command-line-options.php#layers
//
// mogrify  -  resize an image, blur, crop, despeckle, dither, draw on, flip,
// join, re-sample, and much more. Mogrify overwrites the original image file,
// whereas, convert writes to a different image file
