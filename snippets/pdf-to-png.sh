# pdf to png (img), -monochrome
convert -density 300 Doxygen.pdf -background white -alpha remove -colorspace gray -depth 4 out.png
convert -append `ls -1 *.png | sort -n | tr '\n' ' '` all.png

PDF=$1
IMG=${PDF%.*}
convert              \
    -verbose         \
    -density 150     \
    -trim            \
    $PDF             \
    -quality 100     \
    -sharpen 0x1.0   \
    ${IMG}.jpg

# ppt -> pdf
libreoffice --headless --invisible --convert-to pdf *.ppt

# file -> pdf
unoconv -f pdf file

# crop pdf
pdfcrop file.pdf cropped.pdf
