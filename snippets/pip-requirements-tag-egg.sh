Requirements files are used to override a dependency with a local patch that
lives in version control. For example, suppose a dependency, SomeDependency
from PyPI has a bug, and you can’t wait for an upstream fix. You could
clone/copy the src, make the fix, and place it in VCS with the tag sometag. You’d
reference it in your requirements file with a line like so:

# tag, egg
git+https://myvcs.com/some_dependency@sometag#egg=SomeDependency
