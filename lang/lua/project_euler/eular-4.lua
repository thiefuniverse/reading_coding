-- Largest palindrome product
-- Problem 4
-- A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
-- Find the largest palindrome made from the product of two 3-digit numbers.


function isPlainDrome(x)
   return tostring(x) == string.reverse(x)
end

maxNum=0
for i=100,999 do
   for j=100,999 do
      tempMax=i*j
      if isPlainDrome(tempMax) then
	 if tempMax>maxNum then
	    maxNum=tempMax
	 end
      end
   end
end
print(maxNum)
