#! /bin/env sh
# -*- mode:shell-script; coding:utf-8; -*-

# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
CURRENT_DIR="${PWD}"
ROOT="$(cd $(dirname ${BASH_SOURCE:-$0}); pwd)"

# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
snapkit_(){
    local TARGET=${1}
    local TARGET_LOWER=`echo ${TARGET} | tr [A-Z] [a-z]`
    local TARGET_UPPER=`echo ${TARGET} | tr [a-z] [A-Z]`
    # --------------------------------------------------------------------------
    echo create ${1}
    mkdir -p ${CURRENT_DIR}/${TARGET}
    cp -r ${HOME}/projects/tools/snapkit/trunk ${CURRENT_DIR}/${TARGET}/trunk
    cd ${CURRENT_DIR}/${TARGET}/trunk
    rm -r ./.hg ./snapkit.sh
    replace.sh snapkit ${TARGET_LOWER}
    replace.sh SNAPKIT ${TARGET_UPPER}
    mv snapkit.pc.in ${TARGET_LOWER}.pc.in
    mv include/snapkit include/${TARGET_LOWER}
    mv src/snapkit.cc src/${TARGET_LOWER}.cc
    cd ${CURRENT_DIR}
}

# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
if [ ${#} -ne 1 ]; then
    exit 1
fi

snapkit_ ${1}
