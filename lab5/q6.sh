echo Enter any number:
read num
sum=0
while [ $num -ne 0 ]
do
    rem=$(($num%10))
    sum=$(($sum+$rem))
    num=$(($num/10))
done
echo The sum of digits is $sum.