TOTAL PATTERNS IN ANDROID PATTERN LOCK
======================================

This c++ console application computes total patterns possible in android pattern lock.

The problem is solved using graph after excluding a case where there cannot be a line over a node that is already used in the pattern.

Algorithm
---------

The following adjacency matrix hold the rules that are to be followed by the pattern in Android pattern lock.

	0 1 0 1 1 1 0 1 0
	1 0 1 1 1 1 1 0 1
	0 1 0 1 1 1 0 1 0
	1 1 1 0 1 0 1 1 1
	1 1 1 1 0 1 1 1 1
	1 1 1 0 1 0 1 1 1
	0 1 0 1 1 1 0 1 0
	1 0 1 1 1 1 1 0 1
	0 1 0 1 1 1 0 1 0

We know that on calculating power n of a adjacency matrix we get a matrix whose each element (i,j) denote the number of paths of length n from node i to node j in the graph.

But here there is a restriction that unique nodes should be present in the path.

To include the above restriction, each matrix (pattern object) has a 3d array - frequency, whose each element (i,j,k) denote the frequency of occurrence a node k in a patterns of length n starting from node i and ending at node j.

Also the multiply operation (here, combine) is modified to include only those nodes in the path that are not already present.

Output
------

	patterns of length 4: 6320
	patterns of length 5: 28752
	patterns of length 6: 131024
	patterns of length 7: 599232
	patterns of length 8: 2747072
	patterns of length 9: 12619632
	total valid patterns: 16132032

Conclusion
----------

Total valid patterns are 16132032.