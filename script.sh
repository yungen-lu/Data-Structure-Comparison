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
            ./main -d $i -q $((i/10)) -g -f output/$i-data.txt -s output/$((i/10))-search.txt
        done
        echo "done generating"
    fi
}
execTests(){
    echo "start excuting tests"
    for((i=$startingLen; i <= $endingLen; i=i+$interval)); do
        ./main -d $i -q $((i/10)) -A -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
        ./main -d $i -q $((i/10)) -B -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
        ./main -d $i -q $((i/10)) -h -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
        ./main -d $i -q $((i/10)) -b -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
        ./main -d $i -q $((i/10)) -l -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
        ./main -d $i -q $((i/10)) -a -f output/$i-data.txt -s output/$((i/10))-search.txt >> output/result.txt
    done
    echo "done excuting"
    
}
checkOutputDir(){
    [ -d "./output" ] || mkdir "./output"
}
checkOutputDir
getLen
genRand
execTests

