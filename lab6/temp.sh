#wass to reverse the array elements
i=0
echo "Enter the element of array:"
while [ $i -lt 5 ]
do
read a[$i]
# echo ${a[$i]}
i=`expr $i + 1`
done
num=0
for((i=0,j=4;$i<$j;i++,j--))
do
$num=${a[$i]}
a[$i]=${a[$j]}
a[$j]=$num
done


echo "The reversed array is"
for ((i=0; $i<5; i++))
do
echo ${a[$i]}
done
