echo "Enter array size:"
read n
echo "Enter array elements:"
for ((i=0; $i<$n; i++))
do
    read arr[$i]
done
sum=0
for ((i=0; $i<$n; i++))
do
    sum=`expr $sum + ${arr[$i]}`
done
echo "The sum of elements is $sum"