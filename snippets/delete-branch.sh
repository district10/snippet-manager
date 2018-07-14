# delete branch, remove branch
# local and remote
git push origin :dev

# local
git branch -d dev
# remote that already removed
git branch -d -r origin/dev
