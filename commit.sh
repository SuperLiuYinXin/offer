#!/bin/bash

git add .
read -p '请输入commit信息: ' commit

echo 'commit 信息: ' $commit
if [ -z $commit ];then
    echo 'commit信息为空,请重新输入'
    exit 1
fi

git commit -m "${commit}"
git push
echo '上传完毕'