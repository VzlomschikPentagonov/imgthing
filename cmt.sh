#!/bin/bash
echo "Input commit name:"
read COMMIT_NAME
git add .
git commit -m "$COMMIT_NAME"
read PUSH_BRANCH
case $PUSH_BRANCH in
 )
  break
  ;;
 *)
  git push img $PUSH_BRANCH
  ;;
esac
clear
