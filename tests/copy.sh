c=76

while [ $c -le 150 ]
do
	cp valid test$c
	let "c++"
done
