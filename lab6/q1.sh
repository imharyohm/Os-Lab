#wass smallest and greatest no. in the given array
i=0
echo "Enter the element of array:"
while [ $i -lt 5 ]
do
read a[$i]
# echo ${a[$i]}
i=`expr $i + 1`
done


max=${a[0]}
min=${a[0]}

for((i=0;i<5;i++))
do
if [ $max -lt ${a[$i]} ]
then 
max=${a[$i]}
elif [ $min -gt ${a[$i]} ]
then
min=${a[$i]}
fi
done

echo "The greated value is:"$max
echo "The smallest value is:"$min