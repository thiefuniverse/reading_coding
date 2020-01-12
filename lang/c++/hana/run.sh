#!/bin/bash

root_directory=$(git rev-parse --show-toplevel)

if [ ! -d ./dep ]; then
	mkdir dep
fi

hana_version=v1.6.0.zip  # sync with boost v1.71.0
any_version=boost-1.71.0.zip
mpl_version=boost-1.71.0.zip

# get hana
if [ ! -d ./dep/hana ]; then
	cd dep
    wget https://github.com/boostorg/hana/archive/${hana_version}
	dir_unzip=$(unzip -Z -1 ./${hana_version} | head  -1)
    unzip ${hana_version}
	mv $dir_unzip hana
	rm -rf ${hana_version}
fi
cd $root_directory

# compile hana
if [ ! -f ./dep/hana/build/install/include/boost/hana.hpp ]; then
    cd ./dep/hana
    mkdir build && cd build
    # you need a clang compiler which support c++14
    cmake .. -DCMAKE_INSTALL_PREFIX=./install 
    cmake --build . --target install
fi
cd $root_directory

# get any
if [ ! -d ./dep/any ]; then
	cd dep
    wget https://github.com/boostorg/any/archive/${any_version}
	dir_unzip=$(unzip -Z -1 ./${any_version} | head  -1)
    unzip ${any_version}
	mv $dir_unzip any 
	rm -rf ${any_version}
fi
cd $root_directory

if [ ! -d ./dep/mpl ]; then
	cd dep
    wget https://github.com/boostorg/mpl/archive/${mpl_version}
	dir_unzip=$(unzip -Z -1 ./${mpl_version} | head  -1)
    unzip ${mpl_version}
	mv $dir_unzip mpl 
	rm -rf ${mpl_version}
fi
cd $root_directory

