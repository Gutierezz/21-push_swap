#!/bin/bash

mkdir -p Results
echo -n > Results/res3
echo -n > Results/res5
echo -n > Results/res100
echo -n > Results/res500

echo 'Testing 30 Times in a range from 1 to 3'

for i in range {1..30}
do
	ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
	./push_swap $ARG | wc -l >> Results/res3
	echo -en '\033[0;32m▓\033[0;0m'
done

echo -e '\nTesting 120 Times in a range from 1 to 5'

for i in range {1..119}
do
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	./push_swap $ARG | wc -l >> Results/res5
	echo -en '\033[0;32m▓\033[0;0m'
done

echo -e '\nTesting 120 Times in a range from 0 to 99'

for i in range {1..119}
do
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	./push_swap $ARG | wc -l >> Results/res100
	echo -en '\033[0;32m▓\033[0;0m'
done

echo -e '\nTesting 120 Times in a range from 0 to 499'

for i in range {1..119}
do
	ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	./push_swap $ARG | wc -l >> Results/res500
	echo -en '\033[0;32m▓\033[0;0m'
done

echo -e '\n\n Greater than 3 numbers LIMIT : \n'
AVG3=0
while read LINE
do
	if [ $LINE -gt 3 ]
	then
		echo -e "\033[0;31m$LINE\033[0;0m"
	fi
	AVG3=$(($AVG3 + $LINE))
done < 'Results/res3'

echo -e '\n Greater than 5 numbers LIMIT : \n'
AVG5=0
while read LINE
do
	if [ $LINE -gt 12 ]
	then
		echo -e "\033[0;31m$LINE\033[0;0m"
	fi
	AVG5=$(($AVG5 + $LINE))
done < 'Results/res5'

echo -e '\n Greater than 100 numbers LIMIT : \n'
AVG100=0
while read LINE
do
	if [ $LINE -gt 700 ]
	then
		echo -e "\033[0;31m$LINE\033[0;0m"
	fi
	AVG100=$(($AVG100 + $LINE))
done < 'Results/res100'


echo -e '\n Greater than 500 numbers LIMIT : \n'
AVG500=0
while read LINE
do
	if [ $LINE -gt 5500 ]
	then
		echo -e "\033[0;31m$LINE\033[0;0m"
	fi
	AVG500=$(($AVG500 + $LINE))
done < 'Results/res500'

echo -e "\n\n\033[0;36m------------------AVERAGE:--------------------\033[0;0m\n"
echo -e "Average operations count for   3 numbers : \033[0;33m $(($AVG3 / 30)) \033[0;0m"
echo -e "Average operations count for   5 numbers : \033[0;33m $(($AVG5 / 120)) \033[0;0m"
echo -e "Average operations count for 100 numbers : \033[0;33m $(($AVG100 / 120)) \033[0;0m"
echo -e "Average operations count for 500 numbers : \033[0;33m $(($AVG500 / 120)) \033[0;0m"

echo -e '\nWatch your results in folder \033[0;32mResults\033[0;0m\n'
echo -e "       \033[0;31mG\033[0;32mo\033[0;33mo\033[0;34md \033[0;35ml\033[0;36mu\033[0;32mc\033[0;33mk\033[0;31m!\033[0;0m\n"
