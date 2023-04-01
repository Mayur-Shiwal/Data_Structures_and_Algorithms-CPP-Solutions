<h2><a href="https://practice.geeksforgeeks.org/problems/maximum-number-of-partitions-that-can-be-sorted-individually-to-make-sorted2926/1">Maximum number of partitions that can be sorted individually to make sorted</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array<strong> arr[ ]</strong> of size<strong> n </strong>such that elements of arr[ ] in range<strong> [0, 1, ..n-1]</strong>. Our task is to divide the array into the maximum number of partitions that can be sorted individually, then concatenated to make the whole array sorted. </span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {2, 1, 0, 3}
<strong>Output :</strong> 2
<strong>Explanation:</strong>
If divide arr[] into two partitions 
{2, 1, 0} and {3}, sort then and concatenate 
then, we get the whole array sorted.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {2, 1, 0, 3, 4, 5} <strong>
Output :</strong>  4 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>maxPartitions()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, and return the maximum number of partitions. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ T ≤ 100<br>
1 ≤ N ≤ 10<sup>5</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Sorting</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;