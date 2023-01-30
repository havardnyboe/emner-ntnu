include("caesar.jl")
include("vigenere.jl")
include("frequency.jl")

println("--------------------
Choose an analysis:
1) Caesar
2) Frequency analysis
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
    println("Which file do you want to read?")
    file = readline(readline())
    println("How many sets of characters do you want to analyse?")
    num = parse(Int, readline())
    ans = frequency_analysis(file, num)
    println("Showing the 10 most common $(num)-grams:")
    for i in 1:10
        max = findmax(ans)
        println("$(max[2])\t$(max[1])")
        pop!(ans, max[2])
    end
elseif case == "3"
    println("Which file do you want to read?")
    file = readline(readline())
    println(vigenere(file))
elseif case == "4"
    
end