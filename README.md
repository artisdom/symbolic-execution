Alterations to LLVM and KLEE for practical "false positive pruning" defect finding.

Copyright Martin Trojer <martin.trojer@gmail.com>

For more information see http://martinsprogrammingblog.blogspot.com/2011/11/applied-symbolic-execution-with.html

llvm-2.6 contains the update to LLVM, mainly the "CallPaths" LLVM analysis pass.
This uses Boost Graph Library to generate a set of potential paths from a
root basic block to the taket basic-block(s).

klee contains the changes to klee. This is mainly a new seracher "GuidedSearcher"
in lib/Core/Sercher.cpp This searcher uses to CallPaths LLVM pass as mentioned
above.