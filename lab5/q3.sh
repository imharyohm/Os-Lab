#3. WASS to check whether a number is a perfect number or not.

echo -n "Enter a number: "
read number

sum=0

for (( i=1; i<$number; i++ ))
do
  if [ $(( $number % $i )) -eq 0 ]; then
  sum=$(( $sum + $i ))
  fi
done

case "$sum" in "$number") 
echo "$number is a perfect number." 
;;
*) 
echo "$number is not a perfect number." 
;;
esac