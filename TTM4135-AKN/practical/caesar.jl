function caesar(file, key, decrypt)
    alphabeth = collect.("ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-")
    key = decrypt ? length(alphabeth) - key : key
    out = ""
    
    for i in eachindex(file)
        out *= alphabeth[mod(indexin(file[i], alphabeth)[1] + key, 1:length(alphabeth))]
    end
    out
end