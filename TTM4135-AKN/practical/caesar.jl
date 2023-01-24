ALPHABETH = collect.("ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-")

if length(ARGS) < 2
    error("Missing arguments: [FILE] [KEY]")
end

file = readline(ARGS[1])
decrypt = length(ARGS) > 2 ? true : false
key = decrypt ? length(ALPHABETH) - parse(Int, ARGS[2]) : parse(Int, ARGS[2])

for i in eachindex(file)
    print(ALPHABETH[mod(indexin(file[i], ALPHABETH)[1] + key, 1:length(ALPHABETH))])
end
println()
