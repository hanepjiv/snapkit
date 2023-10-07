#!/bin/env sh
# -*-coding:utf-8;mode:shell-script;-*-

##  @file dependencies.sh
##  @brief dependencies.sh
##
##  dependencies.sh
##
##  Copyright 2023 hanepjiv
##
##  @author hanepjiv <hanepjiv@gmail.com>
##  @copyright The MIT License (MIT)
##  @since 2023/09/29
##  @date 2023/10/07

# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
usage_() {
    cat <<EOF 2>&1
Usage: ${0}

        <ACTION> [-h | --help]

        <ACTION>            : [clone | remove]
        -h, --help          : print this help message
EOF
}
# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
TARGETS=( \
          "et-splint" \
              "et-cpplint" \
    )
# -----------------------------------------------------------------------------
et_splint_REPO="git@github.com:hanepjiv/et-splint.git"
et_splint_B="master"
# -----------------------------------------------------------------------------
et_cpplint_REPO="git@github.com:hanepjiv/et-cpplint.git"
et_cpplint_B="master"
# =============================================================================
CURRENT_DIR="${PWD}"
SH_SOURCE=${BASH_SOURCE:-$0}
SH_SOURCE_DIR="$(cd $(dirname ${SH_SOURCE}); pwd)"
OUTPUT_DIR="$(cd ${CURRENT_DIR}/..; pwd)"
# /////////////////////////////////////////////////////////////////////////////
# =============================================================================
clone_target() {
    local target="${1}"
    local target_dir="${OUTPUT_DIR}/${target}"

    if [ -d ${target_dir} ] ; then
        echo ${target} already exists.
        return 0
    fi

    local target_tr=`echo ${target} | tr - _`

    local target_tr_repo="${target_tr}_REPO"
    local target_repo=`eval echo '$'${target_tr_repo}`

    local target_tr_b="${target_tr}_B"
    local target_b=`eval echo '$'${target_tr_b}`

    git clone ${target_repo} -b ${target_b} ${target_dir} || return 1

    return 0
}
# -----------------------------------------------------------------------------
clone() {
    for target in "${TARGETS[@]}"; do
        clone_target "${target}" || return 1
    done
    return 0
}
# =============================================================================
remove_target() {
    local target="${1}"
    local target_dir="${OUTPUT_DIR}/${target}"

    rm -rf ${target_dir} ||  return 1

    return 0
}
# -----------------------------------------------------------------------------
remove() {
    for target in "${TARGETS[@]}"; do
        remove_target "${target}" || return 1
    done
    return 0
}
# =============================================================================
while [ ${#} -gt 0 ]; do
    case ${1} in
        clone)          clone;  shift 1                         ;;
        remove)         remove; shift 1                         ;;
        -h | --help)    usage_; exit 0                          ;;
        *)              echo "invalid argument: ${1}"; exit 1   ;;
    esac
done
