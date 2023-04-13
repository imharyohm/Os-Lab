arr1=(10 20 30 40 50)
arr2=(30 40 50 60 70)

union=()
intersection=()

i=0
while [ $i -lt ${#arr1[@]} ]
do
  j=0
  while [ $j -lt ${#arr2[@]} ]
  do
    if [ ${arr1[$i]} -eq ${arr2[$j]} ]
    then 
      intersection+=(${arr1[$i]})
      break
    fi
    j=$((j+1))
  done
  union+=(${arr1[$i]})
  i=$((i+1))
done
j=0
while [ $j -lt ${#arr2[@]} ]
do
  i=0
  while [ $i -lt ${#union[@]} ]
  do
    if [ ${arr2[$j]} -eq ${union[$i]} ]
    then
      break
    fi
    i=$((i+1))
  done
  if [ $i -eq ${#union[@]} ]
  then
    union+=(${arr2[$j]})
  fi
  j=$((j+1))
done

echo "Union: ${union[@]}"
echo "Intersection: ${intersection[@]}"