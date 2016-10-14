let rec factorial n =
    match n with
    | 0 -> 1
    | _ -> n * factorial (n - 1)

let rec printFact n  =
    match n with 
    | 0 -> printfn "0! = 1"
    | _ -> printfn "%d! = %d"  n (factorial (n))
           
printFact(5)

