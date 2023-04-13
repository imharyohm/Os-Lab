# wss to check the input vlaue is charcter ,interger or special value
echo "enter any value:"
read value
case ${value} in
[a-z]) echo It is charcter
;;
[A-Z]) echo It is charcter
;;
[0-9]) echo It is interger
;;
*) echo It is special charcter
;;
esac