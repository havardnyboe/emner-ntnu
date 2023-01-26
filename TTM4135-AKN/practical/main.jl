include("caesar.jl")

println("--------------------
Choose an analysis:
1) Caesar
2) Substitution
3) Vigenère
4) Hill cipher
--------------------")
case = readline()

if case == "1"
    println("Which file do you want to read?")
    file = readline(readline())
    println("How many shifts do you want to use?")
    key = parse(Int, readline())
    println("Do you want to decrypt the file? (Y/N)")
    dec = lowercase(readline()) == "y" ? true : false
    println(caesar(file, key, dec))
elseif case == "2"

elseif case == "3"

elseif case == "4"
    
end