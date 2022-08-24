#!/usr/bin/python3
# coding=utf-8

def take_pieces(n_pieces):
    min_matches = 1
    max_matches = 7

    r = n_pieces - 1 if n_pieces - 1 else min_matches
    i = 1
    while (max_matches * i) + min_matches < n_pieces:
        r = n_pieces - ((max_matches * i) + min_matches)
        i += 1
    return r


if __name__ == "__main__":

    tests = [
        (1, None),
        (2, 1),
        (3, 2),
        (4, 3),
        (5, 4),
        (6, 5),
        (7, 6),
        (8, 7),
        (9, 1),
        (10, 2),
        (11, 3),
        (12, 4),
        (13, 5),
        (14, 6),
        (15, 7),
        (16, 1),
        (17, 2),
    ]

    for (test, correct_answer) in tests:
        answer = take_pieces(test)
        print(answer)

        if answer not in (1, 2, 3, 4, 5, 6, 7):
            print("Funksjonen returnerte en ugyldig verdi: {:}".format(answer))

        if answer != correct_answer and correct_answer is not None:
            print(
                "Koden feilet for følgende antall fyrstikker: {:}".format(test)
            )
