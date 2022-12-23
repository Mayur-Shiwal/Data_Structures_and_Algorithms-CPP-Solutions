<h2><a href="https://practice.geeksforgeeks.org/problems/design-twitter/1">Design Twitter</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:</span></p>

<ol>
	<li><span style="font-size:18px"><strong>postTweet (userId, tweetId)</strong>: Compose a new tweet.</span></li>
	<li><span style="font-size:18px"><strong>getNewsFeed (userId)</strong>: Retrieve the 10 most recent tweet ids in the user's news feed (If total number of tweets in news feed is less than 10, then return all). Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.</span></li>
	<li><span style="font-size:18px"><strong>follow (followerId, followeeId)</strong>: Follower follows a followee.</span></li>
	<li><span style="font-size:18px"><strong>unfollow (followerId, followeeId)</strong>: Follower unfollows a followee.</span></li>
</ol>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px">postTweet(1, 5);</span>
<span style="font-size:18px">getNewsFeed(1);</span>
<span style="font-size:18px">follow(1, 2);</span>
<span style="font-size:18px">postTweet(2, 6);</span>
<span style="font-size:18px">getNewsFeed(1);</span>
<span style="font-size:18px">unfollow(1, 2);</span>
<span style="font-size:18px">getNewsFeed(1);</span>

<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">[5]</span>
<span style="font-size:18px">[6, 5]</span>
<span style="font-size:18px">[5]</span>
<span style="font-size:18px">
<strong>Explanation: </strong>
postTweet(1,5): User1 posts a new tweet (id=5)
getNewsFeed(1): return a list with 1 tweet [5]</span>
<span style="font-size:18px">follow(1,2)   : User 1 follows user 2.
postTweet(2,6): User2 posts a new tweet (id=6)</span>
<span style="font-size:18px">getNewsFeed(1): return a list with 2 tweets 
&nbsp;             [6,5]. One his own tweet and one
&nbsp;               followee's tweet (sorted from 
&nbsp;               most recent to least recent).</span>
<span style="font-size:18px">unfollow(1,2) : User 1 unfollows user 2</span>
<span style="font-size:18px">getNewsFeed(1): return a list with 1 tweet [5]
&nbsp;               ,because user 1 is no longer
&nbsp;               following anyone.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>follow(1, 2);
postTweet(1, 3);
getNewsFeed(2);</span>

<span style="font-size:18px"><strong>Output:
</strong>[]</span>

<span style="font-size:18px"><strong>Explanation:</strong>
follow(1,2)   : User 1 follows user 2.
postTweet(1,3): User1 posts a new tweet (id=3)
getNewsFeed(2): return a list with 0 tweet [],
                because user2 have no tweets 
                and don't follow anyone (user1
                follows user2 but user2 don't
&nbsp;               follow anyone)</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp; </strong><br>
You don't need to read input or print anything. Your task is to design your data structure inside <strong>class Twitter</strong> and complete the functions <strong>postTweet()</strong>, <strong>getNewsFeed()</strong>, <strong>follow()</strong>, <strong>unfollow()</strong> and the <strong>constructor</strong>.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<ul>
	<li><span style="font-size:18px"><code>1 &lt;= no. of queries&nbsp;&lt;= 1000</code></span></li>
	<li><span style="font-size:18px"><code>1 &lt;= userId, tweetId, followerId, followeeId&nbsp;&lt;= 10<sup>5</sup></code></span></li>
</ul>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Heap</code>&nbsp;<code>Stack</code>&nbsp;<code>Design-Pattern</code>&nbsp;<code>Data Structures</code>&nbsp;