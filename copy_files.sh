#!/bin/bash
# for running in the root file /standalone-scp/
# TODO: resolve the strange <> include statements

originFile=$1

# find the file path in stellar-core
filePath=$(find stellar-core -name "$originFile")
if [[ -z "$filePath" ]]; then
  echo "File not found"
  exit 1
else
  echo "File found: $filePath"
fi

# find filenames of included files
includedFiles=$(grep -oP '^#include\s*"\K[^/]+/\K\S+' $filePath | sed 's/"$//')
echo -e "Included files:\n$includedFiles"

# repeat for all included files
for filename in $includedFiles; do
    # file has .cpp extension, copy it into src/ and change include statements to be "include/"
    if [[ "${filename##*.}" == "cpp" ]]; then
        echo "Copying $filename into src/"
        # copies the file into src/ and changes include statements to be "include/"
        $(cp $filePath src/$filename && sed -i 's/#include\s*".*\/\([^"]*\)"/#include "include\/\1"/g' src/$filename)
    # file has .h or .hpp extension, copy it into src/include/ and change include statements to remove the path
    elif [[ "${filename##*.}" == "h" || "${filename##*.}" == "hpp" ]]; then
        echo "Copying $filename into src/include/"
        # copies the file into src/include and changes include statements to remove the path
        $(cp $filePath src/include/$filename && sed -i 's/#include\s*"[^/]*\/\([^"]*\)"/#include "\1"/g' src/include/$filename)
    # otherwise file invalid
    else
        echo "The file has a different extension (."${filename##*.}"). Exiting program."
        exit 1
    fi
done


#
# FIND
# finds the file path

# $ find stellar-core -name "SHA.h"
# output: 
# stellar-core/src/crypto/SHA.h

# $ find stellar-core -name "SHA.cpp"
# output: 
# stellar-core/src/crypto/SHA.cpp

# $ find stellar-core -name "doesnt exist"
# output: 
# [nothing]

#
# GREP
# finds included files of a given file

# this removes the path and the ""s
#modified, not tested: $ grep -oP '^#include\s*"\K[^/]+/\K\S+' $filePath | sed 's/"$//'

# $ grep -oP '^#include\s*\K"\S+"' stellar-core/src/crypto/SHA.cpp
# output: 
# "crypto/SHA.h"
# "crypto/ByteSlice.h"
# "crypto/CryptoError.h"
# "crypto/Curve25519.h"
# "util/NonCopyable.h"

# $ grep -oP '^#include\s*\K"\S+"' doesntexist.cpp
# output:
# grep: doesntexist.cpp: No such file or directory


#
# CP && SED
# copies a file and then renames the #include statements in the copied version

# this removes the entire path (for copying .h files that reference .h files)
# $ cp original_file.cpp copied_file.cpp && sed -i 's/#include\s*"[^/]*\/\([^"]*\)"/#include "\1"/g' copied_file.cpp
# This works but doesn't change the statements in <>

# this adds in "/include" (for copying .cpp files that reference .h files)
# cp original_file.cpp copied_file.cpp && sed -i 's/#include\s*".*\/\([^"]*\)"/#include "include\/\1"/g' copied_file.cpp
# this one might not work idk


### PATTERN

# find file in stellar-core
# copy file into src/include if .h, src/ if .cpp
# change #include statements of copied file.  Remove path
    # if .cpp, add "include/"
# find included files of given file
# repeat with each file found

