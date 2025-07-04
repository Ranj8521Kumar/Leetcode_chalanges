class Solution {
public:
    char kthCharacter(int k) {
/*
index -> binary -> no  of ones -> 'a' + no.  of ones
0   → 0000 → 0 → a
1   → 0001 → 1 → b
2   → 0010 → 1 → b
3   → 0011 → 2 → c
4   → 0100 → 1 → b
5   → 0101 → 2 → c
6   → 0110 → 2 → c
7   → 0111 → 3 → d
8   → 1000 → 1 → b
9   → 1001 → 2 → c
10  → 1010 → 2 → c
11  → 1011 → 3 → d
12  → 1100 → 2 → c
13  → 1101 → 3 → d
14  → 1110 → 3 → d
15  → 1111 → 4 → e

Pattern building:

0 1  →  +1 to each    1 2        

0 1 1 2  →  +1 to each 1 2 2 3

0 1 1 2 1 2 2 3  →  +1 to each  1 2 2 3 2 3 3 4

Resulting sequence (characters):
a b b c b c c d   b c c d c d d e


Index to Character Mapping:

Index:     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
Char:      a  b  b  c  b  c  c  d  b  c  c  d  d  d  e
*/

        return ('a' + popcount((uint)k-1));
    }
};