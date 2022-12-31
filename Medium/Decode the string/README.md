<h2><a href="https://practice.geeksforgeeks.org/problems/decode-the-string2444/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article">Decode the string</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">An encoded string (<strong>s</strong>) is given, and the task is to decode it. The encoding pattern is that the occurrence of the string is given at the starting of the string and each string is enclosed by square brackets.<br>
<strong>Note:&nbsp;</strong>The occurance of a single&nbsp;string is&nbsp;less than 1000.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = 1[b]
<strong>Output:</strong> b
<strong>Explaination:</strong> 'b' is present only one time.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> s = 3[b2[ca]]
<strong>Output:</strong> bcacabcacabcaca
<strong>Explaination:</strong> 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>decodedString()</strong> which takes s as the input parameter and returns the decoded string.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(|s|)<br>
<strong>Expected Auxiliary Space:</strong> O(|s|)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ |s| ≤ 10<sup>3</sup>&nbsp;</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Facebook</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Stack</code>&nbsp;<code>Backtracking</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;