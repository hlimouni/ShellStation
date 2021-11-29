#!/bin/bash

# Bold High Intensity COLORS
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White


function print_if_it_is_c_file {
    
    file=$1
    extension=${file: -2}
    
    if [ "$extension" == ".c" ]
    then
        echo "$file \\"
    fi
}

function get_files {
    
    output=`ls ./$1`

    for file in $output
    do
        if [ -d "./$1/$file" ]
        then
            get_files "$1/$file"
        elif [ -f "./$1/$file" ]
        then
            print_if_it_is_c_file "./$1/$file"
        fi
    done

}


if [ $# != 1 ] || [ ! -d $1 ]
then
    echo -e "${BIYellow}please enter a valid path name"
    echo -e -n "${BICyan}PS: "
    echo -e "${BICyan}\`${BIWhite}./get_files_for_Makefile.bash .${BICyan}\`"
    exit
fi

path="$1"
cd $path
output=`ls`

for file in $output
do
    if [ -d "./$1/$file" ]
    then
        get_files "$file"
    elif [ -f "./$1/$file" ]
    then
        print_if_it_is_c_file "$1/$file"
    fi
done