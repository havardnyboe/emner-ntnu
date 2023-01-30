include("caesar.jl")

function vigenere(cipher, period)
    arr = []
    for _ in 1:period
        push!(arr, "")
    end
    for i in 1:period
        for j in i:period:length(cipher)
            arr[i] *= cipher[j]
        end
    end
    return arr
end