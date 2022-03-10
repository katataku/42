#!/bin/bash

NC="\033[0m"
BOLD="\033[1m"
ULINE="\033[4m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"

ACTUAL_PATH=./tests/actual/
MAPS_PATH=./tests/maps/
EXPECTED_PATH=./tests/expected/
INFILE_PATH=./tests/

# input, test_name
function do_test() {
	IS_OK=1
	echo -n "${TEST_NAME} "
	./so_long "${MAPS_PATH}${TEST_NAME}" > "${ACTUAL_PATH}${TEST_NAME}" 2>&1

	echo -n "feature: "
	if  diff "${ACTUAL_PATH}${TEST_NAME}" "${EXPECTED_PATH}${TEST_NAME}" > /dev/null ;then
		echo -n "OK"
	else
		printf "${RED}NG${NC}"
		IS_OK=0
	fi

	if [ $IS_OK -eq 1 ] ; then
		printf " ${GREEN}[✓]${NC}\n"
	else
		printf " ${RED}[-]${NC}\n"
	fi
}

#
TEST_NAME=sample1.ber
do_test

#
TEST_NAME=sample2.ber
do_test

#
TEST_NAME=sample3.ber
do_test

#
TEST_NAME=sample4.ber
do_test

