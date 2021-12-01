def list_str(s):
    liste = []
    for i in range(len(s)):
        if i+4 < len(s) and i-3 >= 0:
            if s[i+4] == 'd' and s[i-3] == 'd':
                liste.append(s[i])
    return liste

print(list_str('abcdefX'))
print(list_str('fedcabYabcdef'))
print(list_str('xyzzy'))
print(list_str('abcdefSabcdefOabcdefSabcdef'))
print(list_str('abcdef*abcdef'))
print(list_str('abcdefPabcdefYabcdef'))