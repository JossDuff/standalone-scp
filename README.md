# standalone-scp
Copied from https://github.com/stellar/stellar-core

herder is example implementation of scp driver class from stellar-core.  We'll have to build our own implementation

https://github.com/bobg/scp
example scp in go.  Will be a good reference

# TODO
 - node input file with slices and parser for that file
 - parse into nodes and qslices
 - might not need SCPdriver.  Seems like it deals more with persistence in a live network than the actual consensus.
 - start actually coding and make a list of the issues/ things to solve