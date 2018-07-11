# install miniconda
set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

# Install Miniconda2.
CONDA_PATH=/usr/local/miniconda2
wget https://repo.continuum.io/miniconda/Miniconda2-latest-Linux-x86_64.sh
bash Miniconda2-latest-Linux-x86_64.sh -b -p ${CONDA_PATH}

# Init python 2.7 environment.
${CONDA_PATH}/bin/conda env update -f py27_conda.yml

    name: py27
    dependencies:
      - python=2.7.15
      - protobuf
        - python-gflags

      - pip:
        - glog

# Clean up.
rm -f Miniconda2-latest-Linux-x86_64.sh
