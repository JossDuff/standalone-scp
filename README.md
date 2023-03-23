# standalone-scp

https://github.com/bobg/scp
example scp in go.  Will be a good reference

# running
## 1. Build `stellar-core`
Clone `stellar-core` locally.
```
$ git clone https://github.com/stellar/stellar-core
```
Follow instructions on how to install `stellar-core` [https://github.com/stellar/stellar-core/blob/master/INSTALL.md]()

## 2. Edit makefile
In `standalone-scp/Makefile`, set `CORE_DIR?=` to the location of your built `stellar-core`

ex: in my `Makefile` I have `CORE_DIR?=$(HOME)/dev/cbdc/stellar-core`

## 3. Compile this repo
Run the following in `standalone-scp/`:
`$ make`

If you make changes to any files or want to re-compile:
`$ make clean` will remove any `.o` & `.exe` files

# node-input.txt
This is the input file that defines the nodes and their trusted slices.
Input file needs to be in the root folder of this repo.
Format is as follows:

[node name]<br />
[names of trusted nodes to be added to node's slice.  Space separated]<br />
[empty line]<br />
[node name]<br />
[names of trusted nodes to be added to node's slice.  Space separated]<br />
[empty line]<br />
etc.

# notes

### `file not found` include error from stellar-core
 When including files from `stellar-core` you sometimes might run into an error like this: 
 ```
 In file included from main.cpp:9:
 /home/joss/dev/cbdc/stellar-core/src/crypto/Hex.h:8:10: fatal error: 'xdr/Stellar-types.h' file not found
 #include "xdr/Stellar-types.h"
 ```
 Not exactly sure why this happens, but `stellar-core` is looking in the wrong place for the file.  In this above case, I went into `stellar-core` where the error occurs and changed `#include "xdr/Stellar-types.h"` to `#include "protocol-curr/xdr/Stellar-types.h"` and it compiles.  This is because `Stellar-types.h` is located in `src/protocol-curr/xdr`, and not in `src/xdr` which is where it seems to be looking.  `src/xdr` is actually empty.

# TODO
 - Finish minimal example of a SCP round in main.cpp