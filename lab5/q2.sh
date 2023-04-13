# Wss to check the input is palindrome or not
echo Enter the value:
read value
rev=0
temp=$value
while [ $value -ne 0 ]
do
  rem=$(($value%10))
  rev=$((($rev*10)+$rem))
  value=$(($value/10))
done
if [ $temp -eq $rev ]
then
echo this is palindrome
else
echo this is not palindrome
fi