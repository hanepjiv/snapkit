#! /bin/env sh
# -*- mode:shell-script; coding:utf-8-unix; -*-

##  @file snapkit.sh
##  @brief snapkit.sh
##
##  debug.h
##
##  Copyright 2014 hanepjiv
##
##  @author hanepjiv <hanepjiv@gmail.com>
##  @copyright The MIT License (MIT)
##  @since 2016/01/09
##  @date 2016/10/24

# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
CURRENT_DIR="${PWD}"
ROOT="$(cd $(dirname ${BASH_SOURCE:-$0}); pwd)"

# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
replace_(){
    if [ ${#} -ne 2 ]; then
        exit 1
    fi
    # -------------------------------------------------------------------------
    find ./ -type f \
         \( -name          \*.in        -o -name    \*.sh \
         -o -name CMakeLists.txt        -o -name \*.cmake \
         -o -name           \*.h        -o -name     \*.c \
         -o -name          \*.hh        -o -name    \*.cc \
         -o -name         \*.hpp        -o -name   \*.cpp \
         -o -name        \*.toml                          \
         -o -name         .hgsub \) \
         -exec sed -i -E "s@${1}@${2}@g" {} \;
}
# =============================================================================
snapkit_(){
    local TARGET=${1}
    local TARGET_LOWER=`echo ${TARGET} | tr [A-Z] [a-z]`
    local TARGET_UPPER=`echo ${TARGET} | tr [a-z] [A-Z]`
    # -------------------------------------------------------------------------
    if [ -e ${TARGET} ] ; then
        echo ${TARGET} already exists.
        exit 1
    fi
    # -------------------------------------------------------------------------
    cp -r ${ROOT} ${TARGET}
    cd ${TARGET}
    rm -r .hg .hgsubstate snapkit.sh
    replace_ snapkit ${TARGET_LOWER}
    replace_ SNAPKIT ${TARGET_UPPER}
    mv snapkit.pc.in ${TARGET_LOWER}.pc.in
    mv include/snapkit include/${TARGET_LOWER}
    mv src/snapkit.cc src/${TARGET_LOWER}.cc
    cd ${CURRENT_DIR}
    echo create ${TARGET}
}

# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
if [ ${#} -ne 1 ]; then
    exit 1
fi

snapkit_ ${1}
