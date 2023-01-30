alphabeth = collect.("ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-")
function caesar(cipher, key, decrypt)
    key = decrypt ? length(alphabeth) - key : key
    out = ""
    
    for i in eachindex(cipher)
        out *= alphabeth[mod(indexin(cipher[i], alphabeth)[1] + key, 1:length(alphabeth))]
    end
    out
end