# command line copy image to clipboard
function copy_image {
    xclip -selection clipboard -t `file -b --mime-type "$1"` -i "$1"
}
