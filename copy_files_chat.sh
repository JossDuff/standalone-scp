#!/bin/bash

# Usage: ./copy_files.sh header_file.h

header_file=$1
search_dir="stellar-core"
copy_dir="src"

# Find all files that include the header file
included_files=$(grep -Rl "#include \"$header_file\"" $search_dir)

for file in $included_files; do
  # Copy all .h files needed by the header file to the include directory
  header_dir=$(dirname $file)
  header_files=$(grep -o "#include \"[^\"]*\.h\"" $file | cut -d'"' -f2)
  for header_file in $header_files; do
    header_path="$header_dir/$header_file"
    if [ "$header_dir" != "$copy_dir/include" ]; then
      cp --parents $header_path $copy_dir/include/
    fi
  done

  # Copy all .cpp files needed by the header file to the src directory
  cpp_files=$(grep -o "#include \"[^\"]*\.cpp\"" $file | cut -d'"' -f2)
  for cpp_file in $cpp_files; do
    cpp_path="$header_dir/$cpp_file"
    if [ "$header_dir" != "$copy_dir" ]; then
      cp --parents $cpp_path $copy_dir/
    fi
  done

  # Replace #include statements in copied files
  for copied_file in $(find $copy_dir -type f -name "*.h" -o -name "*.cpp"); do
    sed -i "s:#include \"$header_file\":#include \"$copy_dir/include/$header_file:g" $copied_file
    sed -i "s:#include \"$header_dir/:#include \"$copy_dir/:g" $copied_file
  done
done
