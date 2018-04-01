// -resize 50%
convert tmp.png -resize 8x8 -colorspace Gray output.png
convert \
    -strip \
    -interlace Plane \
    -gaussian-blur 0.05 \
    -filter Lanczos \
    -quality 85% \
    itput.jpg output.jpg

# mogrify
