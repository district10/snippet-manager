# files in vcs in cwd
git ls-files

git ls-tree -r HEAD --name-only # list all files in vcs

# all files that ever existed
git log --pretty=format: --name-status | cut -f2- | sort -u
