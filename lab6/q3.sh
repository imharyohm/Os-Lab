echo "Enter array size:"
read n
echo "Enter array elements:"
for ((i=0; $i<$n; i++))
do
    read arr[$i]
done
j=`expr $n - 1`
for ((i=0; $i<$j; i++))
do
    temp=${arr[$i]}
    arr[$i]=${arr[$j]}
    arr[$j]=$temp
    j=`expr $j - 1` 
done

echo "The reversed array is"
for ((i=0; $i<$n; i++))
do
echo ${arr[$i]}
done