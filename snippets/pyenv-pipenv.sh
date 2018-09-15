curl -L https://github.com/pyenv/pyenv-installer/raw/master/bin/pyenv-installer | bash
# 安装完成后按照提示把下面三行加到 ~/.bashrc 或者 ~/.zshrc
#   export PATH="/home/tzx/.pyenv/bin:$PATH"
#   eval "$(pyenv init -)"
#   eval "$(pyenv virtualenv-init -)"
pip install --user pipenv

pyenv --version
pipenv --version


pipenv --python 3.7
pipenv install mypy --dev
pipenv install transforms3d
pipenv install cython
pipenv install git+https://github.com/jswhit/pyproj.git#egg=pyproj
pipenv install git+ssh://git@path/to.git#egg=spslam

pipenv install --dev
