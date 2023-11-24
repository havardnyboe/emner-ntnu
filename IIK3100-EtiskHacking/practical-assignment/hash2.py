import hashlib
from itertools import product
from string import ascii_lowercase, ascii_uppercase

to_be_cracked = "49c6a1526a77b34a64e2feaa7dffccd1"  # the hash to be cracked
# read the rockyou password list
passwd_list = open("rockyou.txt", "r", encoding="latin-1").readlines()


def hash(password: str) -> str:
    passwd = password.encode('utf-8')  # encode to utf-8
    hexa = passwd.hex().upper()  # convert to hexadecimal and uppercase
    # hash the hexadecimal
    hashed = hashlib.md5(hexa.encode('utf-8')).hexdigest()
    return hashed


def crack(h: str) -> str:
    for passwd in passwd_list:  # iterate over the passwords
        passwd = passwd.strip()  # remove whitespaces
        if hash(passwd) == h:  # compare the hashes
            return passwd  # return the password


print(crack(to_be_cracked))  # print the cracked password
