git rm --cached path/to/file.txt # remove from git history
git commit --amend -CHEAD
git push

git filter-branch --tree-filter 'rm -f <path_to_file>' HEAD
git push origin --force --all
