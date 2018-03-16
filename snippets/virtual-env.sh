pip install virtualenv
export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python2.7
virtualenv -p /usr/bin/python2.7 my_project
source my_project/bin/activate
pip install -r requirements.txt
deactivate
