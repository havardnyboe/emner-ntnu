# !/usr/bin/python3
# coding=utf-8


class Queue:
    def __init__(self, max_size):
        # Initialiser de underliggende datastrukturene her
        pass

    def enqueue(self, value):
        # Skriv kode for Enqueue operasjonen
        pass

    def dequeue(self):
        # Skriv kode for Dequeue operasjonen
        pass


def tester(values, sequence, max_size):
    """
    Tester en oppgitt sekvens av operasjoner og sjekker at verdiene
    (values) kommer ut i riktig rekkefølge.
    """
    index = 0
    queue = Queue(max_size)
    output = []
    for action in sequence:
        if action == "enqueue":
            queue.enqueue(values[index])
            index += 1
        elif action == "dequeue":
            output.append(queue.dequeue())

    if output != values:
        print(
            "Feilet for følgende sekvens av operasjoner "
            + "'{:}' med verdiene ".format(", ".join(sequence))
            + "'{:}' og maksimal størrelse".format(", ".join(map(str, values)))
            + "'{:}'".format(max_size)
        )
        return True
    return False

def test_multiple_queues(values, sequences, number_of_queues, max_size):
    queues = [Queue(max_size) for _ in range(number_of_queues)]
    outputs = [[] for _ in range(number_of_queues)]
    indexes = [0] * number_of_queues

    for i in range(len(sequences[0])):
        for j in range(number_of_queues):
            if sequences[j][i] == "enqueue":
                queues[j].enqueue(values[j][indexes[j]])
                indexes[j] += 1
            elif sequences[j][i] == "dequeue":
                outputs[j].append(queues[j].dequeue())

    failed_flag = False
    feedback = f"Koden feilet når den ble kjørt med {number_of_queues} køer samtidig:"
    for queue_number, (input, output) in enumerate(zip(values, outputs)):
        if input != output:
            failed_flag = True
            feedback += (
                f"\nKø {queue_number + 1} ga feil svar for følgende sekvens av "
                f"operasjoner '{', '.join(sequences[queue_number])}' med verdiene "
                f"'{', '.join(map(str, values[queue_number]))}' og maksimal størrelse '{max_size}'"
            )
        else:
            feedback += (
                f"\nKø {queue_number + 1} ga riktig svar for følgende sekvens av "
                f"operasjoner '{', '.join(sequences[queue_number])}' med verdiene "
                f"'{', '.join(map(str, values[queue_number]))}' og maksimal størrelse '{max_size}'"
            )
    if failed_flag:
        print(feedback)
    return failed_flag

tests = (
    (
        [1, 7, 3],
        ("enqueue", "dequeue", "enqueue", "dequeue", "enqueue", "dequeue"),
        3,
    ),
    (
        [1, 7, 3],
        ("enqueue", "dequeue", "enqueue", "dequeue", "enqueue", "dequeue"),
        1,
    ),
    (
        [-1, 12, 0, 99],
        (
            "enqueue",
            "enqueue",
            "dequeue",
            "dequeue",
            "enqueue",
            "enqueue",
            "dequeue",
            "dequeue",
        ),
        2,
    ),
    (
        [-1, 12, 0, 99],
        (
            "enqueue",
            "enqueue",
            "dequeue",
            "enqueue",
            "dequeue",
            "enqueue",
            "dequeue",
            "dequeue",
        ),
        2,
    ),
    (
        [-1, 12, 0, 99],
        (
            "enqueue",
            "enqueue",
            "enqueue",
            "enqueue",
            "dequeue",
            "dequeue",
            "dequeue",
            "dequeue",
        ),
        4,
    ),
)

multiple_queues_tests = (
    (
        [
            [-525, -593, -224, -965, 321, 910, -203, -667],
            [-876, -867, 170, -422, 229, 508, 247, 619],
            [666, 147, -59, -160, 426, -895, 248, -730]
        ],
        [
            (
                'enqueue',
                'enqueue',
                'enqueue',
                'enqueue',
                'enqueue',
                'dequeue',
                'dequeue',
                'enqueue',
                'enqueue',
                'enqueue',
                'dequeue',
                'dequeue',
                'dequeue',
                'dequeue',
                'dequeue',
                'dequeue'
            ),
            (
                'enqueue',
                'dequeue',
                'enqueue',
                'enqueue',
                'dequeue',
                'dequeue',
                'enqueue',
                'dequeue',
                'enqueue',
                'dequeue',
                'enqueue',
                'dequeue',
                'enqueue',
                'enqueue',
                'dequeue',
                'dequeue'
            ),
            (
                'enqueue',
                'enqueue',
                'enqueue',
                'dequeue',
                'enqueue',
                'dequeue',
                'dequeue',
                'dequeue',
                'enqueue',
                'enqueue',
                'enqueue',
                'dequeue',
                'enqueue',
                'dequeue',
                'dequeue',
                'dequeue'
            )
        ],
        3,
        7,
    ),
)

failed = False

for values, sequence, max_size in tests:
    failed |= tester(values, sequence, max_size)

for values, sequences, number_of_queues, max_size in multiple_queues_tests:
    failed |= test_multiple_queues(values, sequences, number_of_queues, max_size)

if not failed:
    print("Koden din fungerte for alle eksempeltestene.")
