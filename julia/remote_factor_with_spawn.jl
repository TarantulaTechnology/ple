addprocs(3)
using Primes
ref = @spawn Primes.factor(21883298135690819)
factors = fetch(ref)
@assert factors == Dict(234711901=>1,93234719=>1)
