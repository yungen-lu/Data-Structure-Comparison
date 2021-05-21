#!/bin/bash
set -o nounset # error when referencing undefined variable
set -o errexit # exit when command fails

checkFileExist(){
    if test -f ./$1;
    then
        echo  "$1 exists"
    else
        execMake $1
    fi
        
}
execMake(){
    echo "$1 does not exists"
    echo -n "Would you like to compile it now (y/n)? "
	read answer
	[ "$answer" != "${answer#[Yy]}" ] && make $1
}
getLen(){
    echo -n "Enter length of starting output "
    read startingLen
    echo -n "Enter length of ending output "
    read endingLen
    if [ -z "$startingLen" ] || [ -z "$endingLen" ]; then 
        echo 'Inputs cannot be blank please try again!' 
        exit 
    fi
    if ! [[ "$startingLen" =~ ^[0-9]*$ ]] || ! [[ "$endingLen" =~ ^[0-9]*$ ]]; then 
        echo "Inputs must be a numbers" 
        exit 0 
    fi
    length=$(( endingLen - startingLen + 1 ))
    if [ $length -le 0 ]; then
        echo "startingLen must be smaller then endingLen"
        exit
    fi
    echo -n "Enter length of interval"
    read interval
    if [ $interval -le 0 ]; then
       echo "interval must be bigger then 0" 
       exit
    fi
    # echo $length
}
genRand(){
    echo -n "generate ?"
    read ans
	if [ "$ans" != "${ans#[Yy]}" ]; then
        echo "start generating random text files"
        for((i=$startingLen; i <= $endingLen; i=i+$interval)); do
            # ./GenRandMain "-s" $i output/$i-string.txt >/dev/null
            # ./GenRandMain "-n" $i output/$i-number.txt >/dev/null
            ./main -d $i -q $i -g -f output/$i-data.txt -s output/$i-search.txt
        done
        echo "done generating"
    fi
}
execTests(){
    echo "start excuting tests"
    for((i=$startingLen; i <= $endingLen; i=i+$interval)); do
        ./main -d $i -q $i -A -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
        ./main -d $i -q $i -B -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
        ./main -d $i -q $i -h -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
        ./main -d $i -q $i -b -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
        ./main -d $i -q $i -l -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
        ./main -d $i -q $i -a -f output/$i-data.txt -s output/$i-search.txt >> output/result.txt
    done
    echo "done excuting"
    
}
checkOutputDir(){
    [ -d "./output" ] || mkdir "./output"
}
# checkRand(){
#     for((i=$startingLen; i <= $endingLen; i++)); do
#         if test -f output/$i-string.txt && test  -f output/$i-number.txt;
#         then
#             echo  "$i exists"
#         else
#         fi
# 
# }
checkOutputDir
getLen
genRand
execTests

