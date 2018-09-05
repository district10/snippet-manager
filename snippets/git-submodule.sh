git submodule init
git submodule update
git submodule add git@gitlab.com:district10/snippets_private.git private

# remove
git submodule deinit <path_to_submodule>
git rm <path_to_submodule>
git commit -m "Removed submodule"
rm -rf .git/modules/<path_to_submodule>
