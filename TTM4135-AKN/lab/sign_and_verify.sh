time gpg -u "Håvard RSA" --output beemove-short.RSA.sig --detach-sign beemove-short.txt
time gpg --verify beemove-short.RSA.sig beemove-short.txt
time gpg -u "Håvard DSA" --output beemove-short.DSA.sig --detach-sign beemove-short.txt
time gpg --verify beemove-short.DSA.sig beemove-short.txt
time gpg -u "Håvard RSA" --output bible.RSA.sig --detach-sign bible.epub
time gpg --verify bible.RSA.sig bible.epub
time gpg -u "Håvard DSA" --output bible.DSA.sig --detach-sign bible.epub
time gpg --verify bible.DSA.sig bible.epub