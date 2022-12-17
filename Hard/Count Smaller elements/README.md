<h2><a href="https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1">Count Smaller elements</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>Arr&nbsp;</strong>of size <strong>N</strong>&nbsp;containing&nbsp;positive integers. Count number of smaller elements on right side of each array element.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7
Arr[] = {12, 1, 2, 3, 0, 11, 4}
<strong>Output: </strong>6 1 1 1 0 1 0
<strong>Explanation:</strong> There are 6 elements right
after 12. There are 1 element right after
1. And so on.
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
Arr[] = {1, 2, 3, 4, 5}
<strong>Output:</strong> 0 0 0 0 0
<strong>Explanation:</strong>&nbsp;There are 0 elements right
after 1. There are 0 elements right after
2. And so on.
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>constructLowerArray()</strong>&nbsp;which takes the&nbsp;array of&nbsp;integers&nbsp;<strong>arr </strong>and&nbsp;<strong>n&nbsp;</strong>as parameters and returns an array of integers denoting the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*logN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
0 ≤ Arr<sub>i&nbsp; </sub>≤ 10<sup>8</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Codenation</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Binary Search</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;