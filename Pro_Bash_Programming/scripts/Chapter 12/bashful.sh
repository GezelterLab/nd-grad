#!/bin/bash
# Name: bashful.sh - (Listing 12-8)
# Author: Cody R. Drisko (crdrisko)
# Date: 07/22/2019-08:27:12
# Description: Connect to remote computer via ssh

scriptname=${0##*/}

## default colors
bg=#ffffcc              ## default background: pale yellow
fg=#000000              ## default foreground: black

user=bashful            ## default user name
term=xterm              ## default terminal emulator

case $scriptname in
    sleepy)
        bg=#ffffff
        user=sleepy
        host=sleepy.example.com
        ;;
    sneezy)
        fg=#aa0000
        bg=#ffeeee
        host=sneezy.example.org
        ;;
    grumpy)
        fg=#006600
        bg=#eeffee
        term=rxvt
        host=cfajohnson.example.com
        ;;
    dopey)
        host=127.0.0.1
        ;;
    *)  echo "$scriptname: Unknown name" >&2
        exit 1
        ;;
esac

"$term" -fg "$fg" -bg "$bg" -e ssh -l "$user" "$host"
