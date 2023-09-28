
338. Counting Bits

> Given an integer `n`, return an array `ans` of length `n + 1` such that for each i (`0 <= i <= n`), `ans[i]` *is the* ***number of*** `1`'***s*** in the binary representation of `i`.

```
n & n-1, represents the number of 1s in n without the least significant 1, which means that the least significant 1 in `n` is dropped. Like number 6, 110, the least significant 1 is the first 1 from left to right in `110`, so 6 & 5 = 4, which is 100, the number of 1s in 4 is 1, which is the number of 1s in 6 without the least significant 1. And like 8, the correspective binary is 1000, the least significant 1 is the forth 1 from left to right, so 8 & 7 = 0, which means that the number of 1s in 8 without the least significant 1 is 0, which is the number of 1s in 8.
```

## Example 1:

```
n = 2, binary = 10

[0, 1, 1]
```
