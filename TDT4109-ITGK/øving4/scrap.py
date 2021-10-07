# create a function that returns the greatest common divisor of two numbers using euclid's algorithm

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

# create a function that reduces a fraction to its lowest terms using the gcd function


def reduce(a, b):
    divisor = gcd(a, b)
    return a // divisor, b // divisor

# create a function that returns true if a is divisible by b and false otherwise


def divisible(a, b):
    if a % b == 0:
        return True
    else:
        return False

# Lag funksjonen isPrime som tar inn et tall a. Funksjonen skal ha en for-løkke som itererer fra b = 2,3,...,a-1 og bruke funksjonen fra forrige oppgave for å sjekke om a er delelig med b. Om de er delelige avslutter du og returnerer False. Ellers skal du returnere True.


def isPrime(a):
    for i in range(2, a):
        if divisible(a, i):
            return False
    return True
