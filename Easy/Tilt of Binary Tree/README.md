<h2><a href="https://practice.geeksforgeeks.org/problems/tilt-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article">Tilt of Binary Tree</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given a binary tree of size <strong>N+1</strong>, your task is to complete the function <strong>tiltTree()</strong>,&nbsp;that return the tilt of the whole tree. The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null nodes are assigned tilt to be zero. Therefore, tilt of the whole tree is defined as the sum of all nodes’ tilt.</span></p>

<p><strong><span style="font-size:18px">Examples 1:</span></strong></p>

<pre><span style="font-size:20px"><strong>Input:</strong> 
       1
      / \
     2   3
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><strong><span style="font-size:20px">Input:</span></strong>
<span style="font-size:20px">        4 </span>
<span style="font-size:20px">       / \</span>
<span style="font-size:20px">      2   9 </span>
<span style="font-size:20px">     / \   \</span>
<span style="font-size:20px">    3   5   7 </span>
<span style="font-size:20px"><strong>Output:</strong> 15 </span>
<strong><span style="font-size:20px">Explanation:</span></strong>
<span style="font-size:20px">Tilt of node 3 : 0 </span>
<span style="font-size:20px">Tilt of node 5 : 0 </span>
<span style="font-size:20px">Tilt of node 7 : 0</span>
<span style="font-size:20px">Tilt of node 2 : |3-5| = 2 </span>
<span style="font-size:20px">Tilt of node 9 : |0-7| = 7 </span>
<span style="font-size:20px">Tilt of node 4 : |(3+5+2)-(9+7)| = 6 </span>
<span style="font-size:20px">Tilt of binary tree : 0 + 0 + 0 + 2 + 7 + 6 = 15</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>tiltTree()&nbsp;</strong>which takes root node of the tree as input parameter and returns an integer denoting the tilt of the tree. If the tree is empty, return 0.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
0&lt;=N&lt;=500</span><br>
&nbsp;</p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;