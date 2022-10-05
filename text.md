# Homework 1
#### B10902033 林祐辰
<br>
Problem 5:<br>
(a) Complexity:<br>
1.Prove 2.Prove 3.Prove 4.Prove 5.Prove 6.(a)Prove 6.(b)Prove(refer to formula in text book 3-20 and 3-21)<br>
<img src="./ada_1.jpg" style="zoom:15%" /><br>
<br>
(b) Fill-in: 4 < 1 < 2 < 5 < 3 < 6<br>
<br>
(c) Recursion: 1. O(n ^ 1.5) 2. O(n)<br>
<img src="./ada_2.jpg" style="zoom:15%" /><br>
<br>
Problem 6:<br>
(a)<br>
1.False 2.True 3.False 4.True 5.True<br>
(b)<br>
Algorithm:<br>
First do a merge sort on the n strings and in the merge functions, compair two strings character by character, when compairing put two characters in the gene comparator, if the results is two strings are the same then put them in a group, else continue doing the merge sort.<br>
Correctness:<br>
First two strings in the same group must be identical because the algorithm only put them in the same group if they are the same. Second the algorithm will correctly seperate different strings since merge sort will traverse through every strings at least one time.<br>
Time complexity:<br>
Because the time complexity of merge sort is O(n * log n) and in the merge function comparing two strings need O(k), so the total time complexity will be O(n * k * log n).<br>
(c)<br>

(d)<br>

(e)<br>
<img src="./ada_3.jpg" style="zoom:20%" /><br>
(f)<br>

(g)<br>