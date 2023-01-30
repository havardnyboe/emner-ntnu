include("caesar.jl")

function vigenere(cipher)
    for i in 1:5
        for j in i:5:length(cipher)
            print(cipher[j])
        end
        println("\n")
    end
end