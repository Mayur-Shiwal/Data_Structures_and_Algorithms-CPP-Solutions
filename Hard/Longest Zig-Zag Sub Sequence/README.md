<h2><a href="https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence2656/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article">Longest Zig-Zag Sub Sequence</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>nums</strong> of <strong>n</strong>&nbsp;positive integers. The task is to find the longest Zig-Zag subsequence problem such that all elements of this are alternating (nums<sub>i-1</sub> &lt; nums<sub>i</sub> &gt; nums<sub>i+1</sub>&nbsp;or nums<sub>i-1</sub>&nbsp;&gt; nums<sub>i</sub>&nbsp;&lt; nums<sub>i+1</sub>).</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>nums = {1,5,4}
<strong>Output: </strong>3
<strong>Explanation: </strong>The entire sequenece is a 
Zig-Zag sequence.
</span></pre>

<p><span style="font-size:18px"><strong>Examplae 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>nums = {1,17,5,10,13,15,10,5,16,8}
<strong>Ooutput: </strong>7
<strong>Explanation: </strong>There are several subsequences
that achieve this length. 
One is {1,17,10,13,10,16,8}.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read or print anyhting. Your task is to complete the function ZigZagMaxLength()&nbsp;which takes the sequence&nbsp; nums as input parameter and returns the maximum length of alternating sequence.<br>
<br>
<strong>Expected Time Complexity:&nbsp;</strong>O(n)<br>
<strong>Expected Space Complexity:&nbsp;</strong>O(1)<br>
<br>
<strong>Constraints:</strong><br>
1 &lt;= n &lt;= 10<sup>5</sup></span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;