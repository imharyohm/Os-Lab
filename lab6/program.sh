i=0
while [ $i -lt 5 ]
do
read a[$i]
echo ${a[$i]}
i=`expr $i + 1`
done