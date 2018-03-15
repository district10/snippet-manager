// https://github.com/district10/blog/issues/15
ffmpeg -i input.mp4 \
    -vf scale=180:-1 \
    -c:v libx264 \
    -preset slow -crf 22 \
    -c:a copy \
    output-width180.mp4
