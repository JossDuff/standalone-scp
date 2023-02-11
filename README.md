# standalone-scp
Copied from https://github.com/stellar/stellar-core

herder is example implementation of scp driver class from stellar-core.  We'll have to build our own implementation

https://github.com/bobg/scp
example scp in go.  Will be a good reference

https://doc.libsodium.org/installation
need to install sodium

# TODO
 - copy over .cpp files associated with the .h files in lib/ when needed
 - node input file with slices and parser for that file
 - parse into nodes and qslices
 - make parser more robust (check node names, error messages, etc.)
 - might not need SCPdriver.  Seems like it deals more with persistence in a live network than the actual consensus.
 - start actually coding and make a list of the issues/ things to solve