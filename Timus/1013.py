#!/usr/bin/env python
# coding=utf-8

def matrixMul(A, B, m):
    ret = [[0, 0], [0, 0]]
    for i in range(0, 2):
        for j in range(0, 2):
            for k in range(0, 2):
                ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % m
    return ret;

def qm(a, b, m):
    if b == 1:
        return a
    tmp = qm(a, b / 2, m)
    tmp = matrixMul(tmp, tmp, m)
    if b % 2 == 1:
        return matrixMul(a, tmp, m)
    else:
        return tmp

n = int(input())
k = int(input())
m = int(input())

k = k-1

mx = [[k, 1], [k, 0]]
g = [k*k, k]

if n == 2:
    ans = (g[0] + g[1]) % m
else:
    n -= 2
    tmp = qm(mx, n, m)
    ans = g[0] * tmp[0][0] + g[1] * tmp[1][0]
    ans += g[0] * tmp[0][1] + g[1] * tmp[1][1]
    ans %= m

print ans

