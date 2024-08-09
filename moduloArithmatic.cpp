// Modulo Arithimatic 

// n - [n/m]*m == n%m == rem

// (neg + m)%m

// mod have lower precedence than the add and subtract

// You may also sometimes see the notation expr1≡expr2(modm)
// . This is read as "expr1
//  is congruent to expr2
//  modulo m
// ", and is shorthand for expr1 mod m=expr2 mod m
// .

// (a mod m)+(b mod m)  mod m=a+b  mod m
// (a mod m)−(b mod m)  mod m=a−b  mod m
// (a mod m)⋅(b mod m)  mod m=a⋅b  mod m

// modulo multiplicative inverse 
/*
    mmi of a is a^-1
    (a*mmia)%mod = 1

    when m is a prime
    a^mMODm = aMODm
    a^m-1MODm = 1
    1 = a*a^m-2%MOD
    1/a = a^m-2%MOD
*/

// modulo exponentiation
/*
    pow_mod(a,b,m){
        int r = 1;
        while(b){
            if(b&1) r = (r*a)%MOD;
            b/=2;
            a = (a*a)%MOD;
        }
        return r;
    }
*/