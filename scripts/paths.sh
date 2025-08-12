#!/bin/bash
##===================================================================
## 
## It is important to use this script to set all the necessary paths.
## 

# Path for where the binaries are for clang
# SET this.
export LLVM_INSTALL_DIR=/usr/lib/llvm-15
#export LLVM_INSTALL_DIR=/home/$USER/del/llvm-project/build/
#export LLVM_INSTALL_DIR=/home/$USER/bin/clang-10.0.0/ 

# Path where SystemC is installed
# SET this.
export SYSTEMC=/usr/local

# Path for systemc-clang source
export SYSTEMC_CLANG=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

# Path for the systemc-clang build directory
# SET this.
export SYSTEMC_CLANG_BUILD_DIR=$SYSTEMC_CLANG/build
##===================================================================

LLVMCOMPONENT=cppbackend
RTTIFLAG=-fno-rtti 
LLVMCONFIG=$LLVM_INSTALL_DIR/bin/llvm-config

# New llvm/clang uses flags that are different than GNU gcc's
# Alternatively, you can use gcc and g++, but some flags don't work.
export CC=clang
export CXX=clang++
export LLVM_CXX_FLAGS="`$LLVMCONFIG --cxxflags` -fno-aligned-allocation"

# Generate all the flags.
export LLVM_CXX_FLAGS="$LLVM_CXX_FLAGS -fvisibility-inlines-hidden"
export LLVM_LIBS=`$LLVMCONFIG --libs`
export LLVM_LD_FLAGS=`$LLVMCONFIG --ldflags`
export LLVM_LD_FLAGS=`echo $LLVM_LD_FLAGS | sed 's/ *$//g'`

