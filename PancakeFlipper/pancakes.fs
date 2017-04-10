open System

let rec flip k lst =
  match (k, lst) with
  | 0, lst      -> lst
  | _, ('+'::t) -> '-' :: (flip (k-1) t)
  | _, ('-'::t) -> '+' :: (flip (k-1) t)

let flips k lst =
  let rec flips_aux k lst acc len =
    match lst with
    | []        -> acc
    | ('+'::t)  -> flips_aux k t acc (len - 1)
    | ('-'::t)  -> if k > len then -1 else flips_aux k (flip (k-1) t) (acc + 1) (len - 1)
  flips_aux k lst 0 (Seq.length lst)

[<EntryPoint>]
let main _ =
  for i in 1..(Console.ReadLine() |> int) do
    let (lst, k) = Console.ReadLine() |> (fun x -> x.Split ' ') |> (fun x -> (List.ofSeq x.[0], int x.[1]))
    match flips k lst with
    | -1  -> printfn "Case #%d: IMPOSSIBLE" i
    | ans -> printfn "Case #%d: %d" i ans
  0
