# algortihms1
Algorithms class homework 7

Problem 1: Palindrome
  Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
  Example 1: Input: "aba" Output: True
  Example 2: Input: "abca" Output: True Explanation: You could delete the character 'c'.
  Example 3: Input: "abcd" Output: False

Problem 2: Special Fibonacci Sequence
  Instead of a regular Fibonacci number, you are supposed to calculate a special one as follows:
  F(n) = F(n-1)+ 2 * F(n-2) + 3 * F(n-3)
  As an example, if F(0) = F(1) = F(2) = 1, then we have:
  F(3) = F(2) + 2 * F(1) + 3 * F(0) = 1 + 2 + 3 = 6 F(4) = F(3) + 2 * F(2) + 3 * F(1) = 6 + 2 + 3 = 11

  Given F(0), F(1), F(2), and N, your job is to calculate F(N).
  Input Format
  First number is F(0), second number is F(1), third number is F(2), and last number is N.
  Example input: 1 1 1 4

  Output Format
  Print the Nth special Fibonnaci number.
  Example output: 11

Problem 3: Pushups and Football Score
  A friend of yours is on the cheer squad for their football team. Each time the team scores, the cheer squad does pushups — one for each point the team has scored so far. If the teams     
  scores a touchdown (7 points), the squad does 7 pushups. If the team then scores a field goal (3 points), the cheer squad does 10 pushups. If the team then scores a safety (2 points), the 
  squad will do 12 pushups. At the end of that game, the squad will end up having done 7+10+12=29 pushups!

  You meet your friend after a game, and they say “Boy, am I tired! I did a total of n pushups at the game today!” and promptly collapse from exhaustion. Given n, the number of pushups, can   you figure out how the team scored? More than one score may be possible. For example, for 29 pushups, the team could have scored 3, then 2, then 2, then 7, for a total of 14 points. If   
  so, find the highest possible score.

  Sample Input:
    29 3
    7 3 2
  Sample Output:
    14
