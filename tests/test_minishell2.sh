#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## test_minishell1
##

test()
{
    echo -ne $1 | ./sm_shell &> .got
    echo $? >> .got
    echo -ne $1 | tcsh &> .expected
    echo $? >> .expected
    diff .got .expected
    if [[ $? == 0 ]]
    then
        echo -e "\E[0;32m Test \E[0m \e[90m\e[1mPASSED\e\e[0m"
    else
        echo -e "\E[0;31m Test \e[0m \e[41mNOT PASSED\E[0m"
    fi
}

echo -e "\e[36m\e[4mTests commands:\e[0m"

test ls
test exitt
test 'pwd'
test 'ls nofile'
test 'setenv PATH\nunsetenv PATH\nls'
test 'unsetenv PWD PATH LOGNAME HOSTNAME\nls\npwd'
test 'echo "test"'

echo -e "\e[36m\e[4mTests env:\e[0m"

test 'setenv zdza dazdaz dazdaz zdzad'
test 'setenv dadza dadazad'
test 'unsetenv PATH'
test 'setenv PATH dazdaz'
test 'setenv PATH=*--+ dazda'
test 'unsetenv PATH\nsetenv dadza dazda dadza\n unsetenv NOTE PATH LS\n'
test 'unsetenv PWD PATH LOGNAME\nls\nsetenv PATH=\nsetenv PATH /bin'
test 'unsetenv'

echo -e "\e[36m\e[4mTests errors:\e[0m"

test '../a.out^C'
test './Makefile'
test 'zadda'
test '    ./Makefile    '
test './sources'
test 'sources/'

echo -e "\e[36m\e[4mTests parsing:\e[0m"

test '    ls    '
test '              exit'
test '    ls    -l'
test '    pwd     '
test '         '
test '      tcsh'

echo -e "\e[36m\e[4mTests cd:\e[0m"

test 'cd ../'
test 'cd'
test 'cd\ncd -'
test 'cd ../\nls\n cd -\nls'
test 'cd\nls\ncd ../\nls'
test '   cd\n    ls -l \ncd ../../\n ls'
test 'cd dazdza zadaz'
test 'setenv HOME\ncd'
test 'cd ffa'
test 'cd azda zada'
test 'cd /bin/ls'
test 'cd /root'

echo -e "\e[36m\e[4mTests core dump:\e[0m"

ulimit -S -c 0
test 'tests/a.out'

rm -f .got
rm -f .expected
rm -f .history