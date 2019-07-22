#!/bin/bash
# Name: QA.sh - (Listing 12-4)
# Author: Cody R. Drisko (crdrisko)
# Date: 07/22/2019-08:04:01
# Description: Set variables by question and answer

read -ep "Directory containing dictionary: " dict
read -ep "File containing word list: " wordfile
read -ep "File containing compound words and phrases: " compoundfile
read -sn1 -p "Include compound words and phrases in results (y/n)? " compounds
echo
read -ep "Save parameters (y/n)? " save
case $save in
    y|Y) read -ep "Enter path to configuration file: " configFile
         {
             printf '%-30s ## %s"\n' \
                "dict=$dict" "Directory containing dictionary" \
                "wordfile=$wordfile" "File containing word list" \
                "compoundfile=$compoundfile" "File containing compound words and phrases" \
                "Compounds" "$compounds" "Include compound words and phrases in results?"
         } > "${configFile:-/dev/tty}"
esac

