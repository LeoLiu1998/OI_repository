export CXX="clang++"
export CXXFLAGS="-Wall -Wextra -g3 -DYGHDEBUG"
name=1269
bname=1269_b
gen_name=1269_gen.py
make $name 
make $bname
for i in {1..1000}:
do
	python $gen_name>$name.in
	./$name < $name.in>$name.out
	./$bname<$name.in>$name.ans
	if(diff -Bb $name.out $name.ans)
	then
	echo $i AC
	else 
		echo ! $i
		exit
	fi
done
