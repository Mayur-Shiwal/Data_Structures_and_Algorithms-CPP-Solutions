<h2><a href="https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1">Print Matrix in snake Pattern</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a<strong>&nbsp;matrix&nbsp;</strong>of size<strong> N x N</strong>. Print the elements of the matrix in the snake like pattern depicted below.<br><img style="height: 375px; width: 500px;" src="https://contribute.geeksforgeeks.org/wp-content/uploads/snake-pattern.jpg" alt=""></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
N = 3 
matrix[][] = {{45, 48, 54},
&nbsp;            {21, 89, 87}
&nbsp;            {70, 78, 15}}
<strong>Output</strong>: <br>45 48 54 87 89 21 70 78 15&nbsp;
<strong>Explanation</strong>:
Matrix is as below:
45 48 54
21 89 87
70 78 15
Printing it in snake pattern will lead to 
the output as 45 48 54 87 89 21 70 78 15.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
N = 2
matrix[][] = {{1, 2},
&nbsp;             {3, 4}}
<strong>Output</strong>: <br>1 2 4 3
<strong>Explanation</strong>:
Matrix is as below:
1 2&nbsp;
3 4
Printing it in snake pattern will 
give output as 1 2 4 3.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong></span><br><span style="font-size: 18px;">You dont need to read input or print anything. Complete the function <strong>snakePattern()</strong> that takes matrix as input parameter and returns a list of integers in order of the values visited in the snake pattern.&nbsp;</span><br><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N * N)<br><strong>Expected Auxiliary Space:</strong> O(N * N) for the resultant list only.<br><br><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>3</sup><br>1 &lt;= mat[i][j] &lt;= 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;