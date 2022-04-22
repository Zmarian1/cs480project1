#!/bin/bash
# Runs the sender and receiver with input file input.txt
taskset -c 1 ./receiver -s input.txt &
taskset -c 1 ./sender -s input.txt
