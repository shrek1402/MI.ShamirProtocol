
ClangFormatPath="C:/Program Files/LLVM/bin/clang-format.exe"

"$ClangFormatPath" -version

echo start processing directory $(pwd)
echo With files as follows:
echo -----------------------------------

TotalCount=$(find . -not \( -path "./.localhistory/*" -prune \) -iname '*.cpp' -or -iname '*.h' | wc -l)
echo "Total file count is : $TotalCount"

i=0
find . -not \( -path "./.localhistory/*" -prune \) -iname '*.cpp' -or -iname '*.h' | while read file_path; do
    ((++i))
    printf  "[ $i/$TotalCount ] : Processing file '$file_path'"

    "$ClangFormatPath" -i -style=file $file_path
    printf  "..... Clang-format Done\n"

    #"C:/Work/llvm-project/build/Release/bin/AStyle.exe"  --options=".astylerc" $file_path
    #printf  "..... Astyle Done\n"
done

echo -----------------------------------
echo All finished