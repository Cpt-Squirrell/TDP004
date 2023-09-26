#! /bin/bash

# Check given number for if it's a prime
function is_prime {
	prime=1
	end=$(($1 - 1))
	for i in $(seq 2 $end)
	do
		if (($1 % $i == 0))
		then
			prime=0
			break
		fi
	done
	return $prime # Returns 0 or 1
}

# Prompt the user
echo "Enter start number: "
read start
echo "Enter end number: "
read end
echo "---"


print_prime=1
for i in $(seq $start $end)
do
	is_prime $i
	result=$?
	if (( (result == 1) && (print_prime == 1) ))
	then
		echo $(($i + 1))
		print_prime=0
	elif (( (result == 1) && (print_prime == 0) ))
	then
		print_prime=1
	fi
done
