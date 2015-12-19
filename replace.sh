#! /bin/env sh
# -*- mode:shell-script; coding:utf-8; -*-

# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
CURRENT_DIR="${PWD}"
ROOT="$(cd $(dirname ${BASH_SOURCE:-$0}); pwd)"

# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
replace_(){
    if [ ${#} -ne 2 ]; then
        exit 1
    fi

    echo "You sure you want to 'replace_ \"${1}\" \"${2}\"' ?"
    select YN in yes no; do
        case ${YN} in
            yes)                                break   ;;
            no)                                 exit 0  ;;
            *)  echo "invalid YN ${YN}";        exit 1  ;;
        esac
    done
    echo

    find ${CURRENT_DIR} -type f \
         \( -name          \*.in        -o -name    \*.sh \
         -o -name CMakeLists.txt        -o -name \*.cmake \
         -o -name           \*.h        -o -name     \*.c \
         -o -name          \*.hh        -o -name    \*.cc \
         -o -name         \*.hpp        -o -name   \*.cpp \
         -o -name       \*.cabal        -o -name    \*.hs \) \
         -exec sed -i -E "s@${1}@${2}@g" {} \;
}
# //////////////////////////////////////////////////////////////////////////////
# ==============================================================================
#replace_ Unknwon Unknown                                         || exit $?
#replace_ \0\0\0\0 \0\0\0\1                                       || exit $?
#replace_ unknown\\\.h unknown\0\0\0\1\\\.h                       || exit $?
#replace_ eventor\\/eve eventor\\/\0\0\0\1\\/eve                  || exit $?
# ==============================================================================
if [ ${#} -ne 2 ]; then
    exit 1
fi

replace_ "${1}" "${2}"
