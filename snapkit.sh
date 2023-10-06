#! /bin/env sh
# -*- mode:shell-script; coding:utf-8-unix; -*-

##  @file snapkit.sh
##  @brief snapkit.sh
##
##  snapkit.sh
##
##  Copyright 2017 hanepjiv
##
##  @author hanepjiv <hanepjiv@gmail.com>
##  @copyright The MIT License (MIT) / Apache License Version 2.0
##  @since 2017/01/01
##  @date 2023/10/07

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
         -o -name     LICENSE-\*                          \
         \) \
             -exec sed -i -E "s@${1}@${2}@g" {} \;
}
# =============================================================================
snapkit_(){
    local AUTHOR=${1}
    local MAIL_NAME=${2}
    local MAIL_DOMAIN=${3}
    local TARGET=${4}
    local TARGET_DIR="${TARGET}/orig"
    local TARGET_LOWER=`echo ${TARGET} | tr [A-Z] [a-z]`
    local TARGET_UPPER=`echo ${TARGET} | tr [a-z] [A-Z]`
    local TODAY=`date +%Y/%m/%d`
    local YEAR=`date +%Y`
    # -------------------------------------------------------------------------
    if [ -d ${TARGET} ] ; then
        echo ${TARGET} already exists.
        exit 1
    fi
    # -------------------------------------------------------------------------
    mkdir ${TARGET}
    cp -r ${ROOT} ${TARGET_DIR}
    cd ${TARGET_DIR}
    rm -rf .git .gitignore snapkit.sh
    replace_ %%AUTHOR%% ${AUTHOR}
    replace_ %%MAIL_NAME%% ${MAIL_NAME}
    replace_ %%MAIL_DOMAIN%% ${MAIL_DOMAIN}
    replace_ snapkit ${TARGET_LOWER}
    replace_ SNAPKIT ${TARGET_UPPER}
    replace_ %%TODAY%% ${TODAY}
    replace_ %%YEAR%% ${YEAR}
    mv snapkit.pc.in ${TARGET_LOWER}.pc.in
    mv include/snapkit include/${TARGET_LOWER}
    mv src/snapkit.cc src/${TARGET_LOWER}.cc
    cd ${CURRENT_DIR}
    echo create ${TARGET}
}
# =============================================================================
usage_() {
    cat <<EOF 2>&1
Usage: ${0}

        [-h | --help] -a <AUTHOR> [-m <MAIL_NAME>] -d <MAIL_DOMAIN> <TARGET>
        -h, --help              : print this help message
        -a <AUTHOR>             : author name
        -m <MAIL_NAME>          : mail address name. <MAIL_NAME>@<MAIL_DOMAIN>
        -d <MAIL_DOMAIN>        : mail address domain. <MAIL_NAME>@<MAIL_DOMAIN>
        <TARGET>                : target name
EOF
}

# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
AUTHOR=""
MAIL_NAME=""
MAIL_DOMAIN=""
TARGET=""

if [ ${#} -lt 1 ]; then
    usage_
    exit 0
fi

while [ ${#} -gt 0 ]; do
    case ${1} in
        -h | --help)    usage_;                 exit 0  ;;
        -a)             AUTHOR=${2};            shift 2 ;;
        -m)             MAIL_NAME=${2}          shift 2 ;;
        -d)             MAIL_DOMAIN=${2}        shift 2 ;;
        *)              TARGET=${1}             shift 1 ;;
    esac
done

if [ -z "${AUTHOR}" ]; then
   echo "invalid argument: -a <AUTHOR>"
   exit 1
fi

if [ -z "${MAIL_NAME}" ]; then
    MAIL_NAME=${AUTHOR}
fi

if [ -z "${MAIL_DOMAIN}" ]; then
   echo "invalid argument: -d <MAIL_DOMAIN>"
   exit 1
fi

if [ -z "${TARGET}" ]; then
   echo "invalid argument: <TARGET>"
   exit 1
fi

echo AUTHOR=${AUTHOR} MAIL_NAME=${MAIL_NAME} MAIL_DOMAIN=${MAIL_DOMAIN} TARGET=${TARGET}
snapkit_ ${AUTHOR} ${MAIL_NAME} ${MAIL_DOMAIN} ${TARGET}
