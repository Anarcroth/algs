#!/bin/bash

read -p "Would you like to upload your app now? [y/n]: " -n 1 -r
echo    # (optional) move to a new line
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
    exit 1
fi

git add *
git commit -m "Commit (Automated)"
git push origin master
