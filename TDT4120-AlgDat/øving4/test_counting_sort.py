#!/usr/bin/python3
# coding=utf-8


def counting_sort(A, n):
    k = 2048
    B = [0]*n
    C = [0]*k # Genererer array på lengde k
    for i in A:
        C[i] += 1 # Teller instanser av hvert tall
    for i in range(1,k):
        C[i] += C[i-1]
    # print(f"""A:{A}
    # B:{B}
    # C:{C}""")
    for i in range(n,0,-1): # Går baklengs for å gjøre algoritmen stabil
        # if (n == 0): return B
        num = A[i-1]
        B[C[num]-1] = num
        C[num] -= 1
    return B

tests = (
    ([], []),
    ([1], [1]),
    ([1, 2, 3, 4], [1, 2, 3, 4]),
    ([4, 3, 2, 1], [1, 2, 3, 4]),
    ([1, 1, 2, 1], [1, 1, 1, 2]),
    ([1281, 1, 2], [1, 2, 1281]),
    ([0, 2047, 0, 2047], [0, 0, 2047, 2047]),
    (
        [995, 334, 709, 999, 502, 303, 274, 488, 997, 568, 546, 756],
        [274, 303, 334, 488, 502, 546, 568, 709, 756, 995, 997, 999],
    ),
    (
        [648, 298, 568, 681, 795, 356, 603, 772, 373, 50, 253, 116],
        [50, 116, 253, 298, 356, 373, 568, 603, 648, 681, 772, 795],
    ),
)

for test, solution in tests:
    student_answer = counting_sort(test, len(test))
    if student_answer != solution:
        print(
            "Feilet for testen {:}, resulterte i listen ".format(test)
            + "{:} i stedet for {:}.".format(student_answer, solution)
        )
