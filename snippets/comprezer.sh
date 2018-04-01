function _filesize() { cat "$1" | wc -c }

function _mogrify_until() {
    while (( `_filesize "$1"` > `_imgsize_threshold` )); do
        _mogrify "$1"
    done
}

function minify_all_pics() {
    SZ=`_imgsize_threshold`
    find xl/media -size +${SZ}c | while read img; do
        identify "$img" > /dev/null && pic_minify "$img"
    done
}

function full_path() { echo "$(cd "$(dirname "$1")"; pwd)/$(basename "$1")" }   # fullpath

function _bytes() { sed -e :a -e 's/\(.*[0-9]\)\([0-9]\{3\}\)/\1,\2/;ta' }      # format number

unzip -q $TMP
zip -q -r "$TMP" *
