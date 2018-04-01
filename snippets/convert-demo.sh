for i in rotate shear roll hue saturation brightness gamma spiff dull \
         grayscale quantize despeckle reduceNoise addNoise sharpen blur \
         threshold edgedetect spread shade raise segment solarize swirl \
         implode wave oilpaint charcoal jpeg;
do
    convert main.jpg -preview ${i} -gravity south -box "#00000020" \
        -pointsize 36 -fill "#887ddd" -draw "text 0,0 '${i}'" out.${i}.jpg
done
montage out.*.jpg -tile 1x$(ls out.*.jpg | wc -l) -geometry 766x936 out.main.jpg
