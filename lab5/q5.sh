echo -n "Enter the lower limit of the range: "
read lower

echo -n "Enter the upper limit of the range: "
read upper

echo "Prime numbers between $lower and $upper: "

for (( i=$lower; i<=$upper; i++ ))
do
  is_prime=true

  if [ $i -eq 1 ]; then
    is_prime=false
  fi

  for (( j=2; j<$i;j++))
  do
    if [ $(( $i % $j )) -eq 0 ]; then
      is_prime=false
      break
    fi
  done

  case $is_prime in
    true) 
    echo $i 
    ;;
    esac
    done