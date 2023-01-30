using StatsBase

function frequency_analysis(msg, block::Int)
    block -= 1
    arr = []
    for i in 1:length(msg)-(block)
        push!(arr, msg[i:i+block])
    end
    countmap(arr)
end