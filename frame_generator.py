#coding=utf-8

# cpp框架生成器
# 感觉每次创建cpp文件太麻烦了

# 2018年12月27日00:00:39
# @author liuyinxin

import os
import time
# import argparse

# args = argparse.ArgumentParser()
# args.add_argument('-n')

filename = input('请输入文件名:')
create_time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
author = input('请输入作者:')
abstract = input('请输入简介:')

if len(filename) <= 0:
    print('请输入文件名')
    exit(1)
elif len(author) <= 0:
    print('请输入作者')
    exit(1)
elif len(abstract) <= 0:
    print('请输入简介')
    exit(1)

abstract = "\n".join(abstract.split("。"))


content = """
#include <iostream>

/*****************************/
/*　filename: {}.cpp */
/*　abstract: {}  */
/*　author :  {}  */
/*　time:     {}  */
/*****************************/
/*****************************/

using namespace std;

int main(){{
    return 0;
}}
""".format(filename,abstract,author, create_time)

with open(os.path.join(os.path.curdir, '{}.cpp'.format(filename)), 'w') as f:
    f.write(content)

with open(os.path.join(os.path.curdir, '.gitignore'), 'a') as f:
    f.write(filename + '\n')
print('文件创建完毕')
