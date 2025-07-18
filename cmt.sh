#!/bin/bash
echo "Input commit name:"
read COMMIT_NAME
git add .
git commit -m "$COMMIT_NAME"
read PUSH_BRANCH
if[$PUSH_BRANCH != ""]; then
 git push img $PUSH_BRANCH
fi
#echo "Push (y/n)"
#read YN
#case $YN in
# y)
#  echo "Input branch name:"
#  read BRANCH_NAME
#  git push img $BRANCH_NAME
# ;;
# n)
# ;;
#esac
clear
