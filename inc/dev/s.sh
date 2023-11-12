#!/bin/bash
cmd_strings="strings util3_source.txt"
output="../inc/util3.h"
lines=$(strings util3_source.txt)
out_line="#define PROPERTY \\n"
for line in $lines
	do 
		out_line+="X("$line,\"$line\"") \n"
	done 
printf "$out_line" > $output
