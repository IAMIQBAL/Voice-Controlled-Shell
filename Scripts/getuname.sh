uname=$1
base='https://web.facebook.com'
status=$(curl -X GET -I -s -l "$base/$uname" | grep -w "HTTP" | cut -d " " -f2 | tail -n 1)
if (( status == 200 ));
then
    echo "User already exists"
else
    echo "User not found"
fi