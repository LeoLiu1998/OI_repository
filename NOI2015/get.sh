for i in {1..30}:
do
	echo $i>data.in
	./dinner_b<data.in >>data.out
	echo $i
done
