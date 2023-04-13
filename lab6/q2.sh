#wass to count individual the number of occurance
i=0
echo "Enter the element of array:"
while [ $i -lt 5 ]
do
read a[$i]
# echo ${a[$i]}
i=`expr $i + 1`
done

echo "Enter the search element:"
read num
count=0
for((i=0;i<5;i++))
do
if [ $num -eq ${a[i]} ]
then
count=`expr $count + 1`
fi
done

echo "Occurance of the nuumber is:"$count
