<h2><a href="https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1">Find Transition Point</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <strong>sorted array </strong>containing only <strong>0s </strong>and <strong>1s</strong>, find the <strong>transition point</strong>, i.e., the <strong>first index </strong>where <strong>1 </strong>was observed, and <strong>before that</strong>, only 0 was observed.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 5
arr[] = {0,0,0,1,1}
<strong>Output:</strong> 3
<strong>Explanation:</strong> index 3 is the transition 
point where 1 begins.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 4
arr[] = {0,0,0,0}
<strong>Output:</strong> -1
<strong>Explanation:</strong> Since, there is no "1",
the answer is -1.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. The task is to complete the function <strong>transitionPoint()</strong> that takes array <strong>arr</strong> and <strong>N</strong> as input parameters and returns the <strong>0-based </strong>index of the position where <strong>0</strong> ends and 1 begins. If array does not have any <strong>1</strong>, return <strong>-1</strong>. If array does not have any <strong>0</strong>, return <strong>0</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(Log(N))<br><strong>Expected Auxiliary Space: </strong>O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>5</sup><br>0 ≤ arr[i] ≤ 1</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;