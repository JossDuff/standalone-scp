#!/bin/bash

# for running in the root file /standalone-scp/

filename=$1
GREETING="Lets copy dependencies of $filename!"
echo $GREETING

# find the file path in stellar-core
filePath=$(find stellar-core -name "$filename")
echo "Found path: " $filePath

# copy file into src/include if .h, src/ if .cpp
if [[ "${filename##*.}" == "cpp" ]]; then
  echo "The file has the .cpp extension. Copying into src/"
elif [[ "${filename##*.}" == "h" ]]; then
  echo "The file has the .h extension. Copying into src/include/"
else
  echo "The file has a different extension (."${filename##*.}"). Exiting program."
  exit 1
fi

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

# $ cp original_file.cpp copied_file.cpp && sed -i 's/#include\s*"[^/]*\/\([^"]*\)"/#include "\1"/g' copied_file.cpp
# This works but doesn't change the statements in <>



### PATTERN

# find file in stellar-core
# copy file into src/include if .h, src/ if .cpp
# change #include statements of copied file.  Remove path
    # if .cpp, add "include/"
# find included files of given file
# repeat with each file found

