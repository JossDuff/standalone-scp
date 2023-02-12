# standalone-scp
Copied from https://github.com/stellar/stellar-core

https://github.com/bobg/scp
example scp in go.  Will be a good reference

# running
You'll need to install sodium: https://doc.libsodium.org/installation

If you run into errors with some core c++ packages you might need to update your include path.

Run the following in `/standalone-scp`:
`$ make`
`$ ./main.exe`

If you make changes to any files or want to re-compile:
`$ make clean` will remove any `.o` & `.exe` files

## node-input.txt
This is the input file that defines the nodes and their trusted slices.
Format is as follows:

[node name]<br />
[names of trusted nodes to be added to node's slice.  Space separated]<br />
[empty line]<br />
[node name]<br />
[names of trusted nodes to be added to node's slice.  Space separated]<br />
[empty line]<br />
etc.

## notes
 - All files in scp/ and lib/ are copied from stellar-core.  Try not to make changes to the bodies of any of these files since they were made by the Stellar team.  If we get errors, it is much more likely the error is our fault and not the fault of the Stellar devs.  Messing around with #include statements is okay though since our file tree is different than stellar-core's.

## TODO
 - copy over .cpp files associated with the .h files in lib/ when needed
 - node input file with slices and parser for that file
 - parse into nodes and qslices
 - make parser more robust (check node names, error messages, etc.)
 - might not need SCPdriver.  Seems like it deals more with persistence in a live network than the actual consensus.
  - Herder is example implementation of scp driver class from stellar-core.  We MIGHT have to build our own implementation. 
 - start actually coding and make a list of the issues/ things to solve