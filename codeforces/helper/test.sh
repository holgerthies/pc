#!/bin/bash
cat $1.in | while read line; do
	#echo $line
	if [[ $line = "Input" ]]; then
		readtc=1
		readout=0
		testcase=""
		result=""
	elif [[ $line = "Output" ]]; then
		readtc=0
		readout=1
		result=""
		read empty
	elif [[ $readtc -eq 1 ]]; then
		testcase="$testcase\n$line"
	elif [[ $readout -eq 1 ]]; then
		result="$result\n$line"
		if [[ $line = "" ]]; then
			OUTPUT=`mktemp out.XXXXXXXXXX`
			INPUT=`mktemp in.XXXXXXXXXX`
			EXPECT=`mktemp exp.XXXXXXXXXX`
			printf "$result" > "${EXPECT}"
			printf "$testcase" > "${INPUT}"
			out=`./$1.o < "${INPUT}"`
			printf "\n$out\n" > "${OUTPUT}"
			if diff "${OUTPUT}" "${EXPECT}" -b &>/dev/null; then
				echo "test ok"
			else
				echo "error in test case."
				printf "$testcase"
				echo "expected:"
				printf "$result"
				echo "got:"
				printf "$out"
				#diff "${OUTPUT}" "${EXPECT}" -by
			fi
			rm -f "${OUTPUT}"
			rm -f "${EXPECT}"
			rm -f "${INPUT}"

		fi
	else
		echo $readtc
	fi
done