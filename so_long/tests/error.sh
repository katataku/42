#!/bin/bash

for file in `ls ./maps/error_*`; do
	valgrind ./so_long ${file}
done