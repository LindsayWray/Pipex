#!/bin/bash

rm -R test_output
mkdir test_output

compare_files ()
{
if cmp -s "$shell" "$pipex"; then
    printf "OK\n"
else
    printf 'The file "%s" is different from "%s"\n' "$shell" "$pipex"
fi
}

echo "Test 1"
shell=test_output/catcat
pipex=test_output/my_catcat
< input.txt cat | cat > $shell
./pipex input.txt cat cat $pipex
compare_files


echo "Test 2"
shell=test_output/grep_cat
pipex=test_output/my_grep_cat

< input.txt grep 'Cats' | cat > $shell
./pipex input.txt "grep 'Cats'" cat $pipex
compare_files


echo "Test 3"
shell=test_output/ls_wc
pipex=test_output/my_ls_wc
< input.txt ls -l | wc -l > $shell
./pipex input.txt "ls -l" "wc -l" $pipex
compare_files


echo "Test 4"
shell=test_output/echo_quotes
pipex=test_output/my_echo_quotes
< input.txt grep cats | echo "'hello world'" > $shell
./pipex input.txt "grep cats" "echo \"'hello world'\"" $pipex
compare_files


echo "Test 5"
shell=test_output/cat_awk
pipex=test_output/my_cat_awk
< input.txt grep cats | awk '{count++} END {print count}' > $shell
./pipex input.txt "grep cats" "awk '{count++} END {print count}'" $pipex
compare_files


echo "Test 6"
shell=test_output/awk_string
pipex=test_output/my_awk_string
< input.txt grep hello | awk "{count++} END {print count}" > $shell
./pipex input.txt "grep hello" "awk \"{count++} END {print count}\"" $pipex
compare_files


echo "Test 7"
shell=test_output/awk_quotes
pipex=test_output/my_awk_quotes
< input.txt grep hello | awk '"{count++} END {print count}"' > $shell
./pipex input.txt "grep hello" "awk '\"{count++} END {print count}\"'" $pipex 2> $pipex
compare_files


echo "Test 8"
shell=test_output/awk_quotes_2
pipex=test_output/my_awk_quotes_2
< input.txt grep hello | awk "'{count++} END {print count}'" > $shell 2>> $shell
./pipex input.txt "grep hello" "awk \"'{count++} END {print count}'\"" $pipex 2>> $pipex
compare_files


echo "Test 9"
shell=test_output/head_sed
pipex=test_output/my_head_sed
< input.txt head -n 3 | sed 's/ /^^/g ' > $shell
./pipex input.txt "head -n 3" "sed 's/ /^^/g '" $pipex
compare_files


echo "Test 10"
shell=test_output/rubbish
pipex=test_output/my_rubbish
< input.txt rubbish | rubbish > $shell
./pipex input.txt rubbish rubbish $pipex
compare_files


# echo "Test 11"
# shell=test_output/norminette
# pipex=test_output/my_norminette
# < input.txt norminette | grep KO > $shell 2>> $shell
# ./pipex input.txt norminette "grep KO" $pipex 2>> $pipex
# compare_files

echo "Test 12"
shell=test_output/full_path
pipex=test_output/my_full_path
< input.txt /bin/cat | /bin/cat > $shell
./pipex input.txt /bin/cat /bin/cat $pipex
compare_files

# check if old file content is removed and not overwritten. O_TRUNC flag
# force execve error with fake command (like cat or echo +x)
# check if file permissions are the same as the terminals output files