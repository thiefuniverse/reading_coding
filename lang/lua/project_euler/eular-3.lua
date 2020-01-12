-- Largest prime factor
-- Problem 3
-- The prime factors of 13195 are 5, 7, 13 and 29.
--   What is the largest prime factor of the number 600851475143 ?

target=600851475143

function isPrime(x)
   for m=2,x-1 do
      if x%m ==0 then
	 return false
      end
   end
   return true
end

function primes(x)
   flag=0
   tempX=x
   for i=2,x-1 do
      if isPrime(i) then
	 if tempX%i ==0 then
	    tempX=tempX/i
	    return i,primes(tempX)
	 end
      end
   end
   return x
end

print(primes(target))

