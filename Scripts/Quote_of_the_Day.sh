init=$(curl -v  -i -X GET http://quotes.rest/qod.json?category=inspire -o "quote.txt")
quote=$(grep -R "quote" "quote.txt")
echo $quote