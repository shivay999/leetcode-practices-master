# leetcode-cpp-practices

Including problem statement, solution, runtime and complexity analysis.

## DSA

[HassanElDesouky/AwesomeLeetCodeDiscussions](https://github.com/HassanElDesouky/AwesomeLeetCodeDiscussions)

[Important and Useful links from all over the Leetcode](https://leetcode.com/discuss/general-discussion/665604/Important-and-Useful-links-from-all-over-the-Leetcode)

[Interview Preparation for Beginners - [ DS | Algorithms | OS | System Design ]](https://leetcode.com/discuss/general-discussion/698684/interview-preparation-for-beginners-ds-algorithms-os-system-design)

[A few helpful links to posts which tell you HOW to grind leetcode](https://leetcode.com/discuss/general-discussion/355251/A-few-helpful-links-to-posts-which-tell-you-HOW-to-grind-leetcode)

[Comprehensive Data Structure and Algorithm Study Guide](https://leetcode.com/discuss/general-discussion/494279/Comprehensive-Data-Structure-and-Algorithm-Study-Guide)

[My System Design Template](https://leetcode.com/discuss/career/229177/my-system-design-template)

## BFS

### Bidirectional BFS
[127. Word Ladder.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/127.%20Word%20Ladder.cpp)

[126. Word Ladder II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/126.%20Word%20Ladder%20II.cpp)

## Tree

### Binary tree traversal
[Preorder, Inorder, and Postorder Iteratively Summarization](https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization/188240)

[94. Binary Tree Inorder Traversal.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/94.%20Binary%20Tree%20Inorder%20Traversal.cpp#L126)

[173. Binary Search Tree Iterator.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/173.%20Binary%20Search%20Tree%20Iterator.cpp)

[144. Binary Tree Preorder Traversal.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/144.%20Binary%20Tree%20Preorder%20Traversal.cpp)

[145. Binary Tree Postorder Traversal.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/145.%20Binary%20Tree%20Postorder%20Traversal.cpp)

### Threaded binary tree, Morris Traversal
[Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)

[94. Binary Tree Inorder Traversal.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/3bad51a31f89eb66c28269f5dd54bb5536a44ef9/94.%20Binary%20Tree%20Inorder%20Traversal.cpp)

[99. Recover Binary Search Tree.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/99.%20Recover%20Binary%20Search%20Tree.cpp)

[538. Convert BST to Greater Tree.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/1171b5e67a0e24e173dace2b69e236447a7aef03/538.%20Convert%20BST%20to%20Greater%20Tree.cpp)

### Tree diameter
[Diameter of a tree using DFS](https://www.geeksforgeeks.org/diameter-tree-using-dfs/)

[1617. Count Subtrees With Max Distance Between Cities.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1617.%20Count%20Subtrees%20With%20Max%20Distance%20Between%20Cities.cpp)

[1405D - Tree Tag.md](https://github.com/keineahnung2345/codeforces-cpp-practice/blob/master/1405D%20-%20Tree%20Tag.md)

## Graph
[Graph Problems For Beginners Practice [Problems and Sample Solutions]](https://leetcode.com/discuss/general-discussion/655708/graph-problems-for-beginners-practice-problems-and-sample-solutions)

### Single Source Shortest Path
#### Bellman Ford
relax for V-1 times, works for negative weighted edges, time complexity: O(VE)

[Bellman Ford(including proof)](http://courses.csail.mit.edu/6.006/spring11/lectures/lec15.pdf)

[SPFA(Shortest Path Faster Algorithm)](https://www.geeksforgeeks.org/shortest-path-faster-algorithm)

#### Dijkstra
greedy, not work for negative weighted edges

DS                               | time complexity  |
---------------------------------|:----------------:|
adjacency matrix                 | O(V^2)           |
adjacency list + binary heap     | O(ElogV)         |
adjacency list + Fabonacci heap  | O(VlogV + E)     |

[Dijkstra’s algorithm - theorem](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)

[Dijkstra's algorithm - C++ implementation](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/)

### All Pairs Shortest Path
[Floyd Warshall](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)

[399. Evaluate Division.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/399.%20Evaluate%20Division.cpp)

### Tarjan's algorithm
[Articulation Points (or Cut Vertices) in a Graph](https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/)

[1568. Minimum Number of Days to Disconnect Island.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1568.%20Minimum%20Number%20of%20Days%20to%20Disconnect%20Island.cpp)

[Bridges in a graph](https://www.geeksforgeeks.org/bridge-in-a-graph/)

[1192. Critical Connections in a Network.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1192.%20Critical%20Connections%20in%20a%20Network.cpp)


### Cycle detection

#### Cycle detection in directed graph

[Detect Cycle in a Directed Graph](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)

[207. Course Schedule.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/207.%20Course%20Schedule.cpp)

[1591. Strange Printer II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1591.%20Strange%20Printer%20II.cpp)

#### Cycle detection in undirected graph

[Detect cycle in an undirected graph](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/): the text description is wrong, watch the video

[1559. Detect Cycles in 2D Grid.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1559.%20Detect%20Cycles%20in%202D%20Grid.cpp)

### Minimum spanning tree, Prim's algorithm(Greedy)
[Prim’s Minimum Spanning Tree (MST) | Greedy Algo-5](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)

[Minimum cost to connect all cities](https://www.geeksforgeeks.org/minimum-cost-connect-cities/)

[1584. Min Cost to Connect All Points.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1584.%20Min%20Cost%20to%20Connect%20All%20Points.cpp)

## Two pointers
[11. Container With Most Water](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/11.%20Container%20With%20Most%20Water.md)

[15. 3Sum](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/15.%203Sum.md)

[16. 3Sum Closest](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/16.%203Sum%20Closest.md)

[18. 4Sum](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/18.%204Sum.md)

[26. Remove Duplicates from Sorted Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/26.%20Remove%20Duplicates%20from%20Sorted%20Array.cpp)

[80. Remove Duplicates from Sorted Array II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/80.%20Remove%20Duplicates%20from%20Sorted%20Array%20II.cpp)

[27. Remove Element.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/27.%20Remove%20Element.cpp)

[28. Implement strStr().cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/28.%20Implement%20strStr().cpp)

[42. Trapping Rain Water.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/42.%20Trapping%20Rain%20Water.cpp)

[75. Sort Colors.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/75.%20Sort%20Colors.cpp)

[76. Minimum Window Substring.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/76.%20Minimum%20Window%20Substring.cpp)

[88. Merge Sorted Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/88.%20Merge%20Sorted%20Array.cpp)

[125. Valid Palindrome.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/125.%20Valid%20Palindrome.cpp)

[141. Linked List Cycle.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/141.%20Linked%20List%20Cycle.cpp)

[142. Linked List Cycle II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/142.%20Linked%20List%20Cycle%20II.cpp)

[167. Two Sum II - Input array is sorted.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/167.%20Two%20Sum%20II%20-%20Input%20array%20is%20sorted.cpp)

[214. Shortest Palindrome.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/214.%20Shortest%20Palindrome.cpp)

[234. Palindrome Linked List.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/234.%20Palindrome%20Linked%20List.cpp)

[283. Move Zeroes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/283.%20Move%20Zeroes.cpp)

[287. Find the Duplicate Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/287.%20Find%20the%20Duplicate%20Number.cpp)

[344. Reverse String.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/344.%20Reverse%20String.cpp)

[345. Reverse Vowels of a String.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/345.%20Reverse%20Vowels%20of%20a%20String.cpp)

[349. Intersection of Two Arrays.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/349.%20Intersection%20of%20Two%20Arrays.cpp)

[350. Intersection of Two Arrays II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/350.%20Intersection%20of%20Two%20Arrays%20II.cpp)

[424. Longest Repeating Character Replacement.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/424.%20Longest%20Repeating%20Character%20Replacement.cpp)

[524. Longest Word in Dictionary through Deleting.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/524.%20Longest%20Word%20in%20Dictionary%20through%20Deleting.cpp)

[763. Partition Labels.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/763.%20Partition%20Labels.cpp)

[838. Push Dominoes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/838.%20Push%20Dominoes.cpp)

[844. Backspace String Compare.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/844.%20Backspace%20String%20Compare.cpp)

[881. Boats to Save People.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/881.%20Boats%20to%20Save%20People.cpp)

[925. Long Pressed Name.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/925.%20Long%20Pressed%20Name.cpp)

[977. Squares of a Sorted Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/977.%20Squares%20of%20a%20Sorted%20Array.cpp)

[986. Interval List Intersections.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/986.%20Interval%20List%20Intersections.cpp)

[1004. Max Consecutive Ones III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1004.%20Max%20Consecutive%20Ones%20III.cpp)

[1248. Count Number of Nice Subarrays.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1248.%20Count%20Number%20of%20Nice%20Subarrays.cpp)

[1574. Shortest Subarray to be Removed to Make Array Sorted.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1574.%20Shortest%20Subarray%20to%20be%20Removed%20to%20Make%20Array%20Sorted.cpp)

## Sliding Window
[Sliding Window for Beginners [Problems | Template | Sample Solutions]](https://leetcode.com/discuss/general-discussion/657507/sliding-window-for-beginners-problems-template-sample-solutions)

[713. Subarray Product Less Than K.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/713.%20Subarray%20Product%20Less%20Than%20K.cpp)

## Monotonic stack
[Python solution using monotonic stack, similar pattern questions listed](https://leetcode.com/problems/daily-temperatures/discuss/314477/python-solution-using-monotonic-stack-similar-pattern-questions-listed)

[84. Largest Rectangle in Histogram.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/84.%20Largest%20Rectangle%20in%20Histogram.cpp)

[85. Maximal Rectangle.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/85.%20Maximal%20Rectangle.cpp)

[503. Next Greater Element II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/503.%20Next%20Greater%20Element%20II.cpp)

[901. Online Stock Span.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/901.%20Online%20Stock%20Span.cpp)

[1475. Final Prices With a Special Discount in a Shop.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1475.%20Final%20Prices%20With%20a%20Special%20Discount%20in%20a%20Shop.cpp)

[1504. Count Submatrices With All Ones.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1504.%20Count%20Submatrices%20With%20All%20Ones.cpp)

## Monotonic queue(Deque)
[Monotonic Queue Summary](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/204290/Monotonic-Queue-Summary)

[Monotonic Queue Explained with LeetCode Problems](https://medium.com/algorithms-and-leetcode/monotonic-queue-explained-with-leetcode-problems-7db7c530c1d6)

[45. Jump Game II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/45.%20Jump%20Game%20II.cpp)

[122. Best Time to Buy and Sell Stock II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II.cpp)

[239. Sliding Window Maximum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/239.%20Sliding%20Window%20Maximum.cpp)

[918. Maximum Sum Circular Subarray.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/918.%20Maximum%20Sum%20Circular%20Subarray.cpp)

[1425. Constrained Subsequence Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1425.%20Constrained%20Subsequence%20Sum.cpp)

[1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1438.%20Longest%20Continuous%20Subarray%20With%20Absolute%20Diff%20Less%20Than%20or%20Equal%20to%20Limit.cpp)

[1499. Max Value of Equation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1499.%20Max%20Value%20of%20Equation.cpp)

## Multiset
It serves as Self-balancing Binary Search Trees (like an AVL Tree).

[218. The Skyline Problem.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/218.%20The%20Skyline%20Problem.cpp)

[295. Find Median from Data Stream.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/295.%20Find%20Median%20from%20Data%20Stream.cpp)

[332. Reconstruct Itinerary.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/332.%20Reconstruct%20Itinerary.cpp)

[480. Sliding Window Median.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/480.%20Sliding%20Window%20Median.cpp)

[645. Set Mismatch.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/645.%20Set%20Mismatch.cpp)

## Bit manipulation
[Detailed explanation and generalization of the bitwise operation method for single numbers](https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers)

[136. Single Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/136.%20Single%20Number.cpp)

[137. Single Number II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/137.%20Single%20Number%20II.cpp)

[260. Single Number III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/260.%20Single%20Number%20III.cpp)

[169. Majority Element.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/169.%20Majority%20Element.cpp)

[187. Repeated DNA Sequences.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/187.%20Repeated%20DNA%20Sequences.cpp)

[190. Reverse Bits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/190.%20Reverse%20Bits.cpp)

[191. Number of 1 Bits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/191.%20Number%20of%201%20Bits.cpp)

[239. Sliding Window Maximum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/239.%20Sliding%20Window%20Maximum.cpp)

[268. Missing Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/268.%20Missing%20Number.cpp)

[338. Counting Bits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/338.%20Counting%20Bits.cpp)

[342. Power of Four.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/342.%20Power%20of%20Four.cpp)

[477. Total Hamming Distance.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/477.%20Total%20Hamming%20Distance.cpp)

## Binary Search

[二分查找详解](https://github.com/keineahnung2345/fucking-algorithm/blob/note/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E8%AF%A6%E8%A7%A3.md)

[Binary Search for Beginners [Problems | Patterns | Sample solutions]](https://leetcode.com/discuss/general-discussion/691825/binary-search-for-beginners-problems-patterns-sample-solutions)

### "378. Kth Smallest Element in a Sorted Matrix" and its variant
[Summary of solutions for problems "reducible" to LeetCode 378](https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378)

[378. Kth Smallest Element in a Sorted Matrix.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/378.%20Kth%20Smallest%20Element%20in%20a%20Sorted%20Matrix.cpp)

[373. Find K Pairs with Smallest Sums.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/373.%20Find%20K%20Pairs%20with%20Smallest%20Sums.cpp)

[668. Kth Smallest Number in Multiplication Table.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/668.%20Kth%20Smallest%20Number%20in%20Multiplication%20Table.cpp)

[719. Find K-th Smallest Pair Distance.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/719.%20Find%20K-th%20Smallest%20Pair%20Distance.cpp)

[786. K-th Smallest Prime Fraction.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/786.%20K-th%20Smallest%20Prime%20Fraction.cpp)

### find local maximum/minimum
[162. Find Peak Element.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/162.%20Find%20Peak%20Element.cpp)

***

[35. Search Insert Position.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/35.%20Search%20Insert%20Position.cpp)

[69. Sqrt(x).cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/69.%20Sqrt(x).cpp)

[74. Search a 2D Matrix.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/74.%20Search%20a%202D%20Matrix.cpp)

[167. Two Sum II - Input array is sorted.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/167.%20Two%20Sum%20II%20-%20Input%20array%20is%20sorted.cpp)

[230. Kth Smallest Element in a BST.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/230.%20Kth%20Smallest%20Element%20in%20a%20BST.cpp)

[240. Search a 2D Matrix II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/240.%20Search%20a%202D%20Matrix%20II.cpp)

[287. Find the Duplicate Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/287.%20Find%20the%20Duplicate%20Number.cpp)

[349. Intersection of Two Arrays.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/349.%20Intersection%20of%20Two%20Arrays.cpp)

[350. Intersection of Two Arrays II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/350.%20Intersection%20of%20Two%20Arrays%20II.cpp)

[367. Valid Perfect Square.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/367.%20Valid%20Perfect%20Square.cpp)

[374. Guess Number Higher or Lower.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/374.%20Guess%20Number%20Higher%20or%20Lower.cpp)

[392. Is Subsequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/392.%20Is%20Subsequence.cpp)

[441. Arranging Coins.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/441.%20Arranging%20Coins.cpp)

[454. 4Sum II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/454.%204Sum%20II.cpp)

[704. Binary Search.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/704.%20Binary%20Search.cpp)

[744. Find Smallest Letter Greater Than Target.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target.cpp)

[852. Peak Index in a Mountain Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/852.%20Peak%20Index%20in%20a%20Mountain%20Array.cpp)

[981. Time Based Key-Value Store.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/981.%20Time%20Based%20Key-Value%20Store.cpp)

[1011. Capacity To Ship Packages Within D Days.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1011.%20Capacity%20To%20Ship%20Packages%20Within%20D%20Days.cpp)

[1111. Maximum Nesting Depth of Two Valid Parentheses Strings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1111.%20Maximum%20Nesting%20Depth%20of%20Two%20Valid%20Parentheses%20Strings.cpp)

[1235. Maximum Profit in Job Scheduling.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1235.%20Maximum%20Profit%20in%20Job%20Scheduling.cpp)

[1237. Find Positive Integer Solution for a Given Equation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1237.%20Find%20Positive%20Integer%20Solution%20for%20a%20Given%20Equation.cpp)

## Backtracking
[A general approach to backtracking questions in Java (Subsets, Permutations, Combination Sum, Palindrome Partioning)](https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning))

[39. Combination Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/39.%20Combination%20Sum.cpp)

[40. Combination Sum II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/40.%20Combination%20Sum%20II.cpp)

[216. Combination Sum III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/216.%20Combination%20Sum%20III.cpp)

[46. Permutations.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/46.%20Permutations.cpp)

[47. Permutations II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/47.%20Permutations%20II.cpp)

[78. Subsets.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/78.%20Subsets.cpp)

[90. Subsets II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/90.%20Subsets%20II.cpp)

[131. Palindrome Partitioning.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/131.%20Palindrome%20Partitioning.cpp)

***

[51. N-Queens.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/51.%20N-Queens.cpp)

[52. N-Queens II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/52.%20N-Queens%20II.cpp)

[211. Add and Search Word - Data structure design.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/211.%20Add%20and%20Search%20Word%20-%20Data%20structure%20design.cpp)

[401. Binary Watch.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/401.%20Binary%20Watch.cpp)

[784. Letter Case Permutation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/784.%20Letter%20Case%20Permutation.cpp)

[980. Unique Paths III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/980.%20Unique%20Paths%20III.cpp)

[1079. Letter Tile Possibilities.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1079.%20Letter%20Tile%20Possibilities.cpp)

[1219. Path with Maximum Gold.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1219.%20Path%20with%20Maximum%20Gold.cpp)

[1286. Iterator for Combination.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1286.%20Iterator%20for%20Combination.cpp)

## Dynamic Programming
[Dynamic Programming Patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns)

[DP for Beginners [Problems | Patterns | Sample Solutions]](https://leetcode.com/discuss/general-discussion/662866/dp-for-beginners-problems-patterns-sample-solutions)

[Checking for "Overlapping subproblem" property](https://github.com/keineahnung2345/fucking-algorithm/blob/note/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E4%B9%8B%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE.md#%E5%9B%9B%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)

[How to solve DP - String? Template and 4 Steps to be followed.](https://leetcode.com/discuss/general-discussion/651719/how-to-solve-dp-string-template-and-4-steps-to-be-followed)

[My experience and notes for learning DP](https://leetcode.com/discuss/general-discussion/475924/My-experience-and-notes-for-learning-DP)

[DP problem categories](https://zhuanlan.zhihu.com/p/126546914)

[Dynamic Programming Patterns](https://leetcode.com/discuss/interview-question/778035/dynamic-programming-patterns)

[303. Range Sum Query - Immutable.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/303.%20Range%20Sum%20Query%20-%20Immutable.cpp)

[312. Burst Balloons.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/312.%20Burst%20Balloons.cpp)

[338. Counting Bits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/338.%20Counting%20Bits.cpp)

[392. Is Subsequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/392.%20Is%20Subsequence.cpp)

[413. Arithmetic Slices.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/413.%20Arithmetic%20Slices.cpp)

[486. Predict the Winner.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/486.%20Predict%20the%20Winner.cpp)

[647. Palindromic Substrings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/647.%20Palindromic%20Substrings.cpp)

[746. Min Cost Climbing Stairs.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/746.%20Min%20Cost%20Climbing%20Stairs.cpp)

[838. Push Dominoes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/838.%20Push%20Dominoes.cpp)

[931. Minimum Falling Path Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/931.%20Minimum%20Falling%20Path%20Sum.cpp)

[983. Minimum Cost For Tickets.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/983.%20Minimum%20Cost%20For%20Tickets.cpp)

[1025. Divisor Game.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1025.%20Divisor%20Game.cpp)

[1027. Longest Arithmetic Sequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1027.%20Longest%20Arithmetic%20Sequence.cpp)

[1048. Longest String Chain.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1048.%20Longest%20String%20Chain.cpp)

[1074. Number of Submatrices That Sum to Target.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1074.%20Number%20of%20Submatrices%20That%20Sum%20to%20Target.cpp)

[1130. Minimum Cost Tree From Leaf Values.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1130.%20Minimum%20Cost%20Tree%20From%20Leaf%20Values.cpp)

[1143. Longest Common Subsequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1143.%20Longest%20Common%20Subsequence.cpp)

[1147. Longest Chunked Palindrome Decomposition.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1147.%20Longest%20Chunked%20Palindrome%20Decomposition.cpp)

[1235. Maximum Profit in Job Scheduling.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1235.%20Maximum%20Profit%20in%20Job%20Scheduling.cpp)

[1277. Count Square Submatrices with All Ones.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1277.%20Count%20Square%20Submatrices%20with%20All%20Ones.cpp)

[1289. Minimum Falling Path Sum II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1289.%20Minimum%20Falling%20Path%20Sum%20II.cpp)

[1314. Matrix Block Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1314.%20Matrix%20Block%20Sum.cpp)

[1359. Count All Valid Pickup and Delivery Options.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1359.%20Count%20All%20Valid%20Pickup%20and%20Delivery%20Options.cpp)

[1388. Pizza With Slices.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1388.%20Pizza%20With%20Slices.cpp)

[1397. Find All Good Strings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1397.%20Find%20All%20Good%20Strings.cpp)

[1402. Reducing Dishes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1402.%20Reducing%20Dishes.cpp)

[1405. Longest Happy String.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1405.%20Longest%20Happy%20String.cpp)

### Stock series

[Leetcode discussion - Most consistent ways of dealing with the series of stock problems](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)

[121. Best Time to Buy and Sell Stock.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/121.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock.cpp)

[122. Best Time to Buy and Sell Stock II](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II.cpp)

[123. Best Time to Buy and Sell Stock III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/123.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20III.cpp)

[188. Best Time to Buy and Sell Stock IV.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/188.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20IV.cpp)

[309. Best Time to Buy and Sell Stock with Cooldown.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/309.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Cooldown.cpp)

[714. Best Time to Buy and Sell Stock with Transaction Fee.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/714.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20with%20Transaction%20Fee.cpp)

### House bobber seires
[198. House Robber.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/198.%20House%20Robber.cpp)

[213. House Robber II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/213.%20House%20Robber%20II.cpp)

[337. House Robber III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/337.%20House%20Robber%20III.cpp)

### Knapsack problem

#### 0/1 knapsack problem
[416. Partition Equal Subset Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/416.%20Partition%20Equal%20Subset%20Sum.cpp)

[494. Target Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/494.%20Target%20Sum.cpp)

#### Unbounded knapsack problem
[322. Coin Change.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/322.%20Coin%20Change.cpp)

[518. Coin Change 2.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/518.%20Coin%20Change%202.cpp)

#### Two-constraint knapsack problem
[474. Ones and Zeroes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/474.%20Ones%20and%20Zeroes.cpp)

### LIS
[300. Longest Increasing Subsequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/300.%20Longest%20Increasing%20Subsequence.cpp)

[354. Russian Doll Envelopes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/354.%20Russian%20Doll%20Envelopes.cpp)

[368. Largest Divisible Subset.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/368.%20Largest%20Divisible%20Subset.cpp)

### DP + Tree
[124. Binary Tree Maximum Path Sum.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/124.%20Binary%20Tree%20Maximum%20Path%20Sum.cpp)

[337. House Robber III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/337.%20House%20Robber%20III.cpp)

[543. Diameter of Binary Tree.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/543.%20Diameter%20of%20Binary%20Tree.cpp)

### Digits
[233. Number of Digit One.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/233.%20Number%20of%20Digit%20One.cpp)

[902. Numbers At Most N Given Digit Set.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/902.%20Numbers%20At%20Most%20N%20Given%20Digit%20Set.cpp)

[1015. Smallest Integer Divisible by K.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1015.%20Smallest%20Integer%20Divisible%20by%20K.cpp)

### Counting
[62. Unique Paths.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/62.%20Unique%20Paths.cpp)

[63. Unique Paths II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/63.%20Unique%20Paths%20II.cpp)

[96. Unique Binary Search Trees.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/96.%20Unique%20Binary%20Search%20Trees.cpp)

### Recursion
[70. Climbing Stairs.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/70.%20Climbing%20Stairs.cpp)

[509. Fibonacci Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/509.%20Fibonacci%20Number.cpp)

[935. Knight Dialer.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/935.%20Knight%20Dialer.cpp)

[957. Prison Cells After N Days.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/957.%20Prison%20Cells%20After%20N%20Days.cpp)

[1137. N-th Tribonacci Number.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1137.%20N-th%20Tribonacci%20Number.cpp)

### Probability
[808. Soup Servings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/808.%20Soup%20Servings.cpp)

[837. New 21 Game.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/837.%20New%2021%20Game.cpp)

### Game

### Nim game
[292. Nim Game.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/292.%20Nim%20Game.cpp)

#### Stone game
[877. Stone Game.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/877.%20Stone%20Game.cpp)

[1140. Stone Game II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1140.%20Stone%20Game%20II.cpp)

[1406. Stone Game III.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1406.%20Stone%20Game%20III.cpp)

[1510. Stone Game IV.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1510.%20Stone%20Game%20IV.cpp)

#### Tic Tac Toe game
[794. Valid Tic-Tac-Toe State.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/794.%20Valid%20Tic-Tac-Toe%20State.cpp)

[1275. Find Winner on a Tic Tac Toe Game.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1275.%20Find%20Winner%20on%20a%20Tic%20Tac%20Toe%20Game.cpp)

#### DFS + memorization
[329. Longest Increasing Path in a Matrix.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/329.%20Longest%20Increasing%20Path%20in%20a%20Matrix.cpp)

[576. Out of Boundary Paths.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/576.%20Out%20of%20Boundary%20Paths.cpp)

## Dynamic Programming + Bitmask
[A simple tutorial on this bitmasking problem](https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem)

[464. Can I Win.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/464.%20Can%20I%20Win.cpp)

[526. Beautiful Arrangement.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/526.%20Beautiful%20Arrangement.cpp)

[698. Partition to K Equal Sum Subsets](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/698.%20Partition%20to%20K%20Equal%20Sum%20Subsets.cpp)

[1349. Maximum Students Taking Exam.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1349.%20Maximum%20Students%20Taking%20Exam.cpp)

[1434. Number of Ways to Wear Different Hats to Each Other.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1434.%20Number%20of%20Ways%20to%20Wear%20Different%20Hats%20to%20Each%20Other.cpp)

[1494. Parallel Courses II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1494.%20Parallel%20Courses%20II.cpp)

[1595. Minimum Cost to Connect Two Groups of Points.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1595.%20Minimum%20Cost%20to%20Connect%20Two%20Groups%20of%20Points.cpp)

## KMP
[KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)

[28. Implement strStr().cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/28.%20Implement%20strStr().cpp)

[187. Repeated DNA Sequences.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/187.%20Repeated%20DNA%20Sequences.cpp)

[214. Shortest Palindrome.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/214.%20Shortest%20Palindrome.cpp)

[796. Rotate String.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/796.%20Rotate%20String.cpp)

[1392. Longest Happy Prefix.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1392.%20Longest%20Happy%20Prefix.cpp)

[1397. Find All Good Strings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1397.%20Find%20All%20Good%20Strings.cpp)

[1408. String Matching in an Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1408.%20String%20Matching%20in%20an%20Array.cpp)

## Manacher's algorithm
[Longest Palindromic Substring O(N) Manacher's Algorithm](https://www.youtube.com/watch?v=nbTSfrEfo6M&feature=emb_logo)

[Manacher’s Algorithm – Linear Time Longest Palindromic Substring – Part 4](https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-4/)

[[译]最长回文子串(Longest Palindromic Substring) Part I](https://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Par-I.html)

[[译+改]最长回文子串(Longest Palindromic Substring) Part II](https://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Part-II.html)

[5. Longest Palindromic Substring.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/5.%20Longest%20Palindromic%20Substring.cpp)

[214. Shortest Palindrome.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/214.%20Shortest%20Palindrome.cpp)

[647. Palindromic Substrings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/647.%20Palindromic%20Substrings.cpp)

## Greedy
[Greedy for Beginners [Problems | Sample solutions]](https://leetcode.com/discuss/general-discussion/669996/Greedy-for-Beginners-Problems-or-Sample-solutions)

### Interval
[56. Merge Intervals.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/56.%20Merge%20Intervals.cpp)

[435. Non-overlapping Intervals.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/435.%20Non-overlapping%20Intervals.cpp)

[452. Minimum Number of Arrows to Burst Balloons.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/452.%20Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons.cpp)

[1589. Maximum Sum Obtained of Any Permutation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1589.%20Maximum%20Sum%20Obtained%20of%20Any%20Permutation.cpp)

[1109. Corporate Flight Bookings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1109.%20Corporate%20Flight%20Bookings.cpp)

## Rolling hash, Rabin-Karp
[Why is the base used to compute hashes in Rabin–Karp always primes?](https://cs.stackexchange.com/questions/28019/why-is-the-base-used-to-compute-hashes-in-rabin-karp-always-primes/28024#28024)

[686. Repeated String Match.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/686.%20Repeated%20String%20Match.cpp)

[1044. Longest Duplicate Substring.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1044.%20Longest%20Duplicate%20Substring.cpp)

[1147. Longest Chunked Palindrome Decomposition.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1147.%20Longest%20Chunked%20Palindrome%20Decomposition.cpp)

## Regex
[591. Tag Validator.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/591.%20Tag%20Validator.cpp)

[1071. Greatest Common Divisor of Strings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1071.%20Greatest%20Common%20Divisor%20of%20Strings.cpp)

## Trie

[Article on Trie. General Template and List of problems.](https://leetcode.com/discuss/general-discussion/680706/Article-on-Trie.-General-Template-and-List-of-problems.)

[208. Implement Trie (Prefix Tree).cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/208.%20Implement%20Trie%20(Prefix%20Tree).cpp)

[211. Add and Search Word - Data structure design.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/211.%20Add%20and%20Search%20Word%20-%20Data%20structure%20design.cpp)

[212. Word Search II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/212.%20Word%20Search%20II.cpp)

[336. Palindrome Pairs.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/336.%20Palindrome%20Pairs.cpp)

[1268. Search Suggestions System.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1268.%20Search%20Suggestions%20System.cpp)

[648. Replace Words.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/648.%20Replace%20Words.cpp)

[676. Implement Magic Dictionary.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/676.%20Implement%20Magic%20Dictionary.cpp)

[720. Longest Word in Dictionary.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/720.%20Longest%20Word%20in%20Dictionary.cpp)

## Suffix Tree
[Trie, Suffix Tree, Suffix Array](https://www.hackerearth.com/de/practice/notes/trie-suffix-tree-suffix-array/)

[Ukkonen's suffix tree algorithm in plain English](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english?rq=1)

[1408. String Matching in an Array.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1408.%20String%20Matching%20in%20an%20Array.cpp)

## Union Find

Union find problems look alike graph problems, if we only care whether two nodes are connected, not their distance, we should use union find.(?, inspired by 1627)

[959. Regions Cut By Slashes.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/959.%20Regions%20Cut%20By%20Slashes.cpp)

[547. Friend Circles.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/547.%20Friend%20Circles.cpp)

[1391. Check if There is a Valid Path in a Grid.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1391.%20Check%20if%20There%20is%20a%20Valid%20Path%20in%20a%20Grid.cpp)

[399. Evaluate Division.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/399.%20Evaluate%20Division.cpp)

[130. Surrounded Regions.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/130.%20Surrounded%20Regions.cpp)

[128. Longest Consecutive Sequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/128.%20Longest%20Consecutive%20Sequence.cpp)

[1559. Detect Cycles in 2D Grid.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1559.%20Detect%20Cycles%20in%202D%20Grid.cpp)

[1562. Find Latest Group of Size M.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1562.%20Find%20Latest%20Group%20of%20Size%20M.cpp)

[1627. Graph Connectivity With Threshold](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1627.%20Graph%20Connectivity%20With%20Threshold.cpp)

### Union by rank
[684. Redundant Connection.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/684.%20Redundant%20Connection.cpp)

## Segment Tree
[307. Range Sum Query - Mutable(solution)](https://leetcode.com/articles/range-sum-query-mutable/)

[A Recursive approach to Segment Trees, Range Sum Queries & Lazy Propagation](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/)

[307. Range Sum Query - Mutable Medium.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/307.%20Range%20Sum%20Query%20-%20Mutable%20Medium.cpp)

[315. Count of Smaller Numbers After Self.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/315.%20Count%20of%20Smaller%20Numbers%20After%20Self.cpp)

[850. Rectangle Area II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/850.%20Rectangle%20Area%20II.cpp)

[673. Number of Longest Increasing Subsequence.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/673.%20Number%20of%20Longest%20Increasing%20Subsequence.cpp)

[218. The Skyline Problem.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/218.%20The%20Skyline%20Problem.cpp)

[1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1505.%20Minimum%20Possible%20Integer%20After%20at%20Most%20K%20Adjacent%20Swaps%20On%20Digits.cpp)

## Binary Indexed Tree

[Java using Binary Indexed Tree with clear explanation](https://leetcode.com/problems/range-sum-query-mutable/discuss/75753/Java-using-Binary-Indexed-Tree-with-clear-explanation)

[Topcode binary indexed trees tutorial](https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees)

[307. Range Sum Query - Mutable Medium.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/307.%20Range%20Sum%20Query%20-%20Mutable%20Medium.cpp)

[315. Count of Smaller Numbers After Self.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/315.%20Count%20of%20Smaller%20Numbers%20After%20Self.cpp)

[1395. Count Number of Teams.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1395.%20Count%20Number%20of%20Teams.cpp)

[218. The Skyline Problem.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/218.%20The%20Skyline%20Problem.cpp)

[1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1505.%20Minimum%20Possible%20Integer%20After%20at%20Most%20K%20Adjacent%20Swaps%20On%20Digits.cpp)

[Binary Indexed Tree : Range Updates and Point Queries](https://www.geeksforgeeks.org/binary-indexed-tree-range-updates-point-queries/)

[1589. Maximum Sum Obtained of Any Permutation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1589.%20Maximum%20Sum%20Obtained%20of%20Any%20Permutation.cpp)

## Line Sweep
[850. Rectangle Area II.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/850.%20Rectangle%20Area%20II.cpp)

[218. The Skyline Problem.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/218.%20The%20Skyline%20Problem.cpp)

[1109. Corporate Flight Bookings.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1109.%20Corporate%20Flight%20Bookings.cpp)

[1589. Maximum Sum Obtained of Any Permutation.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1589.%20Maximum%20Sum%20Obtained%20of%20Any%20Permutation.cpp)

## Angular Sweep
[1453. Maximum Number of Darts Inside of a Circular Dartboard.cpp](https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/1453.%20Maximum%20Number%20of%20Darts%20Inside%20of%20a%20Circular%20Dartboard.cpp)
