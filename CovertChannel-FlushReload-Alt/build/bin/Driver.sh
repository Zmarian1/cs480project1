#!/bin/bash
# Runs the sender and receiver with input file input.txt
./receiver -s input.txt &
./sender -s input.txt
