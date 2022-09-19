#!/usr/bin/python3
# coding=utf-8


def char_to_int(char):
    return ord(char) - 97


def flexradix(A, n, d):
    # Skriv koden din her
    pass


tests = (
    (([], 1), []),
    ((["a"], 1), ["a"]),
    ((["a", "b"], 1), ["a", "b"]),
    ((["b", "a"], 1), ["a", "b"]),
    ((["a", "z"], 1), ["a", "z"]),
    ((["z", "a"], 1), ["a", "z"]),
    ((["ba", "ab"], 2), ["ab", "ba"]),
    ((["b", "ab"], 2), ["ab", "b"]),
    ((["ab", "a"], 2), ["a", "ab"]),
    ((["zb", "za"], 2), ["za", "zb"]),
    ((["abc", "b"], 3), ["abc", "b"]),
    ((["xyz", "y"], 3), ["xyz", "y"]),
    ((["abc", "b"], 4), ["abc", "b"]),
    ((["xyz", "y"], 4), ["xyz", "y"]),
    ((["zyxy", "yxz"], 4), ["yxz", "zyxy"]),
    ((["abc", "b", "bbbb"], 4), ["abc", "b", "bbbb"]),
    ((["abcd", "abcd", "bbbb"], 4), ["abcd", "abcd", "bbbb"]),
    ((["abcd", "wxyz", "bbbb"], 4), ["abcd", "bbbb", "wxyz"]),
    ((["abcd", "wxyz", "bazy"], 4), ["abcd", "bazy", "wxyz"]),
    ((["a", "b", "c", "babcbababa"], 10), ["a", "b", "babcbababa", "c"]),
    ((["a", "b", "c", "babcbababa"], 10), ["a", "b", "babcbababa", "c"]),
    ((["w", "x", "y", "xxyzxyzxyz"], 10), ["w", "x", "xxyzxyzxyz", "y"]),
    ((["b", "a", "y", "xxyzxyzxyz"], 10), ["a", "b", "xxyzxyzxyz", "y"]),
    ((["jfiqdopvak", "nzvoquirej", "jfibopvmcq"], 10), ["jfibopvmcq", "jfiqdopvak", "nzvoquirej"]),
)

for test, solution in tests:
    student_answer = flexradix(test[0], len(test[0]), test[1])
    if student_answer != solution:
        print(
            "Feilet for testen {:}, resulterte i listen ".format(test)
            + "{:} i stedet for {:}.".format(student_answer, solution)
        )
